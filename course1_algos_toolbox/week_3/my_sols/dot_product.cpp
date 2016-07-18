#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;

bool my_sort(int a, int b)
{
  if (a > b)
    return true;
  else
    return false;	
}

long long min_dot_product(vector<int> a, vector<int> b) {
  // write your code here
  long long result = 0;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end(), my_sort);
  for (size_t i = 0; i < a.size(); i++) {
//    cout << " a * b " << a[i] << " " << b[i] << endl;
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << min_dot_product(a, b) << std::endl;
}
