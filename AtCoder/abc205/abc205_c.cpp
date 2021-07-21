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
// https://atcoder.jp/contests/abc205/tasks/abc205_c
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a,b,c;
    cin >> a >> b >> c;
    if(c == 0){
        cout << "=";
    }
    else if(c > 0){
        if(c % 2 == 0){
            if(a < 0) a *= -1;
            if(b < 0) b *= -1;
        }
        if(a < b) cout << "<";
        else if(a > b) cout << ">";
        else cout << "=";
    }

    return 0;
}