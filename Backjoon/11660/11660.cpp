#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
int board[1025][1025] = {0,};
int dp[1025][1025] = {0,};
// https://www.acmicpc.net/problem/11660
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m;
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			cin >> board[i][j];
			dp[i][j] = board[i][j] + dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
		}
	}
	for(int i = 0;i<m;i++){
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1] << "\n";
	}



	return 0;
}