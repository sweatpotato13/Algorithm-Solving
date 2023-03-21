#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// https://www.acmicpc.net/problem/16566
vector<ll> v;
bool isVisited[4000001] ={0,};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n,m,k;
	cin >> n >> m >> k;
	v.resize(m+1);
	for(int i = 0;i<m;i++){
		cin >> v[i];
	}
	sort(all(v));
	for(int i = 0;i<k;i++){
		int e;
		cin >> e;
		int idx = upper_bound(all(v),e) - v.begin();
		while(isVisited[idx]) 
			idx++;
		isVisited[idx] = true;
		cout << v[idx] << "\n";	
	}
	return 0;
}