#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int getMax(vector<int> w , vector<int> value) 
{
  int max = 0;
  double v = 0;
  for (int i = 0; i < w.size(); ++i)
  {
    if (w[i] > 0 && max(v , value[i]/w[i]) == value[i]/w[i])
    {
      max = i;
      v = value[i]/w[i];
    }
  }
  return max;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  
  // write your code here
  vector<int> A(weights.size() , 0);

  int n = weights.size();
  for (int i = 0; i < n; ++i)
  {
    if (capacity == 0)
      return value;
    int j = getMax(weights , values);
    int a = min(weights[j] , capacity);
    value += a * (float(values[j]) / weights[j]);
    weights[j] -= a;
    A[j] += a;
    capacity -= a;
  }

  return value;
}

int main() {
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout.precision(4);
  cout << optimal_value << endl;
  return 0;
}
