#include <iostream>
#include <cassert>
#include <vector>

using std::vector;
using namespace std;

int binary_search(const vector<int> &a, int x, int li, int ri) {
  uint64_t mid_ele = (li + ((ri - li) / 2));

  if (x < a[li] || x > a[ri])
     return -1;

  if ((li >= ri) && a[ri] != x) {
    // Element does not exist in the list
    return -1;
  }
  if (a[mid_ele] == x) {
    // Found the element. Return index = mid_ele
    return mid_ele;
  } else if (a[mid_ele] > x) {
    // Search on the left side of mid_ele
    return binary_search(a, x, li, (mid_ele - 1));
  } else {
    // Search on the right side of mid_ele
    return binary_search(a, x, (mid_ele + 1), ri);
  }
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i], 0, (a.size() - 1)) << ' ';
  }
}
