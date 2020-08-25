#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/18352
vector<ll> v[300001];
bool isVisited[300001] ={0,};
ll n,m,k,x;
void BFS(ll n){
    ll d = 0;
    queue<int> q;
    q.push(n);
    isVisited[n] = true;
    while(!q.empty()){
        ll s = q.size();
        for(int i = 0;i<s;i++){
            ll cur = q.front();
            q.pop();
            for(int j = 0;j<v[cur].size();j++){
                ll next = v[cur][j];
                if(isVisited[next]) continue;
                isVisited[next] = true;
                q.push(next);
            }
        }
        d++;
        if(d == k && !q.empty()){
            priority_queue<ll, vector<ll>, greater<ll>> pq;
            while(!q.empty()){
                pq.push(q.front());
                q.pop();
            }
            while(!pq.empty()){
                cout << pq.top() << "\n";
                pq.pop();
            }
            return;
        }
    }
    cout << -1;
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k >> x;
    for(int i = 0;i<m;i++){
        ll a,b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    BFS(x);
    return 0;
}
