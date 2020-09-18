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
// https://www.acmicpc.net/problem/2525
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll h,m,c;
    cin >> h >> m >> c;

    h += c/60;
    m += c%60;
    if(m >= 60){
        h++;
        m %= 60;
    }
    if(h >= 24){
        h %= 24;
    }
    cout << h << " " << m;

    return 0;
}
