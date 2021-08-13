#include <iostream>
#include <vector>
using namespace std;
void printPicked(vector<int> A) {
	for (int i = 0; i < A.size(); i++) {
		//cout << "check\n";
		cout << A[i];
	}
}
void Pick(int n, int topick, vector<int> picked) {
	if (topick == 0) {//�� ������ ������ 0�̸� 0��ȯ
		printPicked(picked);
		//cout << "check\n";
		return;
	}
	//�� �� �ִ� ���� ���� ��ȣ�� ����Ѵ�.
	int smallest = picked.empty() ? 0 : picked.front() + 1;
	//��������� 0
	cout <<"smallest"<< smallest << endl;
	for (int next = smallest; next < n; next++) {
		picked.push_back(next);
		Pick(n, topick - 1, picked);
		picked.pop_back();
	}
}
int main(void) {
	vector<int> A;
	for (int i = 0; i < 7; i++) {
		A.push_back(i + 1);
		cout << "  " << A[i];
	}
	cout << endl;
	Pick(7, 2, A);
}