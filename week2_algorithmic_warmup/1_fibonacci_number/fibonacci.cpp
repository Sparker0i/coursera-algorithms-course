#include <iostream>
using namespace std;

int fibonacci(int n)
{
    int F[n + 1];
    F[0] = 0;
    F[1] = 1;
    for (int i = 2; i < n + 1; ++i)
    {
        F[i] = F[i - 1] + F[i - 2];
    }
    return F[n];
}

int main()
{
    int N;
    cin >> N;
    cout << fibonacci(N) << endl;
}