#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// https://programmers.co.kr/learn/courses/30/lessons/12929
typedef long long ll;
ll dp[29] ={0,};
ll solution(ll n) {
    int answer = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 5;
    for(int i = 3;i<=n;i++){
        dp[i+1] = dp[i] * 2 * (2*i+1) / (i+2);
    }
    answer = dp[n];

    return answer;
}
