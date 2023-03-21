#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// https://www.acmicpc.net/problem/10826
string dp[10001] = {"0", "1", "1", "2", "3", "5", "8", "13", "21", "34", "55", };
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;
	cin >> n;
	for(int i = 11;i<=n;i++){
		if(dp[i-1].length() != dp[i-2].length()){
			reverse(all(dp[i-2]));
			dp[i-2] += '0';
			reverse(all(dp[i-2]));
		}
		ll len = dp[i-2].length();
		ll carry = 0;
		dp[i] = "";
		
		for(int j = len-1;j>=0;j--){
			ll a = dp[i-1][j] - '0';
			ll b = dp[i-2][j] - '0';
			ll val = a+b+carry;
			carry = val/10;
			char v = (val%10)+'0';
			dp[i] += v;
		}
		if (carry > 0)
			dp[i] += '1';
		reverse(all(dp[i]));
	}
	cout << dp[n];
	return 0;
}