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
// https://atcoder.jp/contests/abc181/tasks/abc181_c
ll x[101];
ll y[101];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    ll ans = 0;
    rep(i, n)
    {
        cin >> x[i] >> y[i];
    }
    for (ll i = 0; i < n - 2; i++) {
        for (ll j = i+1; j < n - 1; j++) {
            for (ll k = j+1; k < n; k++) {
                ll a, b, c, d;
                a = x[j] - x[i];
                b = x[k] - x[j];
                c = y[j] - y[i];
                d = y[k] - y[j];
                if(a*d == b*c){
                    cout << "Yes";
                    return 0;
                }
            }
        }
    }
    cout << "No";

    return 0;
}
