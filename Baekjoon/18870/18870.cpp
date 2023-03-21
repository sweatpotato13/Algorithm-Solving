#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
//https://www.acmicpc.net/problem/18870
int pt[1000001] ={0,};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	set<int> arr;
	for(int i = 0;i<n;i++){
		int e;
		cin >> e;
		pt[i] = e;
		arr.insert(e);
	}
	int cnt = 0;
	unordered_map<int, int> um;
	set<int>::iterator iter;
	for(iter = arr.begin();iter != arr.end();iter++){
		um[*iter] = cnt++;
	}
	for(int i = 0;i<n;i++){
		cout << um[pt[i]] << " ";
	}

	

	return 0;
}