#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/2749
#define MOD 1000000
int dp[1500001] = {0,1,1,2,3,5,};	//150만 주기로 반복
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;
	cin >> n;
	for(int i = 5;i<=1500000;i++){
		dp[i] = (dp[i-1]+dp[i-2]) % MOD;
	}
	cout << dp[n%1500000];

	return 0;
}