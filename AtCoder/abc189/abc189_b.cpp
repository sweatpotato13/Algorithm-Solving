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
// https://atcoder.jp/contests/abc189/tasks/abc189_b
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,x;
    cin >> n >> x;
    vll v(n), p(n);
    ll temp = 0;
    rep(i,n){
        cin >> v[i] >> p[i];
        temp += v[i] * p[i];
        if(temp > x*100){
            cout << i+1;
            return 0;
        }
    }
    cout << -1;

    return 0;
}