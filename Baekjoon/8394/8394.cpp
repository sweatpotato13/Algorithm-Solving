#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// https://acmicpc.net/problem/8394
int dp[10000001] = {0,};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;
	cin >> n;
	dp[1] = 0;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 5;
	for(int i = 5;i<=n;i++){
		dp[i] = (dp[i-1] + dp[i-2])%10;
	}
	cout << dp[n] << "\n";
	return 0;
}