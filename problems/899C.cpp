// 899C - Dividing the numbers
// https://codeforces.com/problemset/problem/899/C

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

    ll n;
    cin >> n;

    if (n == 3) {
        cout << 0 << endl << 1 << " " << 3;
        return 0;
    }

    ll sum = (n * (n + 1)) / 2;
    int absDiff = (sum % 2 == 0) ? 0 : 1;
    ll nd2 = n / 2;

    vi ans;
    bool isEven = (n % 2) == 0;
    int temp = isEven ? (nd2 / 2) + 1 : (nd2 / 2) + 2;
    int k = isEven ? 1 : 2;

    rep(i, k, temp) {
        ans.pb(i);
        int var = isEven ? (n - i + 1) : (n - i + 2);
        ans.pb(var);
    }

    if ((nd2 % 2) != 0) {
        if (isEven) {
            ans.pb(nd2);
        } else {
            ans.pb(1);
            ans.pb(nd2 + 1);
        }
    }

    cout << absDiff << "\n" << ans.size() << " ";
    printArray(ans);
    return 0;
}