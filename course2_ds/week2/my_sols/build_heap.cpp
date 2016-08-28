#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;
using namespace std;

#define left_child(x)   ((2 * x) + 1)
#define right_child(x)  ((2 * x) + 2)

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void sift_down(int i) {
     int min_ele = data_[i];;
     int min_index = i;

     if (left_child(i) >= data_.size()) {
        return;
     } else if (min_ele > data_[left_child(i)]){
        min_ele = data_[left_child(i)];
        min_index = left_child(i);
     }
     if (right_child(i) < data_.size() && min_ele > data_[right_child(i)]) {
        min_ele = data_[right_child(i)];
        min_index = right_child(i);
     }
     if (min_ele != data_[i]) {
        // We need a swap
        swap(data_[i], data_[min_index]);
        swaps_.push_back(make_pair(i, min_index));
        sift_down(min_index);
     }
  }

  void GenerateSwaps() {
    swaps_.clear();
    for (int i = (data_.size()/2) - 1; i >= 0; i--) {
       sift_down(i);
//       cout << "i: " << i ;
//       min_ele = data_[i];
//       cout << "min_ele: " << min_ele;
//       min_index = i;
//       cout << "min_index: " << min_index;
//       if (min_ele > data_[left_child(i)]) {
//          min_ele = data_[left_child(i)];
//          min_index = left_child(i);
//       }
//       if (min_ele > data_[right_child(i)]) {
//          min_ele = data_[right_child(i)];
//          min_index = right_child(i);
//       }
//
//       cout << "min_index: " << min_index;
//       if (min_ele != data_[i]) {
//         // We need a swap
//         swap(data_[i], data_[min_index]);
//         swaps_.push_back(make_pair(i, min_index));
    }
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
