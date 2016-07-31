#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;

bool seg_sort(std::pair<int64_t, int64_t> &a, std::pair<int64_t, int64_t> &b)
{
   if ((a.first < b.first) || ((a.first == b.first) && (a.second < b.second))) {
      return true;
   }

   return false;
}

vector<int64_t> fast_count_segments(vector<pair<int64_t, int64_t>> segments, vector<int64_t> points)
{
   vector<int64_t> cnt(points.size());
   uint32_t pointsCnt;

   // Sort the segments vector to arrange them in increasing order of start points
   // If start point is same, use the end point to sort
   std::sort(segments.begin(), segments.end(), seg_sort);

   // Once sorted, cycle through all points and see how many line segments it fits on.
   // The idea is that if a starting point of a segment is > point's coordinates, then
   // the loop to check all segments can break there.
   for (int i = 0; i < points.size(); i++) {
      pointsCnt = 0;
      for (auto &seg_iter : segments) {
         if (points[i] >= seg_iter.first) {
            if (points[i] <= seg_iter.second) {
               pointsCnt++;
            }
         } else {
            // Point coordinate is less than the start point of the current segment.
            // Break here since all other segments will have start point >= current
            // segment's start point.
            break;
         }
      }
      cnt[i] = pointsCnt;
   }
   return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points)
{
   vector<int> cnt(points.size());
   for (size_t i = 0; i < points.size(); i++) {
      for (size_t j = 0; j < starts.size(); j++) {
         cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
      }
   }
   return cnt;
}

int main()
{
   int n, m;
   std::cin >> n >> m;
   vector<std::pair<int64_t, int64_t>> segments(n);
   int64_t start, end;
   for (size_t i = 0; i < segments.size(); i++) {
      std::cin >> start >> end;
      std::pair<int64_t, int64_t> p(start, end);
      segments[i] = p;
   }
   vector<int64_t> points(m);
   for (size_t i = 0; i < points.size(); i++) {
      std::cin >> points[i];
   }
   //use fast_count_segments
   vector<int64_t> cnt = fast_count_segments(segments, points);
   for (size_t i = 0; i < cnt.size(); i++) {
      std::cout << cnt[i] << ' ';
   }
}
