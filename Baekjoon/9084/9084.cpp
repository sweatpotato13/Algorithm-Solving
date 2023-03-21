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
// https://www.acmicpc.net/problem/9084
ll dp[21][10101] = {0,};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    tc(t){
        ll n;
        cin >> n;
        vll v(n);
        rep(i,n) cin >> v[i];
        ll m;
        cin >> m;
        rep(i,v.size()){
            repn(j,m){
                if(j < v[i]) dp[i+1][j] = dp[i][j];
                else if(j == v[i]) dp[i+1][j] = dp[i][j] + 1;
                else dp[i+1][j] = dp[i][j] + dp[i+1][j-v[i]];
            }
        }
        cout << dp[v.size()][m] << "\n";
    }


    return 0;
}
