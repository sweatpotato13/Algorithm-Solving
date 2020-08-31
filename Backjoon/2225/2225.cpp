#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/2225
ll MOD = 1e9;
ll dp[201][201] = {0,};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,k;
    cin >> n >> k;
    for(int i = 0;i<=n;i++)
        dp[i][1] = 1;
    for(int i = 0;i<=k;i++){
        dp[0][i] = 1;
    }
    for(int i = 2; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            dp[j][i] = (dp[j-1][i] + dp[j][i-1]) % MOD;
        }
    }

    cout << dp[n][k];


    return 0;
}
