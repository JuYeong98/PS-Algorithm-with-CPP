#include <iostream>
#include <string>
#include <vector>
using namespace std;
//�־��� �迭 A���� ���� ���� �����ϴ� ���ڸ� ��ȯ�Ѵ�. 
//���� �ΰ��� ���� ��� �ƹ��ų� ��ȯ�Ѵ�.
double majority(const vector<int>& A) {
	int N = A.size(); //A�迭�� ũ��
	int majority = -1, majorityCount = 0;
	for (int i = 0; i < N; i++) {
		//A�� �����ϴ� A[i]�� ���� ����.
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