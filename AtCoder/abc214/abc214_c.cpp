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
// https://atcoder.jp/contests/abc214/tasks/abc214_c
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vll s(n), t(n);
    rep(i, n) cin >> s[i];
    rep(i, n) cin >> t[i];
    vll ans = t;
    for(int i = 0;i<2*n;i++){
        ans[(i+1)%n] = min(ans[(i+1)%n], ans[i%n] + s[i%n]);
    }
    for(auto k : ans){
        cout << k << "\n";
    }

    return 0;
}