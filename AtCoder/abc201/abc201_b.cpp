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
// https://atcoder.jp/contests/abc201/tasks/abc201_b
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    map<ll, string> m;
    rep(i, n) {
        string s;
        ll t;
        cin >> s >> t;
        m[t] = s;
    }
    ll cnt = 0;
    string ans;
    for (auto iter = m.rbegin(); iter != m.rend(); iter++) {
        cnt++;
        if(cnt==2){
            ans = iter->second;
            break;
        }
    }
    cout << ans;

    return 0;
}