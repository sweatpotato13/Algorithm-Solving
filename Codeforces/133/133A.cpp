#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://codeforces.com/problemset/problem/133/A
string ans[2] = {"NO", "YES"};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    bool isAnswer = false;
    string s;
    cin >> s;
    for(int i = 0;i<s.length();i++){
        if(s[i] == 'H' || s[i] == 'Q' || s[i] == '9'){
            isAnswer = true;
        }
    }
    cout << ans[isAnswer];
	return 0;

}