#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/14921
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ans = 1e9+9;
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    sort(all(v));
    ll l = 0;
    ll r = n-1;
    while(l < r){
        ll s = v[l] + v[r];
        if(abs(s) < abs(ans)){
            ans = s;
        }
        if(s < 0) l++;
        else r--;
    }
    
    cout << ans;

    return 0;
}