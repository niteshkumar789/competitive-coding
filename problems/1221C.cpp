// 1221C - Perfect Team
// https://codeforces.com/problemset/problem/1221/C

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
#define sti set<int>
#define vpi vector<pii>
#define um unordered_map
#define umii um<int, int>
#define umib um<int, bool>
#define umci um<char, int>
#define umcb um<char, bool>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = b - 1; i >= a; i--)
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

int main() {
    fastio;
    int t;
    cin >> t;

    while (t--) {
        int c , m, x;
        cin >> c >> m >> x;

        int curr = (c + m + x) / 3;
        int ans = min(min(c, m), curr);
        cout << ans << endl;
    }

    return 0;
}