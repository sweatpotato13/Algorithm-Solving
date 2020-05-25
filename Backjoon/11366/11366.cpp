#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// https://acmicpc.net/problem/11366
ll fibo[100] ={0,};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	fibo[1] = 1;
	fibo[2] = 1;
	for(int i = 3;i<100;i++){
		fibo[i] = fibo[i-1] + fibo[i-2];
	}
	ll a,b,c;
	while(true){
		cin >> a >> b >> c;
		if(a == 0 && b== 0 && c == 0){
			break;
		}
		if(a == 0 && b == 0) cout << 0 << "\n";
		else{
			ll ans = a*fibo[c] + b*fibo[c+1];
			cout << ans << "\n";
		}
	}

	return 0;
}