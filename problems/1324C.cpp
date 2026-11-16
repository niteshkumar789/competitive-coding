// Problem 7
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

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        
        int size = str.length();
        int mini = 1;
        int last_idx =  size + 1;

        for (int i = size; i >= 1; i--) {
            if (str[i - 1] == 'R') {
                mini = max(mini, last_idx - i);
                last_idx = i;
            }
        }
        
        mini = max(mini, last_idx);
        cout << mini << endl;
    }
    return 0;
}