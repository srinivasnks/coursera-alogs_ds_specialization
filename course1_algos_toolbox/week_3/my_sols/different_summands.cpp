#include <iostream>
#include <vector>
#include <map>

using std::vector;

vector<uint64_t> optimal_summands(uint64_t n) {
   vector<uint64_t> summands;
   uint64_t remainder, next_entry;

   if (n <= 2) {
      summands.push_back(n);
      return summands;
   }

   remainder = n;
   next_entry = 1;
   while (remainder != 0) {
      remainder -= next_entry;
      if (remainder == 0) {
         summands.push_back(next_entry);
         break;
      } else if (remainder > next_entry) {
         // This entry can be added to the summands list.
         summands.push_back(next_entry);
      } else {
         remainder += next_entry;
      }
      next_entry += 1;
   }
   return summands;
}

int main() {
   uint64_t n;
   std::cin >> n;
   vector<uint64_t> summands = optimal_summands(n);
   std::cout << summands.size() << '\n';
   for (size_t i = 0; i < summands.size(); ++i) {
     std::cout << summands[i] << ' ';
   }
}
