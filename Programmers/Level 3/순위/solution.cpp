#include <string>
#include <vector>
typedef long long int ll;
using namespace std;
// https://programmers.co.kr/learn/courses/30/lessons/49191
ll arr[101][101] = {0,};
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for(int i = 0;i<results.size();i++){
        ll e = results[i][0];
        ll s = results[i][1];
        arr[e][s] = 1;
    }
    for(int i = 1;i<=n;i++){
         for(int j = 1;j<=n;j++){
            for(int k = 1;k<=n;k++){
                if(arr[j][i] && arr[i][k])
                    arr[j][k] = 1;
            }
        }   
    }
    for(int i = 1;i<=n;i++){
        ll cnt = 0;
        for(int j = 1;j<=n;j++){
            if(i == j) continue;
            if(!arr[i][j] && !arr[j][i])
                cnt++;
        }
        if(cnt == 0) answer++;
    }
    return answer;
}
