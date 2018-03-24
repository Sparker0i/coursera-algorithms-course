#include <iostream>
#define ll long long
using namespace std;

ll fibonacci(ll n , ll m)
{
    if (n <= 1)
        return n;

    ll beforePrevious  = 0, previous = 1, a = -1, b = -1;

    for (ll i = 2; i <= n; i++) {
        b = (beforePrevious + previous) % m;

        if (a == 0 && b == 1) 
        {
            ll period = (i + 1) - 2;
            ll res = n % period;
            return fibonacci(res , m);
        }
        else 
        {
            a = b;
            beforePrevious = previous;
            previous = b;
        }
    }

    return b;
}

int main()
{
    ll N , M;
    cin >> N >> M;
    cout << fibonacci(N , M) << endl;
}