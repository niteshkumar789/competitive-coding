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
#define ll long long        // Use when constraints are large (careful with overflow)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vpi vector<pii>

// Loops
#define rep(i,a,b) for(int i=a;i<b;i++)         // rep(i,0,n) is a common idiom
#define rrep(i,a,b) for(int i=a;i>=b;i--)       // reverse loop

// Fast I/O
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

// Sorting and useful STL tricks
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sortall(x) sort(all(x))

// Debugging
#define debug(x) cout << #x << " = " << x << endl;

// ********************************************************************************

// #include <bits/stdc++.h>
// using namespace std;

// #define int long long
// #define pb push_back
// #define vi vector<int>
// #define rep(i,a,b) for(int i=a; i<b; i++)
// #define fastio ios::sync_with_stdio(false); cin.tie(NULL);

// void solve() {
//     int n; cin >> n;
//     vi a(n);
//     rep(i,0,n) cin >> a[i];
//     sort(all(a));
//     cout << a[0] << "\n";
// }

// int32_t main() {
//     fastio
//     int t=1;
//     // cin >> t;
//     while(t--) solve();
//     return 0;
// }


int find_answer(int n) {
    string str = to_string(n);
    if (str.length() == 1) return 0;

    // find sum
    int sum = 0;
    int temp = n;
    while (n) {
        sum += (n % 10);
        n /= 10;
    }
    if (ceil(temp / sum) == 1) return 0; 


    // find count
    int j = str.length() - 1;
    int ct = 0;
    while (j >= 0 && str[j] == '0') {
        ct++;
        j--;
    }

    int i = 0;
    while (i < j) {
        if (str[i] != '0') ct++;
        i++;
    }
    return ct;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;

        // find answer
        cout << find_answer(n) << endl;
    }

    return 0;
}