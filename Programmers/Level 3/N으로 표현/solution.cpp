#include <string>
#include <vector>

using namespace std;
int answer = 9;
void dfs(int N, int number, int cnt, int current){
	if(cnt >= 9) return;
	if(current == number){
		answer = min(answer, cnt);
	}
	int temp = 0;
	for(int i = 0;i+cnt<9;i++){
		temp = temp * 10 + N;
		dfs(N, number, cnt+1+i, current + temp);
		dfs(N, number, cnt+1+i, current - temp);
		dfs(N, number, cnt+1+i, current * temp);
		dfs(N, number, cnt+1+i, current / temp);
	}
}
int solution(int N, int number) {
    dfs(N,number,0,0);
    if(answer == 9) return -1;
    else return answer;
}