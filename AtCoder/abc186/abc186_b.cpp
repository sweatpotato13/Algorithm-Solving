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
// https://atcoder.jp/contests/abc186/tasks/abc186_b
ll a[101][101] ={0,};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll h,w;
    cin >> h >> w;
    ll low = 101 , high = -1;
    for(int i = 0;i<h;i++){
        for(int j = 0;j<w;j++){
            cin >> a[i][j];
            low = min(low, a[i][j]);
            high = max(high,a[i][j]);
        }
    }
    ll ans = 0;
    for(int i = 0;i<h;i++){
        for(int j = 0;j<w;j++){
            ans += (a[i][j] - low);
        }
    }
    cout << ans;

    return 0;
}