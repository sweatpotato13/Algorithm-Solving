#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://codeforces.com/contest/1374/problem/A
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while(t--){
        ll k;
        ll x,y,n;
        cin >> x >> y >> n;
        if(n%x >= y)
            k = n - (n%x-y);
        else
            k = n - n%x - x + y;
        cout << k << "\n";
    }
    
	return 0;
}
