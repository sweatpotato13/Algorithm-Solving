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
// https://atcoder.jp/contests/abc187/tasks/abc187_b
ld slope(ll x1, ll y1, ll x2, ll y2){
    return (ld)(y1-y2)/(ld)(x1-x2);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vll x(n);
    vll y(n);
    ll ans = 0;
    rep(i,n) cin >> x[i] >> y[i];
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            ld temp = slope(x[i],y[i],x[j],y[j]);
            if(temp >= -1 && temp <= 1) ans++;
        }
    }
    cout << ans;

    return 0;
}