// 919C - Seat Arrangements
// https://codeforces.com/problemset/problem/919/C

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

    int n, m, k;
    cin >> n >> m >> k;

    vector<string> arr(n);
    rep(i, 0, n) {
        cin >> arr[i]; // Fix 1: Clean input without losing characters
    }

    // operations
    if (m < k && n < k) {
        cout << 0;
        return 0;
    }

    int ans = 0;
    rep(i, 0, n) {
        int j = 0;
        while (j < m) {
            if (arr[i][j] == '.') {
                int t = j;
                while (t < m && arr[i][t] == '.') {
                    t++;
                }
                int ct = t - j;
                if (ct >= k) {
                    ans += (ct - k + 1);
                }
                j = t;
            }
            else {
                j++;
            }
        }
    }

    rep(j, 0, m) {
        
        int i = 0;
        while (i < n) {
            if (arr[i][j] == '.') {
                int t = i;
                while (t < n && arr[t][j] == '.') {
                    t++;
                }
                int ct = t - i;
                if (ct >= k) {
                    ans += (ct - k + 1);
                }
                i = t;
            }
            else {
                i++;
            }
        }
    }

    if (k == 1) {
        ans /= 2;
    }

    cout << ans;
    return 0;
}