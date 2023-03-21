#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/1248
char s[11][11];
ll ans[11] ={0,};
ll n;
bool check(ll cnt){
    ll isOk = true;
    ll sum = 0;
    for(int i = cnt,j=0;i>=0;i--,j++){
        sum += ans[i];
        if((sum == 0 && s[i][j] == '0') || 
            (sum > 0 && s[i][j] == '+') || 
            (sum < 0 && s[i][j] == '-')){
            continue;
        }
        else{
            isOk = false;
            break;
        }
    }
    return isOk;
}
void solve(ll cnt){
    if(cnt == n){
        for(int i = 0;i<n;i++){
            cout << ans[i] << " ";
        }
        exit(0);
    }
    if(s[cnt][0] == '0'){
        ans[cnt] = 0;
        if(check(cnt)){
            solve(cnt+1);
        }
    }
    else if(s[cnt][0] == '+'){
        for(int i = 1;i<11;i++){
            ans[cnt] = i;
            if(check(cnt)){
                solve(cnt+1);
            }
            ans[cnt] = 0;
        }
    }
    else{
        for(int i = -1;i>-11;i--){
            ans[cnt] = i;
            if(check(cnt)){
                solve(cnt+1);
            }
            ans[cnt] = 0;
        }
    }

}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    cin >> n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n-i;j++){
            cin >> s[i][j];
        }
    }
    
    solve(0);

	return 0;
}
