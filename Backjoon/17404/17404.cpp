#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/17404
ll cost[1001][3] = {0,};
ll dp[1001][3] = {0,};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
    ll ans = 1e9+7;
    ll hi = 1e9+7;
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            if(i == j) dp[0][j] = cost[0][j];
            else dp[0][j] = hi;
        }
        for(int j = 1;j<n;j++){
            dp[j][0] = min(dp[j-1][1],dp[j-1][2]) + cost[j][0];
            dp[j][1] = min(dp[j-1][0],dp[j-1][2]) + cost[j][1];
            dp[j][2] = min(dp[j-1][1],dp[j-1][0]) + cost[j][2];
        }
        for(int j = 0;j<3;j++){
            if(i == j) continue;
            else ans = min(ans, dp[n-1][j]);
        }
    }
    cout << ans;
	return 0;
}