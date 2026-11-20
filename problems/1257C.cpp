// 1257C - Dominated Subarray
// https://codeforces.com/problemset/problem/1257/C

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

void helper(vi arr, int n) {
    int i = 0;
    umii mp;
    int ans = INT_MAX;

    while (i < n) {
        if (mp.find(arr[i]) != mp.end()) {
            ans = min(ans, i - mp[arr[i]] + 1);
        }
        mp[arr[i]] = i;
        i++;
    }
    if (ans == INT_MAX) {
        cout << -1 << endl;
        return;
    }
    cout << ans << endl;
}

int main() {
    fastio;
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        vi arr(n);
        rep(i, 0, n) {
            cin >> arr[i];
        }
        helper(arr, n);
    }

    return 0;
}