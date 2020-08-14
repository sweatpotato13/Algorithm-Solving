#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/14398
ll isVisited[1010] = {0,};
ll room[1010] = {0,};
vector<ll> v[1010];
vector<ll> odd,even;
bool dfs(ll n){
    isVisited[n]++;
    for(auto k : v[n]){
        if(isVisited[k]) continue;
        isVisited[k]++;
        if(room[k] == -1|| dfs(room[k])){
            room[k] = n;
            return true;
        }
    }
    return false;
}
ll gcd(ll a, ll b){
    if(a < b) swap(a,b);
    if(b == 0) return a;
    else return gcd(b, a%b);
}
bool isSqr(ll n){
    ll temp = (ll)sqrt(n);
    if(temp * temp == n) return true;
    else return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0;i<n;i++){
        cin >> arr[i];
        if(arr[i] % 2 == 1) odd.push_back(arr[i]);
        else even.push_back(arr[i]);
    }
    for(ll i = 0;i<odd.size();i++){
        for(ll j = 0;j<even.size();j++){
            if(gcd(odd[i],even[j]) == 1 && isSqr(odd[i] * odd[i] + even[j] * even[j])){
                v[i].push_back(j+200);
            }
        }
    }
    ll ans = 0;
    memset(room,-1,sizeof(room));
    for(int i = 0;i<odd.size();i++){
        memset(isVisited,0,sizeof(isVisited));
        if(dfs(i)) {
            ans++;
        }
    }
    cout << ans;

    return 0;
}
