#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// https://www.acmicpc.net/problem/9625
ll dpA[50] ={0,};
ll dpB[50] ={0,};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;
	cin >> n;
	dpA[0] = 1;
	dpA[1] = 0;

	dpB[0] = 0;
	dpB[1] = 1;
	for(int i = 2;i<=n;i++){
		dpA[i] = dpA[i-1] + dpA[i-2];
		dpB[i] = dpB[i-1] + dpB[i-2];
	}
	cout << dpA[n] << " " << dpB[n];
	return 0;
}