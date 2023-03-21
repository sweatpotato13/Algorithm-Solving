#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/12849
ll dp[8][100001]={0,};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll mod = 1e9+7;
    ll ans = 1;
    ll n;
    cin >> n;

    dp[0][0] = 1;
    for(int i = 0;i<=n;i++){
        dp[0][i+1] = (dp[1][i] + dp[2][i]) % mod;
        dp[1][i+1] = (dp[0][i] + dp[2][i] + dp[3][i]) % mod;
        dp[2][i+1] = (dp[0][i] + dp[1][i] + dp[3][i] + dp[4][i]) % mod;
        dp[3][i+1] = (dp[1][i] + dp[2][i] + dp[4][i] + dp[5][i]) % mod;
        dp[4][i+1] = (dp[2][i] + dp[3][i] + dp[5][i] + dp[7][i]) % mod;
        dp[5][i+1] = (dp[3][i] + dp[4][i] + dp[6][i]) % mod;
        dp[6][i+1] = (dp[5][i] + dp[7][i]) % mod;
        dp[7][i+1] = (dp[4][i] + dp[6][i]) % mod;
    }
    cout << dp[0][n];


	return 0;
}