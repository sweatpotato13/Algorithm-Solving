#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://atcoder.jp/contests/abc177/tasks/abc177_b
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s,t;
    cin >> s >> t;
    ll lens = s.length();
    ll lent = t.length();
    ll ans = lent+1;
    for(int i = 0;i<lens-lent+1;i++){
        ll temp = 0;
        for(int j = 0;j<lent;j++){
            if(s[i+j] != t[j]) temp++;
        }
        ans = min(ans, temp);
    }
    cout << ans;
    return 0;
}


