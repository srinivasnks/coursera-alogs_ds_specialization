#include <iostream>
#include <vector>

using std::vector;
using namespace std;

uint64_t num_inversions;

vector<uint32_t> merge(vector<uint32_t> b, vector<uint32_t> c)
{
   vector<uint32_t> result;

   while (b.begin() != b.end() && c.begin() != c.end()) {
      if (b[0] <= c[0]) {
         result.push_back(b[0]);
         b.erase(b.begin());
      } else {
         result.push_back(c[0]);
         c.erase(c.begin());
         num_inversions += b.size();
      }
   }
   // Check if any one input vector has elements left while the other
   // input vector is empty
   if (b.size()) {
      for (auto iter : b)
         result.push_back(iter);
   } else {
      for (auto iter : c)
         result.push_back(iter);
   }

   return result;
}

vector<uint32_t> mergeSort(vector<uint32_t> &a, uint32_t l, uint32_t r)
{
   vector<uint32_t> ret;
   if (l == r) {
      ret.push_back(a[l]);
      return ret;
   }

   uint32_t next_r = (l + ((r - l) / 2));
   vector<uint32_t> b = mergeSort(a, l, next_r);
   vector<uint32_t> c = mergeSort(a, next_r + 1, r);

   return merge(b, c);
}

void get_number_of_inversions(vector<uint32_t> &a) {
   uint32_t r = a.size() - 1;
   mergeSort(a, 0, r);
}

int main() {
   int n;
   std::cin >> n;
   vector<uint32_t> a(n);
   for (size_t i = 0; i < n; i++) {
      std::cin >> a[i];
   }
   num_inversions = 0;
   get_number_of_inversions(a);
   std::cout << num_inversions << '\n';
}
