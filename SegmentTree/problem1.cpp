#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// BuildTree(0, 0, size - 1, false, arr, seg);
void BuildTree(int i, int low, int high, bool flag, vector<int>& arr, vector<int>& seg) {
    if (low == high) {
        seg[i] = arr[low];
        return;
    }
    
    int mid = (low + high) / 2;
    
    BuildTree(2 * i + 1, low, mid, !flag, arr, seg);
    BuildTree(2 * i + 2, mid + 1, high, !flag, arr, seg);
    
    if (flag == true) {
        seg[i] = (seg[2 * i + 1] | seg[2 * i + 2]);
    } else {
        seg[i] = (seg[2 * i + 1] ^ seg[2 * i + 2]);
    }
}

void updateTree(int index, int& val, int i, int low, int high, bool flag, vector<int>& seg) {
    if (low == high) {
        seg[i] = val;
        return;
    }
    
    int mid = (low + high) / 2;
    
    // recursion
    if (index <= mid) {
        updateTree(index, val, 2 * i + 1, low, mid, !flag, seg);
    }
    else {
        updateTree(index, val, 2 * i + 2, mid + 1, high, !flag, seg);
    }
    
    // operations
    if (flag == true) {
        seg[i] = (seg[2 * i + 1] | seg[2 * i + 2]);
    } else {
        seg[i] = (seg[2 * i + 1] ^ seg[2 * i + 2]);
    }
}

int main() {
    int n, m;
    cin >> n;
    cin >> m;
    
    int size = pow(2, n);
    vector<int> arr(size);
    
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // build a segment tree
    vector<int> seg(4 * size);
    if (n % 2 == 0) {
        BuildTree(0, 0, size - 1, false, arr, seg);
    } else {
        BuildTree(0, 0, size - 1, true, arr, seg);
    }

    // queries input
    while (m--) {
        int index, val;
        cin >> index >> val;
        
        if (n % 2 == 0) {
            // input is 1-based, you must convert to 0-based:
            updateTree(index - 1, val, 0, 0, size - 1, false, seg); 
        }
        else {
            updateTree(index - 1, val, 0, 0, size - 1, true, seg);
        }
        cout << seg[0] << endl;
    }

    return 0;
}

// Codeforces Round 197 (Div. 2)
// Problem: D. Xenia and Bit Operations
// Link - https://codeforces.com/problemset/problem/339/D