#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/12852
int dp[1000001] ={0,};
vector<int> v;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,ans;
	cin >> n;
	ans = n;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	for(int i = 4;i<=n;i++){
		dp[i] = dp[i-1]+1;
		if(i % 3 == 0)
			dp[i] = min(dp[i], dp[i/3] + 1);
		if(i % 2 == 0)
			dp[i] = min(dp[i], dp[i/2] + 1);
	}
	v.push_back(n);
	int idx = 1;
	while(n != 1){
		int temp;
		v.push_back(0);
		if(dp[n-1] + 1 == dp[n]){
			v[idx] = n-1;
			temp = n-1;
		}
		if(n % 2 == 0 && dp[n/2] + 1 == dp[n]){
			v[idx] = n/2;
			temp = n/2;
		}
		if(n % 3 == 0 && dp[n/3] + 1 == dp[n]){
			v[idx] = n/3;
			temp = n/3;
		}
		idx++;
		n = temp;
	}
	cout << dp[ans] << "\n";
	for(int i = 0;i<v.size();i++){
		cout << v[i] << " ";
	}
	return 0;
}