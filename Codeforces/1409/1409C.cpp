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
// http://codeforces.com/problemset/problem/1409/C
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll n,x,y;
        cin >> n >> x >> y;
        ll d = y-x;
        for(int i = 1;i<=d;i++){
            if(d % i) continue;
            if(d/i+1 > n) continue;
            ll k = min((y-1)/i,n-1);
            ll a0 = y-k*i;
            for(int j=0;j<n;j++){
                cout << a0 + i * j << " ";
            }
            cout << "\n";
            break;
        }
    }


    return 0;
}