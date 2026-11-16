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
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    
    int temp = n;
    vi diff;
    ll total = 0;
    ll compressed = 0;

    while (temp--) {
        int ai, bi;
        cin >> ai >> bi;
    
        total += ai;
        compressed += bi;
        diff.pb(ai - bi);
    }

    if (compressed > m) {
        cout << -1;
        return 0;
    }

    sort(diff.begin(), diff.end());
    ll remaining = m - compressed;
    ll ans = n;
    for(int i = 0; i < n; i++) {
        if (diff[i] <= remaining) {
            remaining -= diff[i];
            ans--;
        }
        else {
            break;
        }
    }
    cout << ans;
    return 0;
}