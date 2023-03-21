#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// https://www.acmicpc.net/problem/2670
double board[10001]={0,};
double dp[10001] ={0,};
double ans = -1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> board[i];
	}
	dp[1] = board[1];
	for(int i = 2;i<=n;i++){
		if(board[i] > dp[i-1] * board[i]){
			dp[i] = board[i];
		}
		else{
			dp[i] = board[i] * dp[i-1];
		}
		if(ans < dp[i])
			ans = dp[i];
	}

	cout << fixed;
	cout.precision(3);
	cout << ans;
	return 0;
}