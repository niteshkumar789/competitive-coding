#include <iostream>
#include <vector>
#include <array>
#include <string>
using namespace std;

class SegmentTree {
    private:
        vector<array<int, 3>> seg; // {openCt, closeCt, totalComplete}
        int n;
        
        array<int, 3> merge(const array<int, 3>& L, const array<int, 3>& R) {
            int matched = min(L[0], R[1]);
            int total = L[2] + R[2] + 2 * matched;
            
            int openCt = L[0] + R[0] - matched;
            int closeCt = L[1] + R[1] - matched;
            return {openCt, closeCt, total};
        }

        void BuildTree(int i, int low, int high, string& str) {
            if (low == high) {
                if (str[low] == '(') seg[i] = {1, 0, 0};
                else seg[i] = {0, 1, 0};
                
                return;
            }
            
            int mid = (low + high) / 2;
            BuildTree(2 * i + 1, low, mid, str);
            BuildTree(2 * i + 2, mid + 1, high, str);
            
            // operation
            seg[i] = merge(seg[2 * i + 1], seg[2 * i + 2]);
        }
        
        array<int, 3> rangeQuery_utility(int l, int r, int i, int low, int high) {
            // no overlap
            if (r < low || l > high) return {0, 0, 0};
            
            // complete overlap
            if (l <= low && r >= high) return seg[i];
            
            // partial overlap
            int mid = (low + high) / 2;
            auto left = rangeQuery_utility(l, r, 2 * i + 1, low, mid);
            auto right = rangeQuery_utility(l, r, 2 * i + 2, mid + 1, high);
                
            // operation
            return merge(left, right);
        }

    public:
        SegmentTree(string& str) {
            n = str.size();
            seg.resize(4 * n);
            BuildTree(0, 0, n - 1, str);
        }
        
        int rangeQuery(int l, int r) {
            array<int, 3> temp = rangeQuery_utility(l, r, 0, 0, n - 1);
            return temp[2];
        }
};

int main() {
    string str;
    getline(cin, str);
    
    int m;
    cin >> m;
    
    SegmentTree sg(str);
    
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << sg.rangeQuery(l - 1, r - 1) << endl;
    }
    return 0;
}

// Codeforces Round 223 (Div. 1)
// Problem: C. Sereja and Brackets
// Link - https://codeforces.com/problemset/problem/380/C