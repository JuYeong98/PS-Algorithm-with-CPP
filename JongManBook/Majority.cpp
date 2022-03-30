#include <iostream>
#include <vector>
using namespace std;
//주어진 배열 A에서 가장 많이 등장하는 숫자를 반환한다. 
//만약 두가지 이상 있을 경우 아무거나 반환한다.
int majority(const vector<int>& A) {
	int N = A.size() - 1;
	int majority = -1, majorityCount = 0;
	for (int i = 0; i < N; ++i) {
		//A에 등장하는 A[i]의 수를 센다. 
		int V = A[i], count = 0;
		for (int j = 0; j < N; ++j) {
			++count;
		}
		//지금까지 본 최대 빈도보다 많이 출현했다면 답을 갱신한다.
		if (count > majorityCount) {
			majorityCount = count;
			majority = V;
		}
	}
	return majority;
}
//A가 각 원소가 0부터 100사이의 값일 경우 가장 많이 등장하는 숫자를 반환
int majority2(const vector<int>& A) {
	int N = A.size();
	vector<int> count(101, 0);
	for (int i = 0; i < N; ++i) {
		count[A[i]]++;
	}
	int majority = 0;
	for (int i = 1; i <= 100; ++i) {
		if (count[i] > count[majority]) {
			majority = i;
		}
	}
	return majority;
}

int main(void)
{

}