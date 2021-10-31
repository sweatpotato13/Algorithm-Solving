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
#define X first
#define Y second
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define rep(i, n) FOR(i, 0, n)
#define repn(i, n) FORN(i, 1, n)
#define tc(t) while (t--)
// https://atcoder.jp/contests/abc220/tasks/abc220_b
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll k;
    cin >> k;
    string a, b;
    cin >> a >> b;
    reverse(all(a));
    reverse(all(b));
    ll ia = 0,ib = 0;
    ll base = 1;
    for(int i =0;i<a.length();i++){
        ia += (a[i]-'0')*base;
        base *= k;
    }
    base = 1;
    for(int i =0;i<b.length();i++){
        ib += (b[i]-'0')*base;
        base *= k;
    }
    cout << ia * ib;

    return 0;
}
