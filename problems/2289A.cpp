// 2289A - Problem from Dolgoderevenskoye
// Codeforces Round 1137 (Div. 2)

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
#define sti set<int>
#define vpi vector<pii>
#define um unordered_map
#define umii um<int, int>
#define umib um<int, bool>
#define umci um<char, int>
#define umcb um<char, bool>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = b - 1; i >= a; i--)
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

int main() {
    fastio;
    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        
        // ll odd = 0;
        // ll even = 0;

        // ll last = sqrtl(n);

        // for (ll i = 1; i <= n / i; i++) {
        //     if (n % i == 0) {
        //         ll temp = n / i;
                
        //         if ((i & 1) == 0) even++;
        //         else odd++;

        //         if (i != temp) {
        //             if ((temp & 1) == 0) even++;
        //             else odd++;
        //         }
        //     }
        // }

        // if (even == odd) {
        //     cout << "NO" << endl;
        // } else {
        //     cout << "YES" << endl;
        // }

        if (n % 2 == 0 && n % 4 != 0) 
            cout << "NO" << endl;
        else 
            cout << "YES" << endl;

        /*  Counting Even vs. Odd Divisors: The O(1) Math Trick
            Core Decomposition
                - Every positive integer N can be uniquely written as: N = 2^k × m
                - k: Number of times N is divisible by 2 (the "even part").
                - m: The remaining odd factor (the "odd part").

            Divisor Formulas
                - Let d(m) be the total number of divisors of m. Since m is odd, all of its divisors are odd.
                - Odd Divisors: Formed by combining 2^0 with any divisor of m. Odd Divisors = d(m)
                - Even Divisors: Formed by combining {2^1, 2^2 , &dots;, 2^k} with any divisor of m. Even Divisors = k × d(m)
                - Total Divisors = (k + 1) × d(m)

            Summary of Parity Cases
                Case            Condition on k      Condition on N              Odd vs. Even Divisors               Example
                Odd Number      k = 0               N % 2 != 0                  Even = 0, Odd > 0 (Odd > Even)      N = 15 (20 × 15) Odd: 4, Even: 0
                Singly Even     k = 1               N % 2 == 0 && N % 4 != 0    Even == Odd                         N = 18 (21 × 9) Odd: 3, Even: 3
                Doubly Even     k ≥ 2               N % 4 == 0                  Even = k · Odd (Even > Odd)         N = 12 (22 × 3) Odd: 2, Even: 4
        
        */
    }

    return 0;
}