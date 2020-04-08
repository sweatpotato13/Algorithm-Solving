#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string str)
{
    int answer = 0;
	stack<char> s;
	for(int i = 0;i<str.length();i++){
		if(s.empty()){
			s.push(str[i]);
		}
		else{
			if(s.top() == str[i]){
				s.pop();
			}
			else{
				s.push(str[i]);
			}
		}
	}
	if(s.empty()) answer = 1;
	else answer = 0;

    return answer;
}