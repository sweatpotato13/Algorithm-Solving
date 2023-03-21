#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/2458
int dp[501][501] ={0,};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll ans = 0;
	ll n, m;
	cin >> n >> m;
	for(int i = 0;i<m;i++){
		ll e,s;
		cin >> e >> s;
		dp[e][s] = 1;
	}
    for(int i = 1;i<=n;i++){
         for(int j = 1;j<=n;j++){
            for(int k = 1;k<=n;k++){
                if(dp[j][i] && dp[i][k])
                    dp[j][k] = 1;
            }
        }   
    }
    for(int i = 1;i<=n;i++){
        ll cnt = 0;
        for(int j = 1;j<=n;j++){
            if(i == j) continue;
            if(!dp[i][j] && !dp[j][i])
                cnt++;
        }
        if(cnt == 0) ans++;
    }
	cout << ans << "\n";
	return 0;
}