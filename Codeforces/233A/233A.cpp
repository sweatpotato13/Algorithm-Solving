#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://codeforces.com/problemset/problem/233/A
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> ans(n+1);
    if(n % 2 == 1) cout << -1;
    else{
        for(int i = 1;i<=n;i+=2){
            ans[i] = i+1;
            ans[i+1] = i;
        }
        for(int i = 1; i<=n;i++){
            cout << ans[i] << " ";
        }
    }

    return 0;
}
