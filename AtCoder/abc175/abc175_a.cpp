#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://atcoder.jp/contests/abc175/tasks/abc175_a
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    ll ans = 0;
    ll temp = 0;
    for(int i = 0;i<s.length();i++){
        if(s[i] == 'R'){
            temp++;
        }
        else{
            ans = max(ans, temp);
            temp = 0;
        }
    }
    ans = max(ans,temp);
    cout << ans;

    return 0;
}

