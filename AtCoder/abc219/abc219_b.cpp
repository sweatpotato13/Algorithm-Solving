#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll, ll, ll> tl3;
#define X first
#define Y second
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define rep(i, n) FOR(i, 0, n)
#define repn(i, n) FORN(i, 1, n)
#define tc(t) while (t--)
// https://atcoder.jp/contests/abc219/tasks/abc219_b
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s1,s2,s3,t;
    cin >> s1 >> s2 >> s3 >> t;
    rep(i,t.length()){
        if(t[i] == '1') cout << s1;
        else if(t[i] == '2') cout << s2;
        else cout << s3;
    }

    return 0;
}

