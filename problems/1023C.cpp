// 1023C - Bracket Subsequence
// https://codeforces.com/problemset/problem/1023/C

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

    int n, k;
    cin >> n >> k;
    cin.ignore();

    string str;
    getline(cin, str);

    stack<char> st;
    int t = n - k;
    rep (i, 0, n) {
        if (str[i] == ')' && t > 0) {
            st.pop();
            t -= 2;
        } 
        else {
            st.push(str[i]);
        }
    }
    string ans = "";
    while (!st.empty()) {
        ans = (st.top() + ans);
        st.pop();
    }
    cout << ans;
    
    return 0;
}