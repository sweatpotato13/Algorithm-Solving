#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/10830
ll n,b;
vector<vector<int>> v;
vector<vector<int>> ans;
#define MAX 1000
vector<vector<int>> matrix_mul(vector<vector<int>> fst, vector<vector<int>> snd){
    vector<vector<int>> res(n, vector<int>(n));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            for(int k = 0;k<n;k++){
                res[i][j] += fst[i][k] * snd[k][j];
            }
            res[i][j] %= 1000;
        }
    }
    return res;
}
vector<vector<int>> matrix_pow(vector<vector<int>> fst){
    vector<vector<int>> res(n, vector<int>(n));
    vector<vector<int>> temp = fst;

    for (int i = 0; i < n; i++){    //identity matrix
        for (int j = 0; j < n; j++){
            if (i == j)   
                res[i][j] = 1;
            else            
                res[i][j] = 0;
        }
    }
    while(b > 0){
        if(b&1) res = matrix_mul(res, temp);
        temp = matrix_mul(temp,temp);
        b >>= 1;
    }
    return res;
}
void solve(int k){
    ans = matrix_pow(v);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    cin >> n >> b;
    for(int i = 0;i<n;i++){
        vector<int> a;
        for(int j = 0;j<n;j++){
            int e;
            cin >> e;
            a.push_back(e);
        }
        v.push_back(a);
    }
    solve(b);
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
	return 0;
}