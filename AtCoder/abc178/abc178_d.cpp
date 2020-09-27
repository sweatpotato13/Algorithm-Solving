#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define rep(i, n) FOR(i, 0, n)
#define repn(i, n) FORN(i, 1, n)
#define tc(t) while (t--)
// https://atcoder.jp/contests/abc177/tasks/abc178_d
const ll mod = 1e9+7;
ll dp[2001] = {0,};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll s;
    cin >> s;
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 0;
    for(ll i = 3;i<=s;i++){
        dp[i] = (dp[i-1] + dp[i-3])%mod;
    }
    cout << dp[s];

    return 0;
}
