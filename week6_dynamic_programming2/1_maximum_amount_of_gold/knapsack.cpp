#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;

bool greater(int a , int b)
{
    return a > b;
}

int optimal_weight(int W, vector<int> &w) 
{
    vector<vector<int> >K(w.size() , vector<int>(W + 1 , 0));
    K.at(0).at(0) = 0;

    for (int i = 1; i < K.at(0).size(); ++i)
    {
        if (w[0] <= i)
            K.at(0).at(i) = w[i];
        else
            K.at(0).at(i) = 0;
    }

    for (int i = 1; i < K.size(); ++i)
    {
        for (int j = 1; j < K.at(i).size(); ++j)
        {
            if (w[i] > j)
                K.at(i).at(j) = K.at(i - 1).at(j);
            else
                K.at(i).at(j) = std::max(K.at(i - 1).at(j) , w[i] + K.at(i - 1).at(j - w[i]));
        }
    }
    return K.at(w.size() - 1).at(W);
}

int main() 
{
    int n, W;
    std::cin >> W >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) 
    {
        std::cin >> w[i];
    }
    std::sort(w.begin() , w.end() , greater);
    std::cout << optimal_weight(W, w) << '\n';
}
