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
// http://codeforces.com/problemset/problem/248/A
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    ll l0 = 0, l1 = 0, r0 = 0, r1 = 0;
    rep(i, n) {
        ll l,r;
        cin >> l >> r;
        if(l) l1++;
        else l0++;
        if(r) r1++;
        else r0++;
    }
    cout << min(l0,l1) + min(r0,r1);

    return 0;
}