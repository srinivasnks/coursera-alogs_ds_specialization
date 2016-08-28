#include <iostream>
#include <vector>

using std::vector;
using namespace std;

uint32_t optimal_weight(uint32_t W, const vector<uint32_t> &w) {
   vector<vector<uint32_t>> opt_weights;
   uint32_t i;
   opt_weights.resize((w.size() + 1), vector<uint32_t>(W + 1, 0));
   for (i = 0; i <= W; i++)
      opt_weights[0][i] = 0;
   for (i = 0; i <= w.size(); i++)
      opt_weights[i][0] = 0;

   for (uint32_t Wi = 1; Wi <= W; Wi++) {
      for (uint32_t wi = 1; wi <= w.size(); wi++) {
         uint32_t cur_weight = w[wi - 1];
         if (Wi >= cur_weight) {
            opt_weights[wi][Wi] = (opt_weights[wi - 1][Wi - cur_weight] + cur_weight) >= opt_weights[wi - 1][Wi] ? (opt_weights[wi - 1][Wi - cur_weight] + cur_weight) : opt_weights[wi - 1][Wi];
         } else {
            opt_weights[wi][Wi] = opt_weights[wi - 1][Wi];
         }
      }
   }

/*
   for (uint32_t wi = 0; wi <= w.size(); wi++) {
      for (uint32_t Wi = 0; Wi <= W; Wi++) {
         cout << opt_weights[wi][Wi] << " ";
      }
      cout << endl;
   }
*/

   return opt_weights[w.size()][W];
}

int main() {
   uint32_t n, W;
   std::cin >> W >> n;
   vector<uint32_t> w(n);
   for (uint32_t i = 0; i < n; i++) {
      std::cin >> w[i];
   }
   std::cout << optimal_weight(W, w) << '\n';
}
