#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int arr1_row = arr1.size();  
    int arr1_col = arr1[0].size();
    int arr2_row = arr2.size();
    int arr2_col = arr2[0].size();
    vector<vector<int>> answer(arr1_row,vector<int>(arr2_col,0));
    int sum = 0;
    int result = 0;
    for (int i = 0; i < arr1_row; i++)
    {
        for (int k = 0; k < arr2_col; k++)
        {
            sum = 0;
            for (int j = 0; j < arr1_col; j++)
            {
                result = arr1[i][j] * arr2[j][k];
                sum += result;
                if (j == arr1_col - 1)
                    answer[i][k] = sum;
            }
        }
    }
    return answer;
}