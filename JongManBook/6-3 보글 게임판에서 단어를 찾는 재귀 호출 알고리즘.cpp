#include <vector>
#include <iostream>
using namespace std;

const int dx[8] = { -1,-1,-1,1,1,1,0,0 };
const int dy[8] = { -1,0,1,-1,0,1,-1,1 };

//5x5 의 보글 게임판의 해당 위치에서 주어진 단어가 시작하는지를 반환
bool hasWord(int y, int x, const string& word) {
	//base case1: 시작위치가 범위밖이면 무조건 실패
	if (!(x >= 8) || (y >= 8)) {
		return false;
	}
	if (word.size() == 1) return true;
	for (int direction = 0; direction < 8; direction++) {
		int nextY = y + dy[direction], nextX = x + dx[direction];
		//다음 칸이 범위안에 있는지 , 첫 글자는 일치하는지 확인할 필요없다.
		if (hasWord(nextY, nextX, word.substr(1))) {
			return true;
		}
		return false;
	}
}
