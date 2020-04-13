#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/5430
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	 
	int t;
	cin >> t;
	while(t--){
		string command;
		string arr;
		int n;
		cin >> command >> n >> arr;
		deque<int> deq;
		string temp = "";
		for(int i = 0;i<arr.length();i++){
			if(arr[i] != ']' && arr[i] != '[' && arr[i] != ','){
				temp += arr[i];
			}
			else if(arr[i] == ','){
				int e = atoi(temp.c_str());
				temp = "";
				deq.push_back(e);
			}
		}
		if(arr.length() > 2)
			deq.push_back(atoi(temp.c_str()));
		bool isReversed = false;
		bool isSkip = false;
		for(int i = 0;i<command.length();i++){
			if(command[i] == 'R'){
				isReversed = !isReversed;
			}
			else if(command[i] == 'D'){
				if(deq.empty()){
					cout << "error\n";
					isSkip = true;
					goto END;
				}
				if(isReversed){
					deq.pop_back();
				}
				else{
					deq.pop_front();
				}
			}
		}
		cout << "[";
		END:;
		deque<int>::reverse_iterator riter;
		if(isSkip){

		}
		else if(isReversed){
			for(riter = deq.rbegin();riter != deq.rend();riter++){
				cout << *riter;
				if(riter != deq.rend()-1) cout << ",";
			}
		}
		else{
			for(int i = 0;i<deq.size();i++){
				cout << deq[i];
				if(i != deq.size()-1) cout << ",";
			}			
		}
		if(!isSkip){
			cout << "]\n";
		}
	}
	return 0;
}