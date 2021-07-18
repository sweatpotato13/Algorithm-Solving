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
// https://atcoder.jp/contests/abc203/tasks/abc203_d
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,k;
    cin >> n >> k;
    map<ll,ll> m;
    rep(i,n){
        ll a,b;
        cin >> a >> b;
        m[a] += b;
    }
    ll ans = 0;
    for(auto iter:m){
        if(iter.first - ans <= k){
            ans += iter.first;
            k -= iter.first;
            k += iter.second;
        }
        else{
            ans += k;
            k = 0;
            break;
        }
    }
    ans += k;
    cout << ans;

    return 0;
}