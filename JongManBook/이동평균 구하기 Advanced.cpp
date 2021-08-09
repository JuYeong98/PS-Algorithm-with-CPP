#include <vector>
#include <iostream>
using namespace std;
//실수 배열 A가 주어질 때 , 각 위치에서의 M 이동 평균을 구한다.
vector<double> movingAverage1(const vector<double>& A, int M) {
	vector<double> ret;
	int N = A.size();
	double partialSum = 0;
	for (int i = 0; i < M - 1; i++) {
		partialSum += A[i];
	}
	for (int i = M - 1; i < N; i++) {
		partialSum += A[i];
		ret.push_back(partialSum/M);
		partialSum -= A[i - M + 1];
	}
	return ret;
}