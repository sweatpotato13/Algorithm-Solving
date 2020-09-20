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
// https://www.acmicpc.net/problem/1292
ll dp[1111] ={0,};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a,b;
    cin >> a >> b;
    ll idx = 1;
    ll ans = 0;
    for(int i = 1;;i++){
        ll e = i;
        while(e--){
            dp[idx] = i;
            if(idx >= a && idx <= b) ans += i;
            idx++;
        }
        if(idx > b) break;
    }
    cout << ans;

    return 0;
}
