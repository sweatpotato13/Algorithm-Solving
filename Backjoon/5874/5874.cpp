#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/5874
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    vector<ll> left;
    vector<ll> right;
    for(int i = 1;i<s.length();i++){
        if(s[i] == '('){
            if(s[i-1] == '(') left.push_back(i);
        }
        else{
            if(s[i-1] == ')') right.push_back(i);
        }
    }
    ll ans = 0;
    for(int i = 0;i<left.size();i++){
        ll idx = 0;
        ll s = left[i];
        while(s > right[idx] && idx < right.size()){
            idx++;
        }
        ans += right.size()-idx;
    }
    cout << ans;


	return 0;
}
