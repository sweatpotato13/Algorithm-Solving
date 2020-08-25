#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/18243
vector<ll> v[101];
ll isVisited[101] ={0,};
ll n,k;
void BFS(ll s){
    queue<ll> q;
    q.push(s);
    isVisited[s] = 0;
    while(!q.empty()){
        ll cur = q.front();
        q.pop();
        for(int i = 0;i<v[cur].size();i++){
            ll next = v[cur][i];
            if(isVisited[next] == -1){
                q.push(next);
                isVisited[next] = isVisited[cur]+1;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string ans[2] = {"Big World!","Small World!"};
    cin >> n >> k;
    for(int i = 0;i<k;i++){
        ll a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bool isAnswer = true;
    for(int i = 1;i<=n;i++){
        memset(isVisited,-1,sizeof(isVisited));
        BFS(i);
        for(int j=1;j<=n;j++){
            if(isVisited[j] == -1 || isVisited[j] > 6){
                isAnswer = false;
                goto END;
            }
        }
    }
    END:
    cout << ans[isAnswer];
    return 0;
}
