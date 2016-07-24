#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using std::vector;

int get_majority_element(vector<int> &a) {
  std::map<int, uint64_t> count_map;
  std::map<int, uint64_t>::iterator it;

  for (int i = 0; i < a.size(); i++) {
    if ((it = count_map.find(a[i])) != count_map.end()) {
      // Element already exists in the map. Modify the value to value + 1
      it->second += 1;
    } else {
      // Element is to be newly instered into the map
     count_map.insert(std::pair<int, uint64_t>(a[i], 1));
    }
  }

  for (auto &iter : count_map) {
    if (iter.second > (a.size() / 2)) {
       return 1;
    }
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a) != -1) << '\n';
}
