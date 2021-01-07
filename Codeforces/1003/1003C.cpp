#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://codeforces.com/contest/1003/problem/C
double dp[5001]={0,};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	ll n, k;
	cin >> n >> k;
	vector<ll> v(n);
	double ans = 0;
	for(int i = 0;i<n;i++){
		cin >> v[i];
	}
	dp[0] = 0;
	for(int i = 1;i<=n;i++){
		dp[i] = dp[i-1] + v[i-1];
	}
	for(int i = 0;i<n;i++){
		double sum = 0;
		for(int j = 0;j<i+1;j++){
			if(i-j+1 >= k){
				sum = (dp[i+1] - dp[j]) / (double)(i-j+1);
			}
			if(sum > ans)
				ans = sum;
		}
	}
	cout.precision(15);
	cout << ans << "\n";

    return 0;
}
