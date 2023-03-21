#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/15989
ll dp[10001][3] ={0,};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dp[1][0] = 1;

    dp[2][0] = 1;
    dp[2][1] = 1;

    dp[3][0] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    for(int i = 4;i<=10000;i++){
        dp[i][0] = (dp[i-1][0]);
        dp[i][1] = (dp[i-2][0] + dp[i-2][1]);
        dp[i][2] = (dp[i-3][0] + dp[i-3][1] + dp[i-3][2]);
    }
    ll t;
    cin >> t;
    while(t--){
        ll e;
        cin >> e;
        cout << dp[e][0] + dp[e][1] + dp[e][2] << "\n";
    }

    return 0;
}
