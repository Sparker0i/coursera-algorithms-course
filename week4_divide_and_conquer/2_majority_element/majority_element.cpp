#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using std::vector;

int get_majority_element(vector<int> &a, int left , int right) 
{
  std::vector<int> g;

  for (int i : a)
  {
    if (!g.empty() && g[g.size() - 1] != i)
      g.pop_back();
    
    else if (g.empty() || g[g.size() - 1] == i)
      g.push_back(i);
  }

  if (g.empty())
    return -1;

  int candidate = g[g.size() - 1];
  g.pop_back();
  int count = 0;

  for (int x : a)
  {
    if (x == candidate)
      count += 1;
  }
  if (count > a.size() / 2)
    return candidate;

  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) 
  {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0 , a.size()) != -1) << '\n';
}
