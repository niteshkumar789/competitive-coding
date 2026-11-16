// Problem 8
#include <bits/stdc++.h>
using namespace std;

// problem - 8

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
    vector<vi> matrix(n, vi(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int j = m - 2; j >= 0; j--) {
        if (matrix[n - 1][j] >= matrix[n - 1][j + 1] || matrix[0][j] >= matrix[0][j + 1]) {
            // cout << -1 << "Hello0";
            return 0;
        }
    }
    // Vertical
    for (int i = n - 2; i >= 0; i--) {
        if (matrix[i][m - 1] >= matrix[i + 1][m - 1] || matrix[i][0] >= matrix[i + 1][0]) {
            // cout << -1 << "Hello";
            return 0;
        }
    }
    
    // 1 3 5 6 7
    // 3 0 7 0 9
    // 5 0 0 0 10
    // 8 9 10 11 12

    for (int i = n - 2; i > 0; i--) {
        for (int j = m - 2; j > 0; j--) {
            int num = matrix[i][j];
            // cout << num << "--";
            if (num != 0) {
                bool flag = (
                            (matrix[i][j + 1] != 0 && num >= matrix[i][j + 1]) || 
                            (matrix[i][j - 1] != 0 && num <= matrix[i][j - 1]) || 
                            (matrix[i + 1][j] != 0 && num >= matrix[i + 1][j]) || 
                            (matrix[i - 1][j] != 0 && num <= matrix[i - 1][j])
                        );
                if (flag) {
                    cout << -1;
                    // cout << -1 << "Hello--";
                    return 0;
                }
            }
        }
    }

    int sum = 0;
    for (int i = n - 2; i > 0; i--) {
        for (int j = m - 2; j > 0; j--) {

            int num = matrix[i][j];
            if (
                (matrix[i][j - 1] != 0 && (matrix[i][j - 1] + 1 == matrix[i][j + 1])) || 
                (matrix[i - 1][j] != 0 && (matrix[i - 1][j] + 1 == matrix[i + 1][j]))
            ) {
                cout << -1;
                return 0;
            }
            else {
                sum += (1 + min(matrix[i][j + 1], matrix[i + 1][j]));
            }
        }
    }
    cout << sum;
    return 0;
}