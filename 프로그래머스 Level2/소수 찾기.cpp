#include <string>
#include <vector>
#include <algorithm>//permutation 을 이용
#include <iostream>
using namespace std;
bool is_prime(int a);
int solution(string numbers) {
	int answer = 0;
	vector<string> num;
	vector<int> result;
	for (int i = 0; i < numbers.size(); i++){
		num.push_back(numbers.substr(i, 1));//한글자씩 string 형태로 num 벡터에 넘긴다.
	}
	sort(num.begin(), num.end());
	for (int a = 0; a < numbers.size(); a++) {
		do {
			string temp = "";
			for (int i = 0; i <=a; i++)
			{
				temp.append(num[i]);	
			}
			result.push_back(stoi(temp));
		} while (next_permutation(num.begin(), num.end()));
	}
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());
	for (int i = 0; i < result.size(); i++)
	{
		if (is_prime(result[i]))
			answer++;
	}
	return answer;
}








bool is_prime(int a)
{
	int c = 0;
	for (int i = 1; i <= a; i++)
	{
		if (a % i == 0)
			c++;
	}
	return (c == 2);
}