#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/11404
ll n, m;
ll dp[101][101] ={0,}; 
void init(){
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(i == j) dp[i][j] = 0;
			else dp[i][j] = INT_MAX;
		}
	}
}
void print(){
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(dp[i][j] == INT_MAX) dp[i][j] = 0;
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
}
void solution(){
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			for(int k = 1;k<=n;k++){
				if(dp[j][k] > dp[j][i] + dp[i][k])
					dp[j][k] = dp[j][i] + dp[i][k];
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	init();
	for(int i = 0;i<m;i++){
		ll a,b,c;
		cin >> a >> b >> c;
		if(dp[a][b] != INT_MAX)
			dp[a][b] = min(dp[a][b],c);
		else
			dp[a][b] = c;
	}
	solution();
	print();

	return 0;
}