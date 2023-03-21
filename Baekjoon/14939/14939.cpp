#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/14939
ll dir[5][2] ={{0,0},{1,0},{-1,0},{0,1},{0,-1}};
char s[10][10];
bool isAvailable(ll x, ll y){
    if(x < 0 || y < 0 || x > 9 || y > 9)
        return false;
    else return true;
}
void push(ll x, ll y,auto &v){
    for(int i = 0;i<5;i++){
        ll xx = x+dir[i][0];
        ll yy = y+dir[i][1];
        if(isAvailable(xx,yy)){
            if(v[xx][yy] == '#') v[xx][yy] ='O';
            else v[xx][yy] = '#';
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ans = INT_MAX;
    for(int i = 0;i<10;i++){
        for(int j = 0;j<10;j++){
            cin >> s[i][j];
        }
    }
    for(int i = (1 << 10)-1;i>=0;i--){
        ll res = 0;
        char temp[10][10];
        memcpy(temp,s,sizeof(s));
        for(int j = 0;j<10;j++){
            if(i & (1<<j)){
                push(0,j,temp);
                res++;
            }
        }
        for(int j = 1;j<10;j++){
            for(int k = 0;k<10;k++){
                if(temp[j-1][k] == 'O'){
                    push(j,k,temp);
                    res++;
                }
            }
        }
        bool isAnswer = true;
        for(int j = 0;j<10;j++){
            if(temp[9][j] == 'O'){
                isAnswer = false;
                break;
            }
        }
        if(isAnswer) ans = min(ans, res);
    }
    if(ans == INT_MAX) ans = -1;
    cout << ans;

	return 0;

}