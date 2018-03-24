#include <iostream>
using namespace std;

int primer(int num)
{
    if (num % 10 < 10)
        return num % 10;
    return primer(num % 10);
}

int fibonacci(int n)
{
    int F[n + 1];
    F[0] = 0;
    F[1] = 1;
    for (int i = 2; i < n + 1; ++i)
    {
        F[i] = (F[i - 1] % 10) + (F[i - 2] % 10);
        F[i] = primer(F[i]);
    }
    return F[n];
}

int main()
{
    int N;
    cin >> N;
    cout << fibonacci(N) << endl;
}