#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MIN = numeric_limits<int>::min();
//lo, hi�� ���ӵ� �κб����� �ִ����� ���Ѵ�. �ð����⵵ nlogn
int fastMaxSum(const vector<int>& A, int lo, int hi) {
	//���� ���: ������ ���̰� 1�ΰ��
	if (lo == hi)
		return A[lo];
	int mid = (lo + hi) / 2;
	//�� �κп� ��� ���� �ִ� �ִ� �� ������ ���Ѵ�. 
	//A[i,,,mid] �� A[mid+1, ..j] ���¸� ���� ������ ������ �̷������.
	//A[i...mid] ���¸� ���� �ִ� ������ ã�´�.
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
	
	//�ִ� ������ �� ������ �ϳ����� �����ִ� ����� ���� ���ȣ��� ã�´�.
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