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
// https://atcoder.jp/contests/abc198/tasks/abc198_c
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll r,x,y;
    cin >> r >> x >> y;
    ll len = x*x + y*y;
    ll ans = 0;
    if(len == r*r) cout << 1;
    else if(len < r*r) cout << 2;
    else{
        while(r*r*ans*ans<len){
            ans++;
        }
        cout << ans;
    }

    return 0;
}
