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
// https://codeforces.com/problemset/problem/148/A
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll k,l,m,n,d;
    cin >> k >> l >> m >> n >> d;
    ll ans = 0;
    for(int i = 1;i<=d;i++){
        if(i%k == 0 || i%l == 0 || i%m == 0 || i%n==0){
            ans++;
        }
    }
    cout << ans;
    

    return 0;
}


