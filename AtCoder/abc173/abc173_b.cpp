#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://atcoder.jp/contests/abc173/tasks/abc173_b
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string ans[4] ={"AC","WA","TLE","RE"};
    ll n;
    cin >> n;
    map<string, ll> m;
    for(int i = 0;i<n;i++){
        string s;
        cin >> s;
        m[s]++;
    }
    for(auto k : ans){
        cout << k << " x " << m[k] << "\n";
    }
    

	return 0;
}
