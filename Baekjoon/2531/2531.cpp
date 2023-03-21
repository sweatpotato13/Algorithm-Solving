#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://acmicpc.net/problem/2531
ll dishes[3001] = {0,};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ans = 0;
    ll cur = 0;
    ll n,d,k,c;
    cin >> n >> d >> k >> c;
    vector<ll> v(2*n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
        v[n+i] = v[i];
    }
    dishes[c]++;
    cur++;
    for(int i = 0;i<k-1;i++){
        if(!dishes[v[i]]) 
            cur++;
        dishes[v[i]]++;
    }

    for(int i = 0;i<n;i++){
        if(!dishes[v[i+k-1]]) 
            cur++;
        dishes[v[i+k-1]]++;
        ans = max(ans, cur);
        dishes[v[i]]--;
        if(!dishes[v[i]]) 
            cur--;
    } 
    cout << ans;

    return 0;
}