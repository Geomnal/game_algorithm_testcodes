#include <iostream>
using namespace std;

int fibo(int n);

int main()
{
    int n = 5;
    int a = fibo(n);

    cout << "fibo (" << n << ") �� ����" << endl;
    cout << a << endl;

}

int fibo(int n) {

    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else
        return fibo(n - 1) + fibo(n - 2);


}