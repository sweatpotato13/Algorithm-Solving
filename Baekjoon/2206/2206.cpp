#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://acmicpc.net/problem/2206
ll board[1001][1001] ={0,};
ll cost[1001][1001][2] ={0,};
ll dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
ll n, m;
ll Value = -1;
bool isAvailable(ll x, ll y){
    if(x >= 0 && y >= 0 && x < n && y < m)
        return true;
    else
        return false;
}
void BFS(ll x, ll y){
    queue<pair<pair<ll,ll>,ll>> q;
    q.push({{x,y},0});
    cost[x][y][0] = 1;
    while(!q.empty()){
        pair<pair<ll,ll>,ll> p = q.front();
        q.pop();
        ll xx = p.first.first;
        ll yy = p.first.second;
        ll isBreak = p.second;
        //cout << xx << " " << yy << " " << isBreak << " " << cost[xx][yy][isBreak] << "\n";
        if(xx == n-1 && yy == m-1){
            if(Value == -1) Value = cost[xx][yy][isBreak];
            else Value = min(Value, cost[xx][yy][isBreak]);
        }
        for(int i = 0;i<4;i++){
            ll xxx = xx + dir[i][0];
            ll yyy = yy + dir[i][1];
            if(isAvailable(xxx,yyy)){
                if(cost[xxx][yyy][isBreak] == 0){
                    if(board[xxx][yyy] == 0){
                        cost[xxx][yyy][isBreak] = cost[xx][yy][isBreak] + 1;
                        q.push({{xxx,yyy},isBreak});
                    }
                    else{
                        if(isBreak == 0){
                            cost[xxx][yyy][1] = cost[xx][yy][isBreak] + 1;
                            q.push({{xxx,yyy},1});
                        }
                    }
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<m;j++){
            board[i][j] = s[j] -'0';
        }
    }
    BFS(0,0);
    cout << Value << "\n";
	return 0;

}
