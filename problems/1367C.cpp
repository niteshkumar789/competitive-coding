// 1367C - Social Distance
// https://codeforces.com/problemset/problem/1367/C

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

void solve(int n, string str, int k) {
    int i = 0;
    int ans = 0;
    bool flag = false;

    // case 1: leading zeros (or all zeros)
    while (i < n && str[i] != '1') {
        i++;
    }
    flag = (i < n && str[i] == '1') ? true : false;
    if (!flag) {
        ans += 1;
        ans += ((i - 1) / (k + 1));
        cout << ans << "\n";
        return;
    }
    ans += (i / (k + 1));

    // case 2: trailing zeros
    int j = n - 1;
    while (j >= i && str[j] != '1') {
        j--;
    }
    
    ans += ((n - j - 1) / (k + 1));
    if (i == j) {
        cout << ans << "\n";
        return;
    }

    // case 3: middle segments between two '1's
    int l = i + 1;
    while (l <= j) {
        while (l <= j && str[l] != '1') {
            l++;
        }
        int ct = l - i - 1;
        ans += max(0, (ct - k) / (k + 1));
        i = l;
        l++;
    }
    cout << ans << "\n";
}

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        string str;
        cin >> str; // Fixed input reading
        solve(n, str, k);
    }

    return 0;
}