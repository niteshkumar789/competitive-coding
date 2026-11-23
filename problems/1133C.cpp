// 1133C - Balanced Team
// https://codeforces.com/problemset/problem/1133/C

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
    int n;
    cin >> n;
    
    vi arr(n);
    rep(i, 0, n) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    int i = 0, j = 0, ans = 0;

    while (i < n) {
        while (j < n && arr[j] - arr[i] <= 5) {
			++j;
			ans = max(ans, j - i);
		}
        i++;
    }
    cout << ans;
    return 0;
}