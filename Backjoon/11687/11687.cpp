#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/11687
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    ll l = 1;
    ll h = n*5;
    while(l <= h){
        ll m = (l+h)/2;
        ll temp = 0;
        ll mm = m;
        while(mm >= 5){
            temp += mm/5;
            if(temp > n){
                break;
            }
            mm /= 5;
        }
        if(temp < n) l = m+1;
        else h = m-1;
    }
    ll temp = 0;
    ll mm = l;
    while(mm >= 5){
        temp += mm /5;
        mm /= 5;
    }
    if(temp == n) cout << l;
    else cout << -1;
     
    return 0;
}
