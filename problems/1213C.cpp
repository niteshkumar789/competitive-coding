// 1213C - Book Reading
// https://codeforces.com/problemset/problem/1213/C

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

int main() {
    fastio;
    int t;
    cin >> t;

    while (t--) {
        ll n, m;
        cin >> n >> m;

        ll temp = n / m;
        ll rep = temp / 10;
        ll moreRep = temp % 10;

        ll sum = 0;
        rep(i, 1, 11) {
            sum += ((m * i) % 10);
        }

        ll ans = sum * rep;
        rep(i, 1, moreRep + 1) {
            ans += ((m * i) % 10);
        }

        cout << ans << endl;
    }

    return 0;
}