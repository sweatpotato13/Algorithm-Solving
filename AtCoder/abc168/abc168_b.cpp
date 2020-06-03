#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://atcoder.jp/contests/abc168/tasks/abc168_b
string ans[3] = {"hon","pon","bon"};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	ll k;
	string s;
	cin >> k >> s;
	if(s.length() <= k){
		cout << s;
	}
	else{
		for(int i = 0;i<k;i++){
			cout << s[i];
		}
		cout << "...";
	}

    return 0;
}