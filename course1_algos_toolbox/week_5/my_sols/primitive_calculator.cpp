#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;

void make_sequence(uint32_t n, vector<pair<uint32_t, uint32_t>> &sequence)
{
   sequence[1] = std::make_pair(0, 1);
   for (int i = 2; i <= n; i++) {
      if (i % 3) {
         if (i % 2) {
            sequence[i] = std::make_pair((sequence[i - 1].first + 1), (i - 1));
         } else {
            if (sequence[i - 1].first < sequence[i / 2].first) {
               sequence[i] = std::make_pair((sequence[i - 1].first + 1), (i - 1));
            } else {
               sequence[i] = std::make_pair((sequence[i / 2].first + 1), (i / 2));
            }
         }
      } else {
         if (i % 2) {
            if (sequence[i - 1].first < sequence[i / 3].first) {
               sequence[i] = std::make_pair((sequence[i - 1].first + 1), (i - 1));
            } else {
               sequence[i] = std::make_pair((sequence[i / 3].first + 1), (i / 3));
            }
         } else {
            uint32_t min_val = min(min(sequence[i - 1].first, sequence[i / 2].first), sequence[i / 3].first);
            if (min_val == sequence[i - 1].first) {
               sequence[i] = std::make_pair((sequence[i - 1].first + 1), (i - 1));
            } else if (min_val == sequence[i / 2].first) {
               sequence[i] = std::make_pair((sequence[i / 2].first + 1), (i / 2)); 
            } else {
               sequence[i] = std::make_pair((sequence[i / 3].first + 1), (i / 3));
            }
         }
      }
   }

//   for (int i = 1; i <= n; i++) {
//      cout << i << ": " << sequence[i].first << " " << sequence[i].second << endl;
//   }
}

std::vector<uint32_t> optimal_sequence(uint32_t n)
{
   std::vector<pair<uint32_t, uint32_t>> sequence(n + 1);
   std::vector<uint32_t> opt_seq;
   uint32_t i = n;
   make_sequence(n, sequence);

   opt_seq.insert(opt_seq.begin(), i);
   while(sequence[i].first != 0) {
      opt_seq.insert(opt_seq.begin(), sequence[i].second);
      i = sequence[i].second;
   }
   return opt_seq;
}
int main()
{
   uint32_t n;
   std::cin >> n;
   auto result = optimal_sequence(n);
   std::cout << result.size() - 1 << std::endl;
   for (size_t i = 0; i < result.size(); ++i) {
      std::cout << result[i] << " ";
   }
//   cout << result << endl;
}
