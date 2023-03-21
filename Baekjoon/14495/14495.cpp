#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// https://www.acmicpc.net/submit/14495
ll dp[10001] = {0,1, 1, 1, 2, 3, 4, 6, 9, 13, 19,};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;
	cin >> n;
	for(int i = 11;i<=n;i++){
		dp[i] = dp[i-1] + dp[i-3];
	}

	cout << dp[n];
	return 0;
}