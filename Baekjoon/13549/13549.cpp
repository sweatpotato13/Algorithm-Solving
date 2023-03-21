#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://www.acmicpc.net/problem/13549
ll dp[100001]={0,};
ll n, k;
void BFS(){
	queue<ll> q;
	q.push(n);
	dp[n] = 0;
	while(!q.empty()){
		ll e = q.front();
		q.pop();
		if(e == k) return;
		if(e + 1 < 100001 && dp[e+1] > dp[e]+1){
			dp[e+1] = dp[e]+1;
			q.push(e+1);
		}
		if(e - 1 >= 0 && dp[e-1] > dp[e]+1){
			dp[e-1] = dp[e] + 1;
			q.push(e-1);
		}
		if(2*e < 100001 && dp[e*2] > dp[e]){
			dp[e*2] = dp[e];
			q.push(e*2);
		}
	}
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	cin >> n >> k;
	for(int i = 0;i<100001;i++){
		dp[i] = 100001;
	}
	BFS();
	cout << dp[k] << "\n";
    return 0;
}