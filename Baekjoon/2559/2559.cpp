#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/2559
vector<ll> v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ans = -1e9+9;
    ll n,k;
    cin >> n >> k;
    v.resize(n);
    for(int i = 0;i<n;i++)
        cin >> v[i];
    ll l=0,r=0,res=0;
    while(r <= n){
        if(r-l < k){
            if(r == n) break;
            res += v[r];
            r++;
        }
        else if(r-l == k){
            ans = max(ans,res);
            res -= v[l];
            l++;
        }
    }
    cout << ans;

    return 0;
}