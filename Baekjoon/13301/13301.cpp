#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// https://www.acmicpc.net/problem/13301
ll dp[81]={0,};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;
	cin >> n;
	dp[1] = 4;
	dp[2] = 6;
	dp[3] = 10;
	dp[4] = 16;
	for(int i = 5;i<=n;i++){
		dp[i] = dp[i-1]+dp[i-2];
	}
	cout << dp[n];
	return 0;
}