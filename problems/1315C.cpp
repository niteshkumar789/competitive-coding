// 1315C - Restoring Permutation
// https://codeforces.com/problemset/problem/1315/C

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
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = b - 1; i >= a; i--)
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

void helper(vi b, int n) {
    sti st;
    // insert 2n element
    rep(i, 1, 2*n + 1) {
        st.insert(i);
    }
    
    // remove element of b
    rep(i, 0, n) {
        st.erase(b[i]);
    }

    vi ans;
    rep(i , 0, n) {
        ans.pb(b[i]);

        auto it = st.upper_bound(b[i]);
        if (it == st.end()) {
            cout << -1 << endl;
            return;
        }
        ans.pb(*it);
        st.erase(*it);
    }
    rep(i, 0, 2*n) {
        cout << ans[i];

        if (i != 2 * n - 1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
}

int main() {
    fastio;
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        vi b(n);
        rep(i, 0, n) {
            cin >> b[i];
        }
        helper(b, n);
    }
    return 0;
}