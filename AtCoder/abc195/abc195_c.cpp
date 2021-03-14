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
// https://atcoder.jp/contests/abc195/tasks/abc195_c
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    ll n;
    cin >> n;
    ll ans = 0;
    ll temp = 0;
    for(int i = 0;temp <= n;i++){
        ll prevTemp = temp;
        temp = temp * 10 + 9;
        if(temp <= n){
            ans += (i/3) * (temp - prevTemp);
        }
        else{
            ans += (i/3) * (n - prevTemp);
        }
    }
    cout << ans;

    return 0;
}
