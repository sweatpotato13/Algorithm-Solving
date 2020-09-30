#include <string>
#include <vector>

using namespace std;
long long dp[5001]={1,};
int solution(int n) {
    int answer = 0;
    long long sum = 0;
    for(int i = 2;i<=n;i+=2){
        dp[i] = (3 * dp[i - 2] + sum * 2) %1000000007;
        sum += dp[i-2];
    }
    answer = dp[n];
    return answer;
}
