#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// http://codeforces.com/problemset/problem/59/A
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    bool isLower = false;
    string s;
    cin >> s;
    ll lower = 0;
    ll upper = 0;
    for(auto k : s){
        if('a' <= k && 'z' >= k){
            lower++;
        }
        else upper++;
    }
    if(lower >= upper){
        for(int i = 0;i<s.length();i++){
            s[i] = tolower(s[i]);
        }    
    }
    else{
        for(int i = 0;i<s.length();i++){
            s[i] = toupper(s[i]);
        }   
    }
    cout << s;

	return 0;
}