#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board) { //가장 큰 정사각형 - success
    int answer = board[0][0];
    int garo = board[0].size(); //4 - 4
    int sero = board.size(); //4 - 2

    for (int i = 1; i < sero; i++) {
        for (int j = 1; j < garo; j++) {
            //0인 경우에는 정사각형이 만들어지지 않으므로 1인 경우만 계산
            if (board[i][j] == 1) {
                //왼쪽점, 위쪽점, 왼쪽 대각선에 있는 점 비교 수행
                board[i][j] = min(board[i][j - 1], board[i - 1][j]);
                board[i][j] = min(board[i - 1][j - 1], board[i][j]) + 1;
                answer = max(answer, board[i][j]);
            }
        }
    }

    //오른쪽 아래에는 변의 길이만 저장되어 있기 때문에 제곱 수행
    return answer * answer;
}