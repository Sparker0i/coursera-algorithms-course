#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition(vector<int> &a, int l, int r , int &i, int &j) {
  i = l - 1;
  j = r;
  int p = l - 1 , q = r;
  int v = a[r];

  while (true)
  {
    while (a[++i] < v);

    while (v < a[--j])
    {
      if (j == l)
        break;
    }

    if (i >= j)
      break;

    std::swap(a[i] , a[j]);

    if (a[i] == v)
    {
      ++p;
      std::swap(a[p] , a[i]);
    }

    if (a[j] == v)
    {
      --q;
      std::swap(a[j] , a[q]);
    }
  }

  std::swap(a[i] , a[r]);

  j = i - 1;
  for (int k = l; k < p; ++k , --j)
    std::swap(a[k] , a[j]);

  i++;
  for (int k = r - 1; k > q; --k , ++i)
    std::swap(a[i] , a[k]);
}

void quick_sort(vector<int> &a, int l, int r) {
  if (l >= r)
    return;

  int i , j;
  partition(a , l , r , i , j);

  quick_sort(a, l, j);
  quick_sort(a, i, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
