#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s[30];
	stack<int> goal;
	for(int i = 0;i<board.size();i++){
		for(int j = board.size()-1;j>=0;j--){
			if(board[j][i] != 0)
				s[i].push(board[j][i]);
		}
	}

	for(int i=0;i<moves.size();i++){
		int e = moves[i] - 1;
		if(s[e].empty()) 
			continue;
		int a = s[e].top();
		s[e].pop();
		if(goal.empty())
			goal.push(a);
		else{
			if(goal.top() == a){
				goal.pop();
				answer++;
			}
			else{
				goal.push(a);
			}
		}
	}
    return answer*2;
}