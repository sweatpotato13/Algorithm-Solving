#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// https://acmicpc.net/problem/9655
ll dp[1001] = {0,};
string ans[2] = {"CY","SK"};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;
	cin >> n;
	cout << ans[n%2];

	return 0;
}