// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define T pair<pair<int,int>, int>  // ((x,y), xorVal)

void bfs(vector<vector<int>>& arr, int n, int m, int k, int& ans) {

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<T> q;

    q.push({{0, 0}, arr[0][0]});
    visited[0][0] = true;

    while (!q.empty()) {
        auto [pos, xr] = q.front();
        q.pop();

        int x = pos.first;
        int y = pos.second;

        // reached bottom-right
        if (x == n - 1 && y == m - 1 && xr == k) {
            ans++;
            continue;
        }

        // move right
        if (y + 1 < m && !visited[x][y + 1]) {
            int newXor = xr ^ arr[x][y + 1];
            visited[x][y + 1] = true;
            q.push({{x, y + 1}, newXor});
        }
        // move down
        if (x + 1 < n && !visited[x + 1][y]) {
            int newXor = xr ^ arr[x + 1][y];
            visited[x + 1][y] = true;
            q.push({{x + 1, y}, newXor});
        }
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> arr(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    
    int ans = 0;
    bfs(arr, n, m, k, ans);
    cout << ans << endl;
    return 0;
}
