// Codeforces Round 1135 (Div. 2)

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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (n < 4) {
            cout << -1 << endl;
            continue;
        }

        vector<int> temp(n);
        temp[0] = 4;
        temp[1] = 3;

        if ((n & 1) == 0) {
            temp[n - 1] = 1;
            temp[n - 2] = 2;
        }
        else {
            temp[n - 1] = 2;
            temp[n - 2] = 1;
        }

        int ct = 5;
        for (int i = 2; i < n - 2; i++) {
            temp[i] = ct++;
        }
        
        for (int i = 0; i < n; i++) {
            cout << temp[i];
            if (i < n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}