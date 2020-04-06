#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://codeforces.com/contest/1328/problem/C
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		string a,b;
		bool isVisitedOne = false;
		for(int i = 0;i<n;i++){
			if(s[i] == '0'){
				a.append("0");
				b.append("0");
			}
			else if(s[i] == '1'){
				if(isVisitedOne){
					a.append("0");
					b.append("1");
				}
				else{
					a.append("1");
					b.append("0");	
					isVisitedOne = true;				
				}
			}
			else{
				if(isVisitedOne){
					a.append("0");
					b.append("2");
				}
				else{
					a.append("1");
					b.append("1");	
				}
			}
		}
		cout << a << "\n" << b << "\n";

	}

	return 0;
}