#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/15988
ll dp[1000001] ={0,};
ll mod = 1e9+9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4;i<=1000000;i++){
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % mod;
    }
    ll t;
    cin >> t;
    while(t--){
        ll e;
        cin >> e;
        cout << dp[e] << "\n";
    }

    return 0;
}
