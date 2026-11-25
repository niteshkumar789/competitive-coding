// 1006C - Three Parts of the Array
// https://codeforces.com/problemset/problem/1006/C

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

    int n;
    cin >> n;

    vi arr(n);
    rep(i, 0, n) {
        cin >> arr[i];
    }

    um<ll, ll> mp;
    ll sum = 0;
    rep(i, 0, n) {
        sum += arr[i];
        mp[sum] = i;
    }
    ll ans = 0;
    sum = 0;
    rrep(i, 0, n) {
        sum += arr[i];
        if (mp.find(sum) != mp.end() && mp[sum] < i) {
            ans = max(ans, sum);
        }
    }
    cout << ans;
    return 0;
}