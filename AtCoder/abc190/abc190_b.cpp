#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll, ll, ll> tl3;
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define rep(i, n) FOR(i, 0, n)
#define repn(i, n) FORN(i, 1, n)
#define tc(t) while (t--)
string ans[2] = {"No", "Yes"};
// https://atcoder.jp/contests/abc190/tasks/abc190_b
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,s,d;
    cin >> n >> s >> d;
    vll x(n), y(n);
    ll isPossible = false;
    rep(i,n) cin >> x[i] >> y[i];
    rep(i,n){
        if(x[i] < s && y[i] > d) isPossible = true;
    }
    cout << ans[isPossible];

    return 0;
}