#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://codeforces.com/problemset/problem/1373/B
string ans[2] = {"NET","DA"};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        bool isAnswer = false;
        string s;
        cin >> s;
        ll ones = 0;
        ll zeros = 0;
        for(auto k : s){
            if(k == '0') zeros++;
            else ones++;
        }
        ll m = min(zeros,ones);
        if(m % 2 == 1) isAnswer = true;
        else isAnswer = false;
        cout << ans[isAnswer] << "\n";
    }
    
	return 0;
}