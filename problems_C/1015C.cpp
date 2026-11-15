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
    int n, m;
    cin >> n >> m;
    
    int temp = n;
    vector<vi> songs;
    while (temp--) {
        int ai, bi;
        cin >> ai >> bi;
        songs.pb({ai, bi});
    }

    // 10 8 - 2
    // 7 4 - 3
    // 3 1 - 2
    // 5 4 - 1

    return 0;
}