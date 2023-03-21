#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// https://www.acmicpc.net/problem/13699
ll dp[36] ={0,};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;
	cin >> n;
	dp[0] = 1;
	dp[1] = 1;
	for(int i = 2;i<=n;i++){
		for(int j = 0;j<=i-1;j++){
			dp[i] += (dp[j] * dp[i-1-j]);
		}
	}
	cout << dp[n];
	return 0;
}