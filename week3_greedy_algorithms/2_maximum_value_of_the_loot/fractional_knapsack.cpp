#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using std::vector;

vector<double> divide( const std::vector<int>& a, const std::vector<int>& b )
{
    std::vector<double> result ;

    const std::size_t n = std::min(a.size(), b.size()) ;
    std::transform( std::begin(a), std::begin(a)+n, std::begin(b),
                    std::back_inserter(result), std::divides<double>{} ) ;
    return result ;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  
  // write your code here
  double weight = 0.0;
  int i = 0;
  while (weight <= capacity && weights[i] <= capacity - weight)
  {
    weight += weights[i];
    value += values[i];
    ++i;
  }
  if (weight < capacity)
  {
    double x = capacity - weight;
    weight += x;
    value += ((x * values[i]) / weights[i]);
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
