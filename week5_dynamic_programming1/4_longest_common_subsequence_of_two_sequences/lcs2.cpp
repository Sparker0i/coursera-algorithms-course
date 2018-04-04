#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>

using std::vector;
using std::string;

int lcs(string X, string Y)
{
    int m = X.size();
    int n = Y.size();

    vector<vector<int> >L(m + 1 , vector<int>(n + 1 , 0));
    int i, j;

    for (i=0; i<=m; i++)
    {
        for (j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;

            else
                L[i][j] = std::max(L[i-1][j], L[i][j-1]);
        }
    }

    return L[m][n];
}

int main()
{
    int m;
    std::cin >> m;

    vector<int> x(m);
    for (int i = 0; i < m; ++i)
    {
        std::cin >> x[i];
        // if (x[i] >= 10) 
        //     x[i] %= 10;
    }
    
    int n;
    std::cin >> n;

    vector<int> y(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> y[i];
        // if (y[i] >= 10) 
        //     y[i] %= 10;
    }
    
    std::stringstream X;
    std::copy(x.begin(), x.end(), std::ostream_iterator<int>(X, ""));

    std::stringstream Y;
    std::copy(y.begin(), y.end(), std::ostream_iterator<int>(Y, ""));

    std::cout << lcs(X.str().c_str() , Y.str().c_str()) << std::endl;

    return 0;
}