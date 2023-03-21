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
// https://www.acmicpc.net/problem/10422
ll dp[5001] ={0,};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    const ll mod = 1e9+7;
    dp[0] = 1;
    dp[2] = 1;
    dp[4] = 2;
    for(int i = 6;i<=5000;i+=2){
        for(int j = i-2;j>=0;j-=2){
            dp[i] += (dp[j] * dp[i-j-2]);
            dp[i] %= mod;
        }
    }
    ll t;
    cin >> t;
    tc(t){
        ll l;
        cin >> l;
        cout << dp[l] << "\n";
    }
    
    return 0;
}
