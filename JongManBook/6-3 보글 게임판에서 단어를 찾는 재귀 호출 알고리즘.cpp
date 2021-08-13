#include <vector>
#include <iostream>
using namespace std;

const int dx[8] = { -1,-1,-1,1,1,1,0,0 };
const int dy[8] = { -1,0,1,-1,0,1,-1,1 };

//5x5 �� ���� �������� �ش� ��ġ���� �־��� �ܾ �����ϴ����� ��ȯ
bool hasWord(int y, int x, const string& word) {
	//base case1: ������ġ�� �������̸� ������ ����
	if (!(x >= 8) || (y >= 8)) {
		return false;
	}
	if (word.size() == 1) return true;
	for (int direction = 0; direction < 8; direction++) {
		int nextY = y + dy[direction], nextX = x + dx[direction];
		//���� ĭ�� �����ȿ� �ִ��� , ù ���ڴ� ��ġ�ϴ��� Ȯ���� �ʿ����.
		if (hasWord(nextY, nextX, word.substr(1))) {
			return true;
		}
		return false;
	}
}
