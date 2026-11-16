// 1385C (Make It Good)
// https://codeforces.com/problemset/problem/1385/C

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
#define vpi vector<pii>
#define um unordered_map
#define umii um<int, int>
#define umci um<char, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = b - 1; i >= a; i--)
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

int main() {
    fastio;
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int i = n - 1;

        // Find the non-increasing suffix
        while (i > 0 && a[i - 1] >= a[i]) {
            i--;
        }
        // Find the non-decreasing portion before it
        while (i > 0 && a[i - 1] <= a[i]) {
            i--;
        }
        cout << i << '\n';
    }
    return 0;
}