#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using std::vector;

int partition3(vector<int> &A) {
    //write your code here
    int sum = std::accumulate(A.begin() , A.end() , 0);
    if (A.size() < 3 || !(sum % 3))
        return 0;
    
    int part = std::floor(sum / 3);
    vector<vector<int> > table (A.size() + 1 , vector<int>(part + 1 , 0));

    for (int i = 1; i <= part; ++i)
    {
        for (int j = 1; j <= A.size(); ++j)
        {
            int k = i - A.at(j - 1);
            if (A.at(j - 1) == i || (k > 0 && table.at(k).at(j - 1) > 0))
                if (table.at(i).at(j - 1) == 0)
                    table.at(i).at(j) = 1;
                else
                    table.at(i).at(j) = 2;
            else
                table.at(i).at(j) = table.at(i).at(j - 1);
        }
    }

    if (table.at(part).at(A.size()) == 2)
        return true;
    else return false;
}

int main() 
{
    int n;
    std::cin >> n;
    vector<int> A(n);
    for (size_t i = 0; i < A.size(); ++i) {
        std::cin >> A[i];
    }
    std::cout << partition3(A) << '\n';
}
