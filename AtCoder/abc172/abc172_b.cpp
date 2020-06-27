#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://atcoder.jp/contests/abc172/tasks/abc172_b
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ans = 0;
    string s,t;
    cin >> s >> t;
    ll n = s.length();
    for(int i = 0;i<n;i++){
        if(s[i] != t[i]) ans++;
    }
    cout << ans;

	return 0;
}