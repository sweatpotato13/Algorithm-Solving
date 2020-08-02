#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://atcoder.jp/contests/abc174/tasks/abc174_d
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    string s;
    cin >> n >> s;
    ll totalR = 0;
    ll baseW = 0;
    ll ans = 0;
    for(int i = 0;i<n;i++){
        if(s[i] == 'R') totalR++;
    }
    for(int i = 0;i<totalR;i++){
        if(s[i] == 'W') baseW++;
    }
    ans = baseW;
    cout << ans;
    return 0; 
}