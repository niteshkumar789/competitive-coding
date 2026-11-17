// 1352C - K-th Not Divisible by n
// https://codeforces.com/problemset/problem/1352/C

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
        int n, k;
        cin >> n >> k;

        int rem = k % (n - 1);
        int num = (k / (n - 1)) * n;

        if (rem == 0) {
            num -= 1;
        }
        cout << num + rem << endl;
    }
    return 0;
}