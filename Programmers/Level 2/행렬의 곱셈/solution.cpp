#include <string>
#include <vector>
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    ll size1 = arr1.size();
    ll size2 = arr2[0].size();
    ll size3 = arr1[0].size();
    vector<vector<int>> answer(size1, vector<int>(size2));
    for(int i = 0;i<size1;i++){
        for(int j = 0;j<size2;j++){
            for(int k = 0;k<size3;k++){
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    return answer;
}

