#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
#define mod 1000000009
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// https://www.acmicpc.net/submit/15990
ll dp[100001][4];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
	for(int i = 4;i<=100000;i++){
		dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % mod;
		dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % mod;
		dp[i][3] = (dp[i-3][2] + dp[i-3][1]) % mod;
	}
	ll t;
	cin >> t;
	while(t--){
		ll e;
		cin >> e;
		cout << (dp[e][1]+dp[e][2]+dp[e][3])%mod << "\n";
	}

	return 0;
}