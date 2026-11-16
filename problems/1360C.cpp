// Problem 5
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

void helper(vi arr, int n) {
    unordered_map<int, int> mp;
    vi odd, even;

    for (int i = 0; i < n; i++) {
        if ((arr[i] & 1) == 0) {
            even.pb(arr[i]);
            mp[arr[i]] = 1;
        } else {
            odd.pb(arr[i]);
        }
    }
    if ((odd.size() & 1) == 0 && (even.size() & 1) == 0) {
        cout << "YES" << endl;
        return;
    }
    for (int i = 0; i < odd.size(); i++) {
        if (mp[odd[i] + 1] || mp[odd[i] - 1])  {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        cin.ignore();
        vi arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        helper(arr, n);
    }
    return 0;
}