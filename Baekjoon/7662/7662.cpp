#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/7662
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		multiset<int, greater<int>> s;
		multiset<int, greater<int>>::iterator iter;
		int k;
		cin >> k;
		while(k--){
			string command;
			int e;
			cin >> command >> e;
			if(!command.compare("I")){
				s.insert(e);
			}
			else{
				if(s.empty()) continue;
				if(e == 1){
					iter = s.begin();
				}
				else{
					iter = --s.end();
				}
				s.erase(iter);
			}
		}
		if(s.empty()) cout << "EMPTY\n";
		else{
			iter = s.begin();
			cout << *iter << " ";
			iter = --s.end();
			cout << *iter << "\n";
		}
	}

}