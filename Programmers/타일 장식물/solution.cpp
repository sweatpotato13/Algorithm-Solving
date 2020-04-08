#include <string>
#include <vector>
typedef long long ll;
using namespace std;
ll dp[81] ={0,};
ll increase[81] ={0,};

long long solution(int N) {
    dp[1] = 4;
	dp[2] = 6;
	increase[1] = 2;
	increase[2] = 4;
	for(int i = 3;i<=N;i++){
		dp[i] = dp[i-1]+increase[i-1];
		increase[i] = increase[i-1] + increase[i-2];
	}
    return dp[N];
}