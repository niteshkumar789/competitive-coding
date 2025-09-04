#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>

// #include <bits/stdc++.h>
using namespace std;


// ************************************ MACROS ************************************
// Type shortcuts
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vpi vector<pii>

// Fast I/O
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

// Loops
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = b - 1; i >= a; i--)

// Sorting and useful STL tricks
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sortall(x) sort(all(x))

// Debugging
#define debug(x) cout << #x << " = " << x << endl;

void Test() {
    vi arr = {3, 1, 4, 7, 6};
    
    rep(i, 0, 5) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // ----------------------------------
    
    rrep(i, 0, 5) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // ----------------------------------
    
    sortall(arr);
    rep(i, 0, 5) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // ----------------------------------
    
    debug(arr[2]);
}

int main() {
    // int t;
    // cin >> t;
    
    // while (t--) {
    //     int n;
    //     cin >> n;
    // }

    return 0;
}