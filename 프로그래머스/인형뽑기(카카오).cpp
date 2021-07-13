#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<int> box;
    int answer = 0;

    int row = board.size();
    int column = board[0].size();
    int len = moves.size();
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (board[j][moves[i] - 1] != 0)
            {
                box.push_back(board[j][moves[i] - 1]);
                cout << "moves:" << moves[i] << "  °ª:" << board[j][moves[i] - 1] << " ";
                board[j][moves[i] - 1] = 0;
                int len2 = box.size();
                if (len2 >= 2)
                {
                    if (box[len2 - 1] == box[len2 - 2])
                    {
                        box.pop_back();
                        box.pop_back();
                        answer+=2;
                    }
                }
                break;
            }
        }
    }
    return answer;
}
