#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool cmp(string a , string b)
{
  string A , B;
  A = a.append(b);
  B = b.append(a);
  
  return A.compare(B) > 0 ? 1 : 0;
}

string largest_number(vector<string> a) {
  //write your code here
  std::sort(a.begin() , a.end() , cmp);
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
