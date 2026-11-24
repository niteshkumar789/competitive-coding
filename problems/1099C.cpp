// 1099C - Postcard
// https://codeforces.com/problemset/problem/1099/C

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
    string str;
    getline(cin, str);
    int k;
    cin >> k;
    
    int n = str.length();
    int ct = 0;
    rep(i, 0, n) {
        if (str[i] != '?' && str[i] != '*') ct++;
    }

    string ans = "";
    if (ct > k) {
        int t = ct - k;
        rep(i, 0, n) {
            if (t > 0 && (str[i] == '?' || str[i] == '*')) {
                ans.pbb();
                t--;
            } else {
                if (str[i] != '?' && str[i] != '*') {
                    ans.pb(str[i]);
                }
            }
        }
        if (t == 0) {
            cout << ans;
        } else {
            cout << "Impossible";
        }
    }
    else {
        int t = k - ct;
        rep(i, 0, n) {
            if (str[i] == '*') {
                while (t > 0) {
                    ans.pb(ans[ans.size() - 1]);
                    t--;
                }
            }
            else {
                if (str[i] != '?' && str[i] != '*') {
                    ans.pb(str[i]);
                }
            }
        }
        if (ans.size() == k) 
            cout << ans;
        else 
            cout << "Impossible";
    }
    return 0;
}