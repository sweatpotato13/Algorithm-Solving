#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://codeforces.com/contest/1353/problem/C
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        n = (n-1)/2;
        ll ans = 0;
        ans = (n*(n+1)*(2*n+1)/6) * 8;
        cout << ans << endl;
    }
 
   return 0;
}
