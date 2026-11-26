// 519C - A and B and Team Training
// https://codeforces.com/problemset/problem/519/C

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

void printArray(vvi arr) {
    int n = arr.size();
    rep(i, 0, n) {
        rep(j, 0, n) {
            cout << arr[i][j];
            if (j != n - 1) cout << " ";
        }
        if (i != n - 1) cout << endl;
    }
}

void solve(int n, int m) {
    if (n * 2 < m) {
        cout << n;
    } else if (n > m * 2) {
        cout << m;
    }
    else {
        int r1 = n % 3;
        int r2 = m % 3;

        int ans = (((r1 + r2) / 3) + (n / 3) + (m / 3));
        cout << ans;
    }
}
int main() {
    fastio;

    int n, m;
    cin >> n >> m;
    solve(n, m);

    return 0;
}