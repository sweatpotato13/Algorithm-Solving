#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://atcoder.jp/contests/abc167/tasks/abc167_c
ll a[12][12] = {0,};
bool isVisited[12] ={0,};
vector<ll> c;
ll n,m,x;
ll ans = -1;
void track(){
    ll skill[12] ={0,};
    ll val = 0;
    for(int i = 0;i<n;i++){
        if(isVisited[i]){
            val += c[i];
            for(int j = 0;j<m;j++){
                skill[j] += a[i][j];
            }
        }
    }
    for(int i = 0;i<m;i++){
        if(skill[i] < x){
            return ;
        }
    }
    if(ans == -1){
        ans = val;
    }
    else{
        ans = min(ans, val);
    }
}
void solve(ll cnt){
    if(cnt == n){
        track();
        return;
    }
    isVisited[cnt] = true;
    solve(cnt+1);
    isVisited[cnt] = false;
    solve(cnt+1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> x;
    c.resize(n);
    for(int i = 0;i<n;i++){
        cin >> c[i];
        for(int j = 0;j<m;j++){
            cin >> a[i][j];
        }
    }
    solve(0);
    cout << ans;

	return 0;

}