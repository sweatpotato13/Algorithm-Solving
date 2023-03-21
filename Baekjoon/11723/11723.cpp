#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
int v[21] = {0,};
//https://www.acmicpc.net/problem/11723
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	while(n--){
		string s;
		cin >> s;
		if(!s.compare("add")){
			int e;
			cin >> e;
			v[e] = 1;
		}
		else if(!s.compare("remove")){
			int e;
			cin >> e;
			v[e] = 0;	
		}
		else if(!s.compare("check")){
			int e;
			cin >> e;
			cout << v[e] << "\n";
		}
		else if(!s.compare("toggle")){
			int e;
			cin >> e;
			if(v[e]) v[e] = 0;
			else v[e] = 1;
		}
		else if(!s.compare("all")){
			for(int i = 0;i<21;i++)
				v[i] = 1;
		}
		else if(!s.compare("empty")){
			memset(v,0,sizeof(v));
		}
	}
	return 0;

}