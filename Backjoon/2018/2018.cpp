#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/2018
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ans = 0;
    ll n;
    cin >> n;
    ll l=0,r=0,res = 0;
    while(l <= r && r <= n+1){
        if(res > n){
            res -= l;
            l++;
        }
        else if(res < n){
            res += r;
            r++;
        }
        else{
            ans++;
            res += r;
            r++;
        }
    }

    cout << ans;

    return 0;
}