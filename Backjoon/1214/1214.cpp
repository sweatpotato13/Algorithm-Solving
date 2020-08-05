#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/1214
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll d,p,q;
    cin >> d >> p >> q;
    if(p < q) swap(p,q);
    if(d % p == 0 || d % q == 0 || d % (p+q) == 0){
        cout << d;
        return 0;
    }
    ll ans = (d/p)*p+p;
    ll temp = ans;
    for(int i = 1;i<=(temp/p);i++){
        ll t = temp - p*i;
        if ((d-t)%q == 0) {
            cout << d;
            return 0;
        }
        else{
            t = t + ((d-t)/q)*q+q;
        }
        if(t == ans) break;
        ans = min(ans, t);
    }
    cout << ans;
    
    return 0;
}
