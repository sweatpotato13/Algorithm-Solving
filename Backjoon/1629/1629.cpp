#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/1629
ll a,b,c;
ll solve(ll x , ll y){
	if(y == 0) return 1;
	else if(y == 1) return x;
	else{
		if(y%2) return solve(x, y-1)*x;
	}
	ll e = solve(x, y/2) % c;
	return (e*e) %c;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll ans = 0;
	cin >> a >> b >> c;

	cout << solve(a,b) % c << "\n";

	return 0;
}