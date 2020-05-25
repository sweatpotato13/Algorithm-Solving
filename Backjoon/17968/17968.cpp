#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll dp[1001] ={1,1,0,};
// https://acmicpc.net/problem/17968
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;
	cin >> n;	
	for(int i = 2;i<=n;i++){
		ll e = 1;
		while(true){
			dp[i] = e;
			ll k = 1;
			while(true){
				if(i-2*k >= 0){
					if(dp[i]-dp[i-k] != dp[i-k]-dp[i-2*k])
						k++;
					else break;
				}
				else break;
			}
			if(i-2*k >= 0) e++;
			else break;
		}
	}

	cout << dp[n];
	return 0;
}