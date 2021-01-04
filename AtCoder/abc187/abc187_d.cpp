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
// https://atcoder.jp/contests/abc187/tasks/abc187_d
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vll x(n);
    ll temp = 0;
    ll ans = 0;
    rep(i,n){
        ll a,b;
        cin >> a >> b;
        temp -= a;
        x[i] = a+a+b;
    }
    sort(all(x));
    while(temp <= 0){
        temp += x.back();
        x.pop_back();
        ans++;
    }
    cout << ans;

    return 0;
}