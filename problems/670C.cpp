// 	670C - Cinema
// https://codeforces.com/problemset/problem/670/C

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
#define vc vector<char>
#define vvi vector<vector<int>>
#define sti set<int>
#define vpi vector<pii>
#define um unordered_map
#define umii um<int, int>
#define umci um<char, int>
#define umcb um<char, bool>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = b - 1; i >= a; i--)
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

void printArray(vi arr) {
    int n = arr.size();
    rep(i, 0, n) {
        cout << arr[i];
        if (i != n - 1) cout << " ";
    }
}


void solve(vi arr, vi audio, vi subtitles, int n, int m) {
    umii mp;
    rep(i, 0, n) {
        mp[arr[i]]++;
    }

    int movie = -1;
    int maxFreq = 0;
    int sub = 0;
    rep(i, 0, m) {
        int ad = audio[i];
        int ppl = mp[audio[i]];
        int subppl = mp[subtitles[i]];

        if (ppl > maxFreq) {
            // select this movie
            movie = i;
            maxFreq = ppl;
            sub = subppl;
        } else if (ppl == maxFreq) {
            // check subtitle
            if (subppl > sub) {
                sub = subppl;
                movie = i;
            }
        }
    }

    if (movie == -1) {
        cout << 1;
        return;
    }

    cout << movie + 1;
}

int main() {
    fastio;

    int n;
    cin >> n;

    vi arr(n);
    rep(i, 0, n) {
        cin >> arr[i];
    }

    int m;
    cin >> m;
    vi audio(m);
    rep(i, 0, m) {
        cin >> audio[i];
    }

    vi subtitles(m);
    rep(i, 0, m) {
        cin >> subtitles[i];
    }

    solve(arr, audio, subtitles, n, m);

    return 0;
}