// Problem 1
#include <bits/stdc++.h>
using namespace std;
 
void helper(string s, int n) {
    int open = 0;
    int close = 0;
 
    for (int i = 0; i < n; i++) {
        if (s[i] == ')') {
            if (open == 0)
                close++;
            else {
                open--;
            }
        }
        else {
            open++;
        }
    }
    cout << open << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();
 
        string s;
        getline(cin, s);
        helper(s, n);
    }
    return 0;
}