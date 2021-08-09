#include <vector>
using namespace std;
const int INF = 987654321;

//�� �޴��� ��尡 �Ļ縦 �� �� �ִ��� ��ȯ�Ѵ�.
bool canEveryoneEat(const vector<int>& menu);
//�丮�� �� �ִ� ���� ������ ��
int M;
//food ��° ������ ������ ���� ���θ� �����Ѵ�.
int selectMenu(vector<int>& menu, int food) {
	//���� ���  : ��� ���Ŀ� ���� ������ ���θ� ����������
	if(food ==M){
		if(canEveryoneEat(menu)) return menu.size();
		//�ƹ��͵� �� �Դ� ����� ������ ���� ū ���� ��ȯ�Ѵ�. 
		return INF;
	}
	// �� ������ �������ʴ°���� ���� �����غ���.
	int ret = selectMenu(menu, food + 1);
	menu.push_back(food);
	ret = min(ret, selectMenu(menu, food + 1));
	menu.pop_back();
	return ret;
}