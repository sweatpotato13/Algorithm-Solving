#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
	if(a > b){
		int temp = a;
		a = b;
		b = temp;
	}
	while(!((a % 2) && (b-a == 1))){
		if(a % 2) a++;
		if(b % 2) b++;
		a /= 2;
		b /= 2;
		answer++;
	}
    return answer;
}