#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// https://www.acmicpc.net/problem/1557
vector<ll> v;
ll mobius[1010100]={0,};
ll n;
ll solve(ll n){
    ll val = 0;
    for(ll i = 1; i*i <= n; i++){
        val += (mobius[i] * (n/(i*i)));
    }
    return val;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(ll i = 1;i<=1000000;i++){    //u(1) = 1
        mobius[i] = 1;
    }
    for(ll i = 2;i*i<=1000000;i++){
        if(mobius[i] == 1){
            for(int j = i;j<=1000000;j+=i){
                mobius[j] *= -i;
            }
            for(int j = i*i;j<=1000000;j += i*i){
                mobius[j] = 0;
            }
        }
    }
    for(ll i = 2;i<=1000000;i++){
        if(mobius[i] == i){
            mobius[i] = 1;
        }
        else if(mobius[i] == -i){
            mobius[i] = -1;
        }
        else if(mobius[i] > 0){
            mobius[i] = -1;
        }
        else if(mobius[i] < 0){
            mobius[i] = 1;
        }
    }
    ll l = 0;
    ll h = 1e12;
    while(l + 1 < h){
        ll mid = (l+h)/2;
        if(solve(mid) < n){
            l = mid;
        }
        else{
            h = mid;
        }
    }
    cout << h << "\n";

    return 0;
}
