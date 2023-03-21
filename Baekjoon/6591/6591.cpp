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
// https://www.acmicpc.net/problem/6591
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,k;
    while(true){
        cin >> n >> k;
        if(n == 0 && k == 0) break;
        ll ans = 1;
        if(k > n/2){
            k = n-k;
        }
        for(int i = 0;i<k;i++){
            ans *= n;
            ans /= (i+1);
            n--;
        }
        cout << ans << "\n";
    }

    return 0;
}