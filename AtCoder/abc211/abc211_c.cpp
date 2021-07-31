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
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define rep(i, n) FOR(i, 0, n)
#define repn(i, n) FORN(i, 1, n)
#define tc(t) while (t--)
// https://atcoder.jp/contests/abc211/tasks/abc211_c
ll dp[101010][10] = {0,};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    string t = "chokudai";
    ll mod = 1e9 + 7;
    dp[0][0] = 1;
    for(ll i = 0;i<s.size();i++){
        for(ll j = 0;j<9;j++){
            dp[i+1][j] += dp[i][j];
            if(s[i] == t[j]) dp[i+1][j+1] += dp[i][j];
            dp[i+1][j] %= mod;
        }
    }
    cout << dp[s.length()][8];

    return 0;
}