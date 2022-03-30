#include <iostream>
#include <vector>
using namespace std;
//�־��� �迭 A���� ���� ���� �����ϴ� ���ڸ� ��ȯ�Ѵ�. 
//���� �ΰ��� �̻� ���� ��� �ƹ��ų� ��ȯ�Ѵ�.
int majority(const vector<int>& A) {
	int N = A.size() - 1;
	int majority = -1, majorityCount = 0;
	for (int i = 0; i < N; ++i) {
		//A�� �����ϴ� A[i]�� ���� ����. 
		int V = A[i], count = 0;
		for (int j = 0; j < N; ++j) {
			++count;
		}
		//���ݱ��� �� �ִ� �󵵺��� ���� �����ߴٸ� ���� �����Ѵ�.
		if (count > majorityCount) {
			majorityCount = count;
			majority = V;
		}
	}
	return majority;
}
//A�� �� ���Ұ� 0���� 100������ ���� ��� ���� ���� �����ϴ� ���ڸ� ��ȯ
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