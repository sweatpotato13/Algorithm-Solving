#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/14444
ll a[202020] ={0,};
void manachers(string s){
    ll r = 0, p = 0;
    for (int i = 0; i < s.length(); i++){
        if (i <= r)
            a[i] = min(a[2 * p - i], r - i);
        else
            a[i] = 0;
        while (i - a[i] - 1 >= 0 && i + a[i] + 1 < s.length() && s[i - a[i] - 1] == s[i + a[i] + 1])
            a[i]++;
        if (r < i + a[i]){
            r = i + a[i];
            p = i;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string temp = "";
    cin >> temp;
    string s = "";
    for(auto k : temp){
        s += '#';
        s += k;
    }
    s += "#";
    manachers(s);
    ll ans = 0;
    for(int i = 0;i<s.length();i++){
        ans = max(ans, a[i]);
    }
    cout << ans;

    return 0;
}
