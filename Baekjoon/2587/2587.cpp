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
// https://www.acmicpc.net/problem/2587
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 5;
    ll avg = 0;
    vll v(5);
    tc(t){
        ll e;
	cin >> e;
	v[t] = e;
        avg += e;
    }
    sort(all(v));
    avg /= 5;
    cout << avg << " " << v[2];
    return 0;
}