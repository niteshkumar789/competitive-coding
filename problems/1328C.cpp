// 1328C - Ternary XOR
// https://codeforces.com/problemset/problem/1328/C

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
        cin.ignore();
        string x;
        getline(cin, x);

        vi a(n, 0);
        vi b(n, 0);
        bool flag = false; // max decided

        rep(i, 0, n) {
            if (flag == true) {
                b[i] = x[i] - '0';
            }
            else {
                if (x[i] == '2') {
                    a[i] = 1;
                    b[i] = 1;
                }
                else if (x[i] == '1') {
                    a[i] = 1;
                    flag = true;
                }
            }
        }
        rep(i, 0, n) {
            cout << a[i];
        }
        cout << endl;
        rep(i, 0, n) {
            cout << b[i];
        }
        cout << endl;
    }
    return 0;
}