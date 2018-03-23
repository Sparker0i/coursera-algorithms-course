#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <iomanip>
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

using std::vector;
using std::cout;
using std::cin;
using std::endl;

class Item
{
  public:
  int value , weight;
  Item(int v, int w)
  {
    value = v;
    weight = w;
  }

  Item() {}
};

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

bool cmp(struct Item a , struct Item b)
{
  return (double)a.value / a.weight > (double)b.value / b.weight;
}

double get_optimal_value(int capacity, vector<Item> items) {
  double value = 0.0;
  int weight = 0;
  
  // write your code here
  std::sort(items.begin() , items.end() , cmp);

  for (int i = 0; i < items.size(); ++i)
  {
    if (weight + items[i].weight <= capacity)
    {
      weight += items[i].weight;
      value += items[i].value;
    }
    else
    {
      int r = capacity - weight;
      value += items[i].value * ((float) r) / items[i].weight;
      break;
    }
  }

  return value;
}

int main() {
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<Item> items;
  items.resize(n);
  for (int i = 0; i < n; i++) {
    int v , w;
    cin >> v >> w;
    items[i] = Item(v , w);
  }

  double optimal_value = get_optimal_value(capacity, items);

  cout << std::fixed;
  cout << std::setprecision(4);
  cout << optimal_value << endl;
  return 0;
}
