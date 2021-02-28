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
// https://atcoder.jp/contests/abc192/tasks/abc192_c
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,k;
    cin >> n >> k;
    ll a = n;
    rep(i,k){
        vll g;
        while(a){
            ll temp = a%10;
            g.push_back(temp);
            a /= 10;
        }
        sort(all(g));
        ll g1 = 0, g2 = 0;
        for(int j = 0;j<g.size();j++){
            g1 += g[j] * pow(10,j);
        }
        reverse(all(g));
        for(int j = 0;j<g.size();j++){
            g2 += g[j] * pow(10,j);
        }
        a = g1 - g2;
        if(a == 0) break;
    }
    cout << a;

    return 0;
}
