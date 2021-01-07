#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://codeforces.com/contest/1362/problem/B
bool isVisited[1025] = {0,};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll ans = -1;
        ll n;
        cin >> n;
        vector<ll> v(n);
        memset(isVisited,0,sizeof(isVisited));
        for(int i = 0;i<n;i++){
            cin >> v[i];
            isVisited[v[i]] = true;
        }
        for(int i = 1;i<1024;i++){
            ll isAnswer = true;
            for(int j = 0;j<n;j++){
                if(!isVisited[v[j]^i]){
                    isAnswer = false;
                    break;
                }
            }
            if(isAnswer){
                ans = i;
                break;
            }
        }
        
        cout << ans << "\n";
    }
    
	return 0;

}