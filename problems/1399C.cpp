// problem 10
// ****************** Important Question ******************
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
#define um unordered_map
#define umii um<int, int>
#define umci um<char, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = b - 1; i >= a; i--)
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

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

        ll sum = 0;
        int i = 1;
        while (i < n) {
            if (arr[i - 1] > arr[i]) {
                ll temp = arr[i - 1];
                ll currDiff = temp - arr[i];

                i++;
                ll maxDiff = 0;
                while (arr[i - 1] > arr[i] && i < n) {
                    maxDiff = temp - arr[i];
                    i++;
                }
                sum += max(currDiff, maxDiff);
            }
            i++;
        }
        cout << sum << endl;
    }
    return 0;
}