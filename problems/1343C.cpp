// 1343C - Alternating Subsequence
// https://codeforces.com/problemset/problem/1343/C

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

        int i = 0;
        ll sum = 0;
        bool isPos = (arr[0] > 0) ? true : false;

        while (i < n) {
            int currMax = 0;
            if (isPos) {
                while (i < n && arr[i] > 0) {
                    currMax = max(currMax, arr[i]);
                    i++;
                }
                isPos = false;
            }
            else {
                currMax = arr[i];
                while (i < n && arr[i] < 0) {
                    currMax = max(currMax, arr[i]);
                    i++;
                }
                isPos = true;
            }
            sum += currMax;
        }
        cout << sum << endl;
    }
    return 0;
}