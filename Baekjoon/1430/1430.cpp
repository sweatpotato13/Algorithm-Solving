#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/1430
vector<pll> tower(101);
vector<ll> v[101];
bool isVisited[101] = {0,};
ld ans = 0;
ll n,r,d,x,y;
void bfs(ll s){
    queue<ll> q;
    isVisited[s] = true;
    q.push(s);
    for(ld cost = 1;!q.empty();cost/=2){
        ll size = q.size();
        for(int i = 0;i<size;i++){
            ll cur = q.front();
            q.pop();
            for(int next : v[cur]){
                if(!isVisited[next]){
                    isVisited[next] = true;
                    q.push(next);
                    if(next > 0) ans += d*cost;
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> r >> d >> x >> y;
    tower[0] = {x,y};
    for(int i = 1;i<=n;i++){
        cin >> tower[i].first >> tower[i].second;
        for(int j = 0;j<i;j++){
            if((tower[i].first-tower[j].first) * (tower[i].first-tower[j].first) 
                + (tower[i].second-tower[j].second) * (tower[i].second-tower[j].second) <= r*r){
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
        }
    }
    bfs(0);
    cout << fixed;
    cout.precision(2);
    cout << ans;


    return 0;
}


