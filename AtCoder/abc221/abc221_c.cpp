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
// https://atcoder.jp/contests/abc221/tasks/abc221_c
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    cin >> n;
    sort(all(n));
    ll ans = 0;
    do{
        for(int i=1; i<n.size(); i++){
            string l = "", r = "";
            for(int j=0; j<i; j++) l += n[j];
            for(int j=i; j<n.size(); j++) r += n[j];
            if(l[0]=='0' || r[0]=='0') continue;
            ans = max(ans,stoll(l)*stoll(r));
        }
    }while(next_permutation(n.begin(),n.end()));
    cout << ans;

    return 0;
}