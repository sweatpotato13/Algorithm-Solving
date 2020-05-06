#include <string>
#include <vector>
typedef long long int ll;
using namespace std;
// https://programmers.co.kr/learn/courses/30/lessons/12914
ll dp[2001] = {0,};
long long solution(int n) {
    long long answer = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i = 4; i<=n;i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 1234567;
    }
    answer = dp[n];
    return answer;
}
