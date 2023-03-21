#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/2014
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll k,n;
    cin >> k >> n;
    vector<ll> v(k);
    for(int i = 0;i<k;i++){
        cin >> v[i];
    }
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    map<ll,ll> isVisited;
    pq.push(1);
    ll m = 0;
    while(n--){
        ll cur = pq.top();
        pq.pop();
        for(int i = 0;i<k;i++){
            ll next = cur * v[i];
            if(pq.size() > n && next > m)
                continue;
            if(!isVisited[next]){
                m = max(m, next);
                isVisited[next] = 1;
                pq.push(next);
            }
        }
    }
    cout << pq.top();

    return 0;
}
