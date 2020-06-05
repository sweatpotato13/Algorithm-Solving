#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://atcoder.jp/contests/abc167/tasks/abc167_a
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string ans[2] = {"No","Yes"};
    bool isAnswer = true;
    string s,t;
    cin >> s >> t;
    for(int i=0;i<s.length();i++){
        if(s[i] != t[i]){
            isAnswer = false;
            break;
        }
    }
    cout << ans[isAnswer];

	return 0;

}