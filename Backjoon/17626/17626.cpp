#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
int dp[50001]={0,};
// https://www.acmicpc.net/problem/17626
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int i;
	int n;
	cin >> n;
	vector<int> v(227);
	for(int i = 0;i<227;i++)
		v.push_back(i*i);
	for(int i = 0;i<=n;i++){
		dp[i] = 2100000000;
	}		
	dp[0] = 0;
	dp[1] = 1;
	for(int i = 2;i<=n;i++){
		int min = 2100000000;
		for(int j = 0;v[j]<=i;j++){
			min = std::min(min, dp[i-v[j]]);
		}
		dp[i] = min+1;
	}
	cout << dp[n] << "\n";

	return 0;
}
