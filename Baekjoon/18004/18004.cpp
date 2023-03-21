#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define rep(i, n) FOR(i, 0, n)
#define repn(i, n) FORN(i, 1, n)
#define tc(t) while (t--)
// https://www.acmicpc.net/problem/18004
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a,b;
    cin >> a >> b;
    if(a <= b){
        cout << b-a;;
    }
    else{
        ll ans = 0;
        bool flag = true;
        while(true){
            if(a == b) break;
            if(!flag) a++;
            else if(a%2 == 0){
                a /= 2;
                if(a < b) flag = false;
            }
            else{
                a++;
            }
            ans++;
        }
        cout << ans;
    }
    
    return 0;
}
