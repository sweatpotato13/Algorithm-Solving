#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://acmicpc.net/problem/9375
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		map<string, int> cloth;
		int n;
		cin >> n;
		for(int i = 0;i<n;i++){
			string name, type;
			cin >> name >> type;
			cloth[type]++;
		}
		map<string, int>::iterator iter;
		vector<int> v;
		for(iter = cloth.begin();iter != cloth.end();iter++){
			v.push_back(iter->second);
		}
		int ans = 1;
		for(int i = 0;i<v.size();i++){
			ans *= (v[i]+1);
		}
		cout << ans - 1 << "\n";
	}

}