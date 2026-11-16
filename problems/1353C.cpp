// Problem 2

#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        
        ll T = (n - 1) / 2;
        ll sum = ((T * (T + 1) * (2 * T + 1) ) / 6 ) * 8;
        cout << sum << endl;
    }
    return 0;
}