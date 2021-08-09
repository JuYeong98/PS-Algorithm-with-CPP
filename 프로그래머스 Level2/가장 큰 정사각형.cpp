#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board) { //���� ū ���簢�� - success
    int answer = board[0][0];
    int garo = board[0].size(); //4 - 4
    int sero = board.size(); //4 - 2

    for (int i = 1; i < sero; i++) {
        for (int j = 1; j < garo; j++) {
            //0�� ��쿡�� ���簢���� ��������� �����Ƿ� 1�� ��츸 ���
            if (board[i][j] == 1) {
                //������, ������, ���� �밢���� �ִ� �� �� ����
                board[i][j] = min(board[i][j - 1], board[i - 1][j]);
                board[i][j] = min(board[i - 1][j - 1], board[i][j]) + 1;
                answer = max(answer, board[i][j]);
            }
        }
    }

    //������ �Ʒ����� ���� ���̸� ����Ǿ� �ֱ� ������ ���� ����
    return answer * answer;
}