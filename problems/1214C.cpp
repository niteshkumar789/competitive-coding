// 1214C - Bad Sequence
// https://codeforces.com/problemset/problem/1214/C

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
#define umib um<int, bool>
#define umci um<char, int>
#define umcb um<char, bool>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = b - 1; i >= a; i--)
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

int main() {
    int n;
    cin >> n;
    string str;
    
    cin.ignore();
    getline(cin, str);

    int open = 0;
    int close = 0;
    rep(i, 0, n) {
        if (str[i] == '(') open++;
        else close++;
    }

    if (open != close) {
        cout << "NO";
        return 0;
    }
    stack<char> st;
    rep(i, 0, n) {
        if (str[i] == ')') {
            if (!st.empty() && st.top() == '(') {
                st.pop();
                continue;
            }
        }
        st.push(str[i]);
    }
    if (st.size() > 2) {
        cout << "NO";
        return 0;
    }
    cout << "YES";

    return 0;
}