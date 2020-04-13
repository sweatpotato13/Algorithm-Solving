#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://acmicpc.net/problem/1676
int isDivisibleByFive(int n){
	int cnt = 0;
	while(n % 5 == 0){
		cnt++;
		n = n/5;
	}
	return cnt;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int ans = 0;
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++){
		if(i%5 == 0)
			ans += isDivisibleByFive(i);
	}
	cout << ans << "\n";

	return 0;
}