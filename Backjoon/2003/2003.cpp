#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://acmicpc.net/problem/2003
vector<ll> v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ans = 0;
    ll n,m;
    cin >> n >> m;
    v.resize(n);
    for(int i = 0;i<n;i++)
        cin >> v[i];
    ll l=0,r=0,res=0;
    while(r <= n){
        if(res < m){
            res += v[r];
            r++;
        }
        else if(res > m){
            res -= v[l];
            l++;
        }
        else{
            ans++;
            res += v[r];
            r++;
        }
    }
    cout << ans;

    return 0;
}