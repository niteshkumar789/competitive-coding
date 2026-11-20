// 1272C - Yet Another Broken Keyboard
// https://codeforces.com/problemset/problem/1272/C

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

void helper(int n, int k, string s, vector<char> str) {
    umcb mp;
    rep(i, 0, k) {
        mp[str[i]] = true;
    }

    bool flag = false;
    int i = 0;
    ll ans = 0;
    while (i < n) {
        ll ct = 0;
        while (i < n && mp[s[i]]) {
            ct++;
            i++;
        }
        if (ct != 0) {
            ans += ((ct * (ct + 1)) / 2);
        }
        i++;
    }

    cout << ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    cin.ignore(); 
    string s;
    getline(cin, s);
    vector<char> str(k);
    rep(i, 0, k) {
        cin >> str[i];
    }
    helper(n, k, s, str);

    return 0;
}