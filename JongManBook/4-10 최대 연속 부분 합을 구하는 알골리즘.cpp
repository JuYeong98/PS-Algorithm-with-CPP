#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MIN = numeric_limits<int>::min();
//lo, hi의 연속된 부분구간의 최대합을 구한다. 시간복잡도 nlogn
int fastMaxSum(const vector<int>& A, int lo, int hi) {
	//기저 사례: 구간의 길이가 1인경우
	if (lo == hi)
		return A[lo];
	int mid = (lo + hi) / 2;
	//두 부분에 모두 걸쳐 있는 최대 합 구간을 구한다. 
	//A[i,,,mid] 와 A[mid+1, ..j] 형태를 갖는 구간의 합으로 이루어진다.
	//A[i...mid] 형태를 갖는 최대 구간을 찾는다.
	int left = MIN, right = MIN, sum = 0;
	for (int i = mid; i >= lo; i--) {
		sum += A[i];
		left = max(left, sum);
	}
	sum = 0; 
	for (int i = mid + 1; i <= hi; i++)
	{
		sum += A[i];
		right = max(right, sum);
	}
	
	//최대 구간이 두 조각중 하나에만 속해있는 경우의 답을 재귀호출로 찾는다.
	int single = max(fastMaxSum(A, lo, mid),
		fastMaxSum(A, mid + 1, hi));
	return max(left + right, single);
}
int fastMaxDP(const vector<int>A, int lo, int hi) {
	int N = A.size() , ret = MIN, psum = 0;
	for (int i = 0; i < N; i++) {
		psum = max(psum, 0) + A[i];
		ret = max(psum, ret);
	}
	return ret;
}
int main(void) {
	vector<int> A;
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		A.push_back(rand() % 100);
		cout << A[i]<<"  ";
	}
	int partialSum= fastMaxSum(A, 0, 9);
	int partialDPSum = fastMaxDP(A, 0, 9);
	cout << partialSum<<endl;
	cout << partialDPSum << endl;
}