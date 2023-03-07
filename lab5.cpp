#include <iostream>
using namespace std;

int s_recursive(int n);
void test_s_ver_1();

int s_loop_n(int n);
void test_s_ver_2();

void multiply(int F[][2], int M[][2]);
void power(int F[][2], int n);

int s_matrix(int n);
void test_s_ver_3();

int main()
{
    test_s_ver_1();
    test_s_ver_2();
    test_s_ver_3();

    return 0;
}

int s_recursive(int n)
{
    if (n <= 1) {
        return n;
    } else {
        return s_recursive(n-1) + s_recursive(n-2);
    }
}

void test_s_ver_1() {
    for (int n = 0; n < 15; n++) {
        cout << "s(" << n << ") = " << s_recursive(n) << endl;
    }
}

int s_loop_n(int n) {
    if (n < 0) {
        return -1;
    }
    if (n == 0 || n == 1) {
        return n;
    }
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

void test_s_ver_2()
{
    for (int n = 0; n < 15; n++) {
        cout << "s(" << n << ") = " << s_loop_n(n) << endl;
    }
}

//---------------------------------task 3-----------------------------------
void multiply(int F[][2], int M[][2]) {
   int a = F[0][0] * M[0][0] + F[0][1] * M[1][0];
   int b= F[0][0] * M[0][1] + F[0][1] * M[1][1];
   int c = F[1][0] * M[0][0] + F[1][1] * M[1][0];
   int d = F[1][0] * M[0][1] + F[1][1] * M[1][1];
   F[0][0] = a;
   F[0][1] = b;
   F[1][0] = c;
   F[1][1] = d;
}
void power(int F[][2], int n) {
    if (n == 0 || n == 1)
        return;
    int M[2][2] = {{1,1},{1,0}};
    while (n > 1) {
        if (n % 2 != 0)
            multiply(F, M);
        multiply(M, M);
        n /= 2;
    }
    multiply(F, M);
}


int s_matrix(int n){
   int F[2][2] = {{1,1},{1,0}};
   if (n == 0)
      return 0;
   power(F, n - 1);
   return F[1][0];
}
void test_s_ver_3() {
    for (int n = 0; n < 15; n++) {
        cout << "s(" << n << ") = " << s_matrix(n) << endl;
    }
}

