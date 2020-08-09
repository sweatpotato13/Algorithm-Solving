#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/14433
ll isVisited[301] = {0,};
ll room[301] = {0,};
vector<ll> team1[301];
vector<ll> team2[301];
string ans[2] = {"그만 알아보자", "네 다음 힐딱이"};
bool dfs1(ll n){
    if(isVisited[n]){
        return false;
    }
    else{
        isVisited[n]++;
        for(auto k : team1[n]){
            if(!room[k]|| dfs1(room[k])){
                room[k] = n;
                return true;
            }
        }
        return false;
    }
}
bool dfs2(ll n){
    if(isVisited[n]){
        return false;
    }
    else{
        isVisited[n]++;
        for(auto k : team2[n]){
            if(!room[k]|| dfs2(room[k])){
                room[k] = n;
                return true;
            }
        }
        return false;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, k1, k2;
    cin >> n >> m >> k1 >> k2;
    for(int i = 0;i<k1;i++){
        ll s,e;
        cin >> s >> e;
        team1[s].push_back(e);
    }
    for(int i = 0;i<k2;i++){
        ll s,e;
        cin >> s >> e;
        team2[s].push_back(e);
    }
    ll ans1 = 0;
    for(int i = 1;i<=n;i++){
        memset(isVisited,0,sizeof(isVisited));
        if(dfs1(i)) {
            ans1++;
        }
    }
    memset(room,0,sizeof(room));
    ll ans2 = 0;
    for(int i = 1;i<=n;i++){
        memset(isVisited,0,sizeof(isVisited));
        if(dfs2(i)) {
            ans2++;
        }
    }
    bool canWin = false;
    if(ans1 < ans2) canWin = true;
    cout << ans[canWin];

    return 0;
}
