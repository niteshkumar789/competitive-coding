// Problem 3
#include <bits/stdc++.h>
using namespace std;
 
void helper(vector<int> seq, int n) {
    vector<int> inc;
    vector<int> dec;
 
    // sort
    sort(seq.begin(), seq.end());
    inc.push_back(seq[0]);
 
    int ct = 1;
    for (int i = 1; i < n; i++) {
        if (seq[i] == seq[i - 1]) {
            dec.push_back(seq[i]);
            ct++;
        }
        else {
            ct = 1;
            inc.push_back(seq[i]);
        }
        if (ct == 3) {
            cout << "NO";
            return;
        }
    }
 
    sort(dec.rbegin(), dec.rend());
    
    int s1 = inc.size();
    cout << "YES" << endl;
    cout << s1 << endl;
    if (s1 == 0) {
        cout << endl;
    }
    for (int i = 0; i < s1; i++) {
        cout << inc[i];
        if (i != s1 - 1) {
            cout << " ";
        }
    }
    cout << endl;
    // --------------------------------------------
    int s2 = dec.size();
    cout << s2 << endl;
    if (s2 == 0) {
        cout << endl;
        return;
    }
    for (int i = 0; i < dec.size(); i++) {
        cout << dec[i];
        if (i != s2 - 1) {
            cout << " ";
        }
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> seq(n);
 
    for (int i = 0; i < n; i++) {
        int temp = 0;
        cin >> temp;
        seq[i] = temp;
    }
    helper(seq, n);
    return 0;
}