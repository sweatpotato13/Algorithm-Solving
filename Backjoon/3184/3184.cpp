#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/3184
ll r,c;
ll isVisited[251][251] = {0,};
ll dir[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
char m[251][251];
ll ans_s=0, ans_w=0, temp_s=0, temp_w=0;
void BFS(ll x, ll y){
    temp_s = 0;
    temp_w = 0;
    queue<pll> q;
    q.push({x,y});
    isVisited[x][y] = true;
    while(!q.empty()){
        ll xx = q.front().first;
        ll yy = q.front().second;
        q.pop();
        if(m[xx][yy] == 'v') temp_w++;
        if(m[xx][yy] == 'o') temp_s++;
        for(int i = 0;i<4;i++){
            ll nx = xx + dir[i][0];
            ll ny = yy + dir[i][1];
            if(nx >= 0 && ny >= 0 && nx < r && ny < c){
                if(m[nx][ny] != '#' && !isVisited[nx][ny]){
                    isVisited[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
        }
    }
    if(temp_s > temp_w) ans_s += temp_s;
    else ans_w += temp_w;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c;
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin >> m[i][j];
            if(m[i][j] == '#'){
                isVisited[i][j] = true;
            }
        }
    }
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            if(!isVisited[i][j]){
                BFS(i,j);
            }
        }
    }
    cout << ans_s << " " << ans_w;
    return 0; 
}
