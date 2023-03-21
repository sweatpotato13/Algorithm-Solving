#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://www.acmicpc.net/problem/2910
map<ll,ll> order;
bool cmp(pair<ll,ll> a, pair<ll,ll> b){
    if(a.first > b.first){
        return true;
    }
    else if(a.first < b.first){
        return false;
    }
    else{
        if(order[a.second] < order[b.second]){
            return true;
        }
        else{
            return false;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,c;
    cin >> n >> c;
    map<ll,ll> m;
    ll idx = 1;
    for(int i = 0;i<n;i++){
        ll e;
        cin >> e;
        if(order[e] == 0){
            order[e] = idx++;
        }
        m[e]++;
    }
    vector<pair<ll,ll>> v;
    for(auto k : m){
        v.push_back({k.second,k.first});
    }
    sort(all(v),cmp);
    for(auto k : v){
        for(int i = 0;i<k.first;i++){
            cout << k.second << " ";
        }
    }
    
	return 0;
}
