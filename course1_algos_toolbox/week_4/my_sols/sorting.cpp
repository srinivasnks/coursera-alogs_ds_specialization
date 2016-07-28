#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <map>

using std::vector;
using std::swap;
using namespace std;

uint64_t partition2(vector<uint64_t> &a, uint64_t l, uint64_t r) {
  uint64_t x = a[l];
  uint64_t j = l;
  for (uint64_t i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

std::pair<uint64_t, uint64_t> partition3(vector<uint64_t> &a, uint64_t l, uint64_t r) {
   uint64_t pivot = a[l];
   uint64_t i, j, k;

   j = k = l;
   for (i = l + 1; i <= r; i++) {
      if (a[i] < pivot) {
         if (j < k) {
            j += 1;
            swap(a[i], a[j]);
            k += 1;
            swap(a[i], a[k]);
         } else {
            j += 1;
            swap(a[i], a[j]);
         }
      } else if (a[i] == pivot) {
         if (k <= j) {
            k = j + 1;
         } else {
            k += 1;
         }
         swap(a[i], a[k]);
      }
   }
   swap(a[j], a[l]);

   return (std::pair<uint64_t, uint64_t>(j, k));
}

void randomized_quick_sort(vector<uint64_t> &a, uint64_t l, uint64_t r) {
   if (l >= r) {
      return;
   }
   int sorted = 1;
   std::map<uint64_t, uint64_t> my_map;
   uint64_t k;
   vector<uint64_t>::iterator iter1 = a.begin() + l;
   vector<uint64_t>::iterator iter2 = a.begin() + r + 1;


   for (int i = l; i < r; i++) {
      if (a[i] > a[i + 1])
         sorted = 0;
   }
   if (sorted)
      return;

   k = l + ((r - l)/2);
   swap(a[l], a[k]);

      auto m = partition2(a, l, r);
      if (m > 0) {
         randomized_quick_sort(a, l, m - 1);
      }
      randomized_quick_sort(a, m + 1, r);
/*   } else {
      auto m = partition3(a, l, r);

      if (m.first > 0) {
         randomized_quick_sort(a, l, m.first - 1);
      }
      randomized_quick_sort(a, m.second + 1, r);
   }
   */
}

int main() {
  uint64_t n;
  std::cin >> n;
  vector<uint64_t> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);

  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
