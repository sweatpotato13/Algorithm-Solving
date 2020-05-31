#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://codeforces.com/problemset/problem/1359/B
ll dp[100][1000] ={0,};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        memset(dp,0,sizeof(dp));
        ll ans = 0;
        ll n,m,x,y;
        cin >> n >> m >> x >> y;
        vector<string> v(n);
        for(int i = 0;i<n;i++){
            cin >> v[i];
        }        
        if(x*2 <= y){   // 1*1 is cheaper
            for(int i = 0;i<n;i++){
                for(int j = 0;j<m;j++){
                    if(v[i][j] == '.')
                        ans++;
                }
            }     
            ans *= x;   
        }
        else{   // 1*2 is cheaper
            for(int i = 0;i<n;i++){
                ll temp = 0;
                for(int j = 0;j<m;j++){
                    if(v[i][j] == '.'){
                        temp++;
                    }
                    else{
                        if(temp % 2 == 0){
                            ans += (temp/2) * y;
                        }
                        else{
                            ans += x;
                            ans += ((temp-1)/2) * y;
                        }
                        temp = 0;
                    }
                }
                if(temp % 2 == 0){
                    ans += (temp/2) * y;
                }
                else{
                    ans += x;
                    ans += ((temp-1)/2) * y;
                }
                temp = 0;
            }     
        }
        cout << ans << "\n";
    }

	return 0;
}