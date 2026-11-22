// 1102C - Doors Breaking and Repairing
// https://codeforces.com/problemset/problem/1102/C

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
    int n, x, y;
    cin >> n >> x >> y;

    vi arr(n);
    rep(i, 0, n) {
        cin >> arr[i];
    }

    if (x > y) {
        cout << n;
        return 0;
    }

    if (x <= y) {
        int ct = 0;
        rep(i, 0, n) {
            if (arr[i] <= x) {
                ct++;
            }
        }

        int temp = ct / 2;
        temp += ct % 2;
        cout << temp;
    }
    
    return 0;
}