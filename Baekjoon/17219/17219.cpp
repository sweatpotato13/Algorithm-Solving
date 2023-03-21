#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://acmicpc.net/problem/17219
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m;
	cin >> n >> m;
	map<string, string> dictionary;
	for(int i = 0;i<n;i++){
		string web, password;
		cin >> web >> password;
		dictionary[web] = password;
	}
	for(int i = 0;i<m;i++){
		string web;
		cin >> web;
		cout << dictionary[web] << "\n";
	}


}