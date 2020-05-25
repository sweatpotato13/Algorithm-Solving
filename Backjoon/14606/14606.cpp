#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// https://www.acmicpc.net/problem/14606
ll dp[11] ={0,};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;
	cin >> n;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 3;
	dp[4] = 6;
	dp[5] = 10;
	for(int i = 6;i<=n;i++){
		dp[i] = dp[i-1]+i-1;
	}
	cout << dp[n];

	return 0;
}