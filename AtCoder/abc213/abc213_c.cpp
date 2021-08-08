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
// https://atcoder.jp/contests/abc213/tasks/abc213_c
bool sortbysec(const tl3& a, const tl3& b) { return (get<1>(a) < get<1>(b)); }
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll h, w, n;
    cin >> h >> w >> n;
    vector<tl3> a;
    vector<tl3> b;
    for (ll i = 1; i <= n; i++) {
        ll ta, tb;
        cin >> ta >> tb;
        a.push_back(make_tuple(ta, i, 0));
        b.push_back(make_tuple(tb, i, 0));
    }
    sort(all(a));
    sort(all(b));
    ll rep = 0;
    for(ll i = 0;i<n;i++) {
        if(i == 0) a[i] = make_tuple(get<0>(a[i]), get<1>(a[i]), i+1);
        else if(i != 0 && get<0>(a[i]) == get<0>(a[i-1])) {
            a[i] = make_tuple(get<0>(a[i]), get<1>(a[i]), get<2>(a[i-1]));
            rep++;
        }
        else a[i] = make_tuple(get<0>(a[i]), get<1>(a[i]), i+1-rep);  
    }
    rep = 0;
    for(ll i = 0;i<n;i++) {
        if(i == 0) b[i] = make_tuple(get<0>(b[i]), get<1>(b[i]), i+1);
        else if(i != 0 && get<0>(b[i]) == get<0>(b[i-1])) {
            b[i] = make_tuple(get<0>(b[i]), get<1>(b[i]), get<2>(b[i-1]));
            rep++;
        }
        else b[i] = make_tuple(get<0>(b[i]), get<1>(b[i]), i+1-rep);  
    }
    sort(all(a), sortbysec);
    sort(all(b), sortbysec);
    rep(i, n) { cout << get<2>(a[i]) << " " << get<2>(b[i]) << "\n"; }

    return 0;
}