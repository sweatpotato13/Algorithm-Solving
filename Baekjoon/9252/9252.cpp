#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/9252
int dp[1001][1001]={0,};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string ans = "";
	string a,b;
	cin >> a >> b;
	int L1 = a.length();
	int L2 = b.length();
	for(int i = 1;i<=L1;i++){
		for(int j = 1;j<=L2;j++){
			if(b[j-1] == a[i-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				if(dp[i-1][j] < dp[i][j-1]){
					dp[i][j] = dp[i][j-1];
				}
				else{
					dp[i][j] = dp[i-1][j];
				}
			}
		}
	}
	int i = L1;
	int j = L2;
	while(dp[i][j] != 0){
		if(dp[i-1][j] == dp[i][j]){
			i--;
		}
		else if(dp[i][j-1] == dp[i][j]){
			j--;
		}
		else if(dp[i][j] - 1 == dp[i-1][j-1]){
			i--;
			j--;
			ans += a[i];
		}
	}
	cout << dp[L1][L2] << "\n";
	reverse(all(ans));
	if(dp[L1][L2] != 0){
		cout << ans << "\n";
	}

	return 0;
}