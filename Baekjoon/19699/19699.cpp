#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/19699
ll che[10001] ={0,};
ll isVisited[10001] = {0,};
void getChe(ll num) {
    for (int i = 2; i <= num; i++) {
        che[i] = i;
    }
    for (int i = 2; i <= num; i++) { 
        if (che[i] == 0) 
            continue;
        for (int j = i + i; j <= num; j += i) {
            che[j] = 0;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    getChe(10000);
    ll n,m;
    cin >> n >> m;
    vector<ll> v(n);
    vector<ll> idx(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    for(int i = 0;i<m;i++){
        idx[i] = 1;
    }
    sort(all(idx));
    vector<ll> ans;
    do{
        ll temp = 0;
        for(int i = 0;i<n;i++){
            if(idx[i]) temp += v[i];
        }
        if(!isVisited[temp]) isVisited[temp] = true;
        else continue;
        if(che[temp]) ans.push_back(temp);

    }while(next_permutation(all(idx)));
    sort(all(ans));
    if(ans.size() == 0) cout << -1;
    else{
        for(auto k : ans){
            cout << k << ' ';
        }
    }

    return 0;
}
