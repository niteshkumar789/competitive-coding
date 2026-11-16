// Problem 8
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
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = b - 1; i >= a; i--)
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<vi> matrix(n, vi(m));

    // Input
    int sum = 0;
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> matrix[i][j];
            sum += matrix[i][j];
        }
    }

    // Operations
    int maxPossible = 0;
    rrep(i, 0, n) {
        rrep(j, 0, m) {
            int num = matrix[i][j];

            if (num != 0) {
                bool flag1 = (j + 1 < m) ? (num < matrix[i][j + 1] ? true : false) : true;
                bool flag2 = (i + 1 < n) ? (num < matrix[i + 1][j] ? true : false) : true;

                if (!(flag1 && flag2)) {
                    cout << -1;
                    return 0;
                }
            }
            else {
                int temp = (min(matrix[i][j + 1], matrix[i + 1][j]) - 1);
                matrix[i][j] = temp;
                maxPossible += temp;
            }
        }
    }
    cout << sum + maxPossible;
    return 0;
}