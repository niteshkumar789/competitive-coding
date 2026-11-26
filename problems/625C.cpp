// 625C - K-special Tables
// https://codeforces.com/problemset/problem/625/C

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

void solve(int n, int k) {
    int N = n * n;
    vvi matrix(n, vi(n));
    
    int num = (n * (k - 1)) + 1;
    int sum = 0;
    rep(i, 0, n) {
        int c = k - 1;
        rep(j, c, n) {
            matrix[i][j] = num++;
        }
        sum += matrix[i][c];
    }

    num = 1;
    rep(i, 0, n) {
        rep(j, 0, k - 1) {
            matrix[i][j] = num++;
        }
    }
    cout << sum << endl;
    printArray(matrix);
}
int main() {
    fastio;

    int n, k;
    cin >> n >> k;
    solve(n, k);

    return 0;
}