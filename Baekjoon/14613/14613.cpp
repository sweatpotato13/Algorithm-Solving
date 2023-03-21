#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/10819
ld dp[21][4001] ={0,};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ld w,l,d;
    cin >> w >> l >> d;
    ld b=0,s=0,g=0,p=0,da=0;
    dp[0][2000] = 1;
    for(int i = 1;i<=20;i++){
        for(int j = 1000;j<=3499;j++){
            if(dp[i-1][j] == 0) continue;
            dp[i][j-50] += dp[i-1][j] * l;
            dp[i][j+50] += dp[i-1][j] * w;
            dp[i][j] += dp[i-1][j] * d;
        }
    }
    for(int i = 1000;i<=3499;i++){
        if(1000 <= i && i < 1500) b+=dp[20][i];
        else if(1500 <= i && i < 2000) s+=dp[20][i];
        else if(2000 <= i && i < 2500) g+=dp[20][i];
        else if(2500 <= i && i < 3000) p+=dp[20][i];
        else if(3000 <= i && i < 3500) da+=dp[20][i];
    }
    cout << fixed;
    cout.precision(8);
    cout << b << "\n" << s << "\n" << g << "\n" << p << "\n" << da << "\n";
    return 0;
}
