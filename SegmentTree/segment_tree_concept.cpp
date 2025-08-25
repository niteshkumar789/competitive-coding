#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class SegmentTree {
    private:
        vector<int> seg;
        int n;
        
        void BuildTree(int i, int low, int high, vector<int>& arr) {
            if (low == high) {
                seg[i] = arr[low];
                return;
            }
            
            // Recursion
            int mid = (low + high) / 2;
            BuildTree(2 * i + 1, low, mid, arr);
            BuildTree(2 * i + 2, mid + 1, high, arr);
            
            // operations
            seg[i] = max(seg[2 * i + 1], seg[2 * i + 2]);
        }
        
        void updateTree_utility(int index, int val, int i, int low, int high) {
            if (low == high) {
                seg[i] = val;
                return;
            }
            
            // recursion
            int mid = (low + high) / 2;
            if (index <= mid) {
                updateTree_utility(index, val, 2 * i + 1, low, mid);
            }
            else {
                updateTree_utility(index, val, 2 * i + 2, mid + 1, high);
            }
            
            // operations
            seg[i] = max(seg[2 * i + 1], seg[2 * i + 2]);
        }
        
        int rangeQuery_utility(int l, int r, int i, int low, int high) {
            // no overlap
            if (r < low || l > high) {
                return INT_MIN; // for max query
            }
            
            // complete overlap
            if (l <= low && r >= high) {
                return seg[i];
            }
            
            // partial overlap
            int mid = (low + high) / 2;
            int left = rangeQuery_utility(l, r, 2 * i + 1, low, mid);
            int right = rangeQuery_utility(l, r, 2 * i + 2, mid + 1, high);
            
            // operations
            return max(left, right);
        }

    public:
        SegmentTree(vector<int>& arr) {
            n = arr.size();
            seg.resize(4 * n);
            BuildTree(0, 0, n - 1, arr);
        }
        
        int rangeQuery(int l, int r) {
            int i = 0;
            int low = 0;
            int high = n - 1;
            return rangeQuery_utility(l, r, i, low, high);
        }

        int updateTree(int index, int val) {
            int i = 0;
            int low = 0;
            int high = n - 1;
            updateTree_utility(index, val, i, low, high);
            return seg[0];
        }
};

int main() {
    vector<int> arr = {1, 3, 2, 7, 9, 11};
    SegmentTree st(arr);

    cout << st.rangeQuery(1, 4) << "\n"; // 9
    st.updateTree(3, 10);                // update arr[3] = 10
    cout << st.rangeQuery(1, 4) << "\n"; // 10
}
