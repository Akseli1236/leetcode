#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets) {
    int n = baskets.size();
    vector<int> tree(2 * n); // 1-based index

    // Build segment tree in O(n)
    for (int i = 0; i < n; ++i)
      tree[n + i] = baskets[i];
    for (int i = n - 1; i > 0; --i)
      tree[i] = min(tree[i << 1], tree[i << 1 | 1]);

    auto update = [&](int pos, int val) {
      pos += n;
      tree[pos] = val;
      for (pos >>= 1; pos > 0; pos >>= 1)
        tree[pos] = min(tree[pos << 1], tree[pos << 1 | 1]);
    };

    // Find first index with value >= val (left to right)
    function<int(int, int, int, int)> query = [&](int node, int l, int r,
                                                  int val) -> int {
      if (l == r)
        return (tree[node] >= val) ? l : -1;
      int mid = (l + r) / 2;
      int left = query(2 * node, l, mid, val);
        if (left != -1)
          return left;

        return query(2 * node + 1, mid + 1, r, val);
    };

    int placed = 0;
    for (int fruit : fruits) {
      int idx = query(1, 0, n - 1, fruit);
      if (idx != -1) {
        update(idx, 0);
        placed++;
      }
    }

    return fruits.size() - placed;
  }
};

int main() {

  Solution solution;

  vector<int> fruits = {4, 2, 5};
  vector<int> baskets = {3, 5, 4};

  int answer = solution.numOfUnplacedFruits(fruits, baskets);

  cout << answer << endl;

  return 0;
}
