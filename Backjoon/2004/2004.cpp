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
// https://www.acmicpc.net/problem/2004
ll count_five(ll n){
    ll res = 0;
    for(ll i = 5;n/i >= 1;i*=5){
        res += (n/i);
    }
    return res;
}
ll count_two(ll n){
    ll res = 0;
    for(ll i = 2;n/i >= 1;i*=2){
        res += (n/i);
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;
    cin >> n >> m;

    ll a = count_five(n);
    if(m) a -= count_five(m);
    if(n!=m) a -= count_five(n-m);

    ll b = count_two(n);
    if(m) b -= count_two(m);
    if(n!=m) b -= count_two(n-m);

    cout << min(a,b);

    return 0;
}
