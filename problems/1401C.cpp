// 1401C - Mere Array
// https://codeforces.com/problemset/problem/1401/C

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
#define vvi vector<vector<int>>
#define vc vector<char>
#define vpi vector<pii>
#define sti set<int>
#define um unordered_map
#define umii um<int, int>
#define umci um<char, int>
#define umcb um<char, bool>
#define umib um<int, bool>
#define minhp priority_queue<int, vi, greater<int>>
#define maxhp priority_queue<int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = b - 1; i >= a; i--)
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

void printArray(vi arr) {
    int n = arr.size();
    rep(i, 0, n) {
        cout << arr[i];
        if (i != n - 1) 
            cout << " ";
    }
}
void printMatrix(vvi arr) {
    int n = arr.size();
    rep(i, 0, n) {
        rep(j, 0, n) {
            cout << arr[i][j];
            if (j != n - 1) cout << " ";
        }
        if (i != n - 1) cout << endl;
    }
}

void solve(int n, vi arr) {
    vi temp = arr;
    sort(arr.begin(), arr.end());
    int mini = arr[0];

    rep(i, 0, n) {
        if (arr[i] != temp[i] && temp[i] % mini != 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
        solve(n, arr);
    }

    return 0;
}