#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll, ll, ll> tl3;
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define rep(i, n) FOR(i, 0, n)
#define repn(i, n) FORN(i, 1, n)
#define tc(t) while (t--)
// https://atcoder.jp/contests/abc221/tasks/abc221_b
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s,t;
    cin >> s >> t;

    string ans = "No";
    if(s == t){
        cout << "Yes";
        return 0;
    }
    for(int i = 0; i<s.length();i++){
        if(i > 0){
            swap(s[i],s[i-1]);
            if(s == t){
                ans = "Yes";
            }
            swap(s[i],s[i-1]);
        }
        if(i < s.length()){
            swap(s[i], s[i+1]);
            if(s == t){
                ans = "Yes";
            }
            swap(s[i], s[i+1]);
        }
    }
    cout << ans;

    return 0;
}