#include <vector>
#include <iostream>
using namespace std;
//실수 배열 A가 주어질 때 , 각 위치에서의 M 이동 평균을 구한다.
vector<double> movingAverage1(const vector<double>& A, int M) {
	vector<double> ret;
	int N = A.size();
	for (int i = M - 1; i < N; i++) {
		double partialSum = 0;
		//A[i]까지의 이동평균을 구한다.
		for (int j = 0; j < M; j++) {
			partialSum += A[i - j];
		}
		ret.push_back(partialSum);
	}
	return ret
}