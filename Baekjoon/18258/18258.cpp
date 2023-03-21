#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/18258
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	queue<int> q;
	while(n--){
		string command;
		cin >> command;
		if(!command.compare("push")){
			int e;
			cin >> e;
			q.push(e);
		}
		else if(!command.compare("pop")){
			if(q.empty()) cout << "-1\n";
			else{
				int e = q.front();
				cout << e << "\n";
				q.pop();
			}
		}
		else if(!command.compare("size")){
			cout << q.size() << "\n";
		}
		else if(!command.compare("empty")){
			if(q.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if(!command.compare("front")){
			if(q.empty()) cout << "-1\n";
			else{
				int e = q.front();
				cout << e << "\n";
			}
		}
		else if(!command.compare("back")){
			if(q.empty()) cout << "-1\n";
			else{
				int e = q.back();
				cout << e << "\n";
			}
		}
	}	

	return 0;
}