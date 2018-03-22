#include <iostream>
#include <vector>

int get_change(int m) 
{
  int n = 0;
  //write your code here
  while (m != 0)
  {
    if (m >= 10 && m - 10 >= 0)
    {
      m -= 10;
      ++n;
    }
    else if (m >= 5 && m - 5 >= 0)
    {
      m -= 5;
      ++n;
    }
    else if (m >= 1 && m - 1 >= 0)
    {
      m -= 1;
      ++n;
    }
  }
  return n;
}

int main() 
{
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}