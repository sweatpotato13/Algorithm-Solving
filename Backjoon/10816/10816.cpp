#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/10816
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	map<int,int> card;	
	while (n--) {
		int e;
		cin >> e;
		card[e]++;
	}
	int m;
	cin >> m;
	while(m--){
		int e;
		cin >> e;
		cout << card[e] << " ";
	}
	cout << "\n";
	return 0;

}