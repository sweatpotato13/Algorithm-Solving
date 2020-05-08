#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://codeforces.com/contest/1003/problem/B
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	string ans = "";
	ll a,b,x;
	cin >> a >> b >> x;
	if(x % 2 == 0){
		if(a > b){
			for(int i = 0;i<x/2;i++) ans += "01";
			for(int i = 0;i<b-x/2;i++) ans += "1";
			for(int i = 0;i<a-x/2;i++) ans += "0";
		}
		else{
			for(int i = 0;i<x/2;i++) ans += "10";
			for(int i = 0;i<a-x/2;i++) ans += "0";
			for(int i = 0;i<b-x/2;i++) ans += "1";
		}
	}
	else{
		if(a>b){
			for(int i = 0;i<x/2;i++) ans += "01";
			for(int i = 0;i<a-x/2;i++) ans += "0";
			for(int i = 0;i<b-x/2;i++) ans += "1";
		}
		else{
			for(int i = 0;i<x/2;i++) ans += "10";
			for(int i = 0;i<b-x/2;i++) ans += "1";
			for(int i = 0;i<a-x/2;i++) ans += "0";	
		}
	}
	cout << ans << "\n";
    return 0;
}
