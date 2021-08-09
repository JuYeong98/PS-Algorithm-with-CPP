#include <iostream>
#include <string>
#include <vector>
using namespace std;
//주어진 배열 A에서 가장 많이 등장하는 숫자를 반환한다. 
//만약 두가지 있을 경우 아무거나 반환한다.
double majority(const vector<int>& A) {
	int N = A.size(); //A배열의 크기
	int majority = -1, majorityCount = 0;
	for (int i = 0; i < N; i++) {
		//A에 등장하는 A[i]의 수를 센다.
		int V = A[i], count = 0;
		for (int j = 0; j < N; j++) {
			if (V == A[j])
				count++;
		}
		if (count > majorityCount)
		{
			majorityCount = count;
			majority = V;
		}
	}
	return majority;
}

int main(void) {


}