#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/16395
ll pascal[50][50] ={0,};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pascal[0][0] = 1;
    pascal[1][0] = 1;
    pascal[1][1] = 1;
    ll n,k;
    cin >> n >> k;
    for(int i = 2;i<=n;i++){
        for(int j = 0;j<=i;j++){
            if(j == 0 || j == i) pascal[i][j] = 1;
            else pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
        }
    }
    cout << pascal[n-1][k-1];


    return 0;
}