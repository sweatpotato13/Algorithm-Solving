#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/7562
ll dir[8][2] = { {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1} };
ll l;
ll sx,sy,ex,ey;
ll isVisited[301][301] = {0,};
bool isAvailable(ll x, ll y){
    if(x >= 0 && y >= 0 && x < l && y < l)
        return true;
    else return false;
}
void BFS(){
    queue <pll> q;
    q.push({sx,sy});
    while(!q.empty()){
        ll x = q.front().first;
        ll y = q.front().second;
        q.pop();
        if(x == ex && y == ey){
            cout << isVisited[x][y] << "\n";
            return;
        }
        for(int i = 0;i<8;i++){
            ll xx = x + dir[i][0];
            ll yy = y + dir[i][1];
            if(isAvailable(xx,yy)){
                if(!isVisited[xx][yy]){
                    isVisited[xx][yy] = isVisited[x][y] + 1;
                    q.push({xx,yy});
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        memset(isVisited,0,sizeof(isVisited));
        cin >> l;
        cin >> sx >> sy >> ex >> ey;
        BFS();
    }

    return 0;
}
