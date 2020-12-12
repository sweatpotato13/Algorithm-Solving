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
// https://atcoder.jp/contests/abc184/tasks/abc184_c
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll r1,c1,r2,c2;
    cin >> r1 >> c1 >> r2 >> c2;
    ll r = r2-r1;
    ll c = c2-c1;
    ll ans = 3;
    if(r == 0 && c == 0) ans = 0;
    else if(r == c || r == -c || abs(r) + abs(c) <= 3) ans = 1;
    else if((r1 + r2 + c1 + c2)%2 == 0 || abs(r + c) <= 3 || abs(r - c) <= 3 || abs(r) + abs(c) <= 6) ans = 2;
    cout << ans;
    return 0;
}