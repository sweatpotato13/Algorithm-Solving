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
// https://atcoder.jp/contests/abc208/tasks/abc208_b
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll p;
    cin >> p;
    ll facto[11] = {0,};
    facto[1] = 1;
    for(ll i = 2;i<11;i++){
        facto[i] = facto[i-1]*i;
    }
    ll ans = 0;
    for(ll i = 10;i>=1;i--){
        while(p >= facto[i]){
            p -= facto[i];
            ans++;
        }
    }
    cout << ans;

    return 0;
}