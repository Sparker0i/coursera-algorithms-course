#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  int value = n;
  int k = 1;

  while (true)
  {
    if (value <= 2 * k)
    {
      summands.push_back(value);
      break;
    }
    else
    {
      summands.push_back(k);
      value -= k;
      k += 1;
    }
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
