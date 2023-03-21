#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
//https://www.acmicpc.net/problem/1764
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;
	cin >> n >> m;
	map<string, int> neverHeard;
	vector<string> v;
	for(int i = 0;i<n;i++){
		string s;
		cin >> s;
		neverHeard[s] = 1;
	}
	for(int i = 0;i<m;i++){
		string s;
		cin >> s;
		if(neverHeard[s]){
			v.push_back(s);
		}
	}
	sort(all(v));
	cout << v.size() << "\n";
	for(int i = 0;i<v.size();i++){
		cout << v[i] << "\n";
	}

	return 0;
}