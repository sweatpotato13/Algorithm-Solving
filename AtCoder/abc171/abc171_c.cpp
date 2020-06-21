#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://atcoder.jp/contests/abc171/tasks/abc171_c
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string ans = "";
    ll n;
    cin >> n;
    while(n){
        ll temp = (n-1)%26;
        ans += ('a' + temp);
        n = (n-1)/26;
    }
    reverse(all(ans));
    cout << ans;

	return 0;
}
