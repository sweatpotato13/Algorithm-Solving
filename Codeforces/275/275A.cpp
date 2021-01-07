#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://codeforces.com/problemset/problem/275/A
ll board[3][3] = {0,};
ll ans[3][3] = {0,};
ll dir[5][2] ={{0,0},{1,0},{-1,0},{0,1},{0,-1}};
bool isAvailable(ll x, ll y){
    if(x >= 0 && y >= 0 && x < 3 && y < 3) return true;
    else return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            cin >> board[i][j];
            if(board[i][j]){
                for(int k = 0;k<5;k++){
                    ll x = i + dir[k][0];
                    ll y = j + dir[k][1];
                    if(isAvailable(x,y)){
                        ans[x][y] += board[i][j];
                    }
                }
            }
        }
    }
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            if(ans[i][j] & 1) cout << 0;
            else cout << 1;   
        }
        cout << "\n";
    }

    return 0;
}
