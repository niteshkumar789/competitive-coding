// 747C - Servers
// https://codeforces.com/problemset/problem/747/C

#include <bits/stdc++.h>
using namespace std;

// Type shortcuts
#define ll long long
#define pb push_back
#define pbb pop_back
#define F first
#define S second
#define pii pair<int, int>
#define vi vector<int>
#define vc vector<char>
#define vvi vector<vector<int>>
#define sti set<int>
#define vpi vector<pii>
#define um unordered_map
#define umii um<int, int>
#define umci um<char, int>
#define umcb um<char, bool>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = b - 1; i >= a; i--)
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

void printArray(vi arr) {
    int n = arr.size();
    rep(i, 0, n) {
        cout << arr[i];
        if (i != n - 1) cout << " ";
    }
}

int main() {
    fastio;

    int n, q;
    cin >> n >> q;

    vvi matrix;
    rep(i, 0, q) {
        int x, y, z;
        cin >> x >> y >> z;
        matrix.pb({x, y, z});
    }

    

    return 0;
}