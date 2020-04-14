#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/2407
struct bigInt{
	ll high;
	ll low;
};
bigInt dp[101][101] ={0,};
ll mod = 1e15;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll n,m;
	cin >> n >> m;
	dp[0][0].high = 0;
	dp[0][0].low = 1;
	dp[1][0].high = 0;
	dp[1][0].low = 1;
	dp[1][1].high = 0;
	dp[1][1].low = 1;
	for(ll i = 2;i<=n;i++){
		for(ll j = 0;j<=i;j++){
			if(j == 0 || i == j){
				dp[i][j].high = 0;
				dp[i][j].low = 1;
			}
			else {
				dp[i][j].low = dp[i-1][j-1].low + dp[i-1][j].low;
				if(dp[i][j].low >= mod){
					dp[i][j].low -= mod;
					dp[i][j].high++;
				}
				dp[i][j].high = dp[i][j].high + dp[i-1][j-1].high + dp[i-1][j].high;
			}
		}
	}
	if(dp[n][m].high == 0){
		cout << dp[n][m].low << "\n";
	}
	else{
		cout << dp[n][m].high;
		cout.width(15);
		cout.fill('0');
		cout << dp[n][m].low << "\n";
	}
	
	return 0;
}