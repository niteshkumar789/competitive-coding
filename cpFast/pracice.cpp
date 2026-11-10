#include <bits/stdc++.h>
using namespace std;

// ************************************ MACROS ************************************
// Type shortcuts
#define ll long long
#define pb push_back
#define pbb pop_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int, int>
#define vi vector<int>
#define vpi vector<pii>

#define SQ(a) (a)*(a)

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

/*  Notes:
        (a+b) mod m = (a % m + b % m) % m
        (a−b) mod m = (a % m − b % m) % m
        (a·b) mod m = (a % m · b % m) % m

    Deque
    A deque is a dynamic array whose size can be efficiently changed at both ends of
    the array. Like a vector, a deque provides the functions push_back and pop_back,
    but it also includes the functions push_front and pop_front which are not avail
    able in a vector.
        deque<int> d;
        d.push_back(5); // [5]
        d.push_back(2); // [5,2]
        d.push_front(3); // [3,5,2]
        d.pop_back(); // [3,5]
        d.pop_front(); // [5]

    The internal implementation of a deque is more complex than that of a vector,
    and for this reason, a deque is slower than a vector. Still, both adding and
    removing elements take O(1) time on average at both ends
*/

int main() {
    int n;
    cin >> n;
    double ans = 0;
    int sum = 0;
    int x = n;

    while (n--) {
        int a;
        cin >> a;
        sum += a;
    }
    ans = sum / double(x);
    // cout << ans;
    cout << fixed << setprecision(12) << ans;

    return 0;
}