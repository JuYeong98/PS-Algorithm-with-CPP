#include <vector>
using namespace std;
const int INF = 987654321;

//이 메뉴로 모드가 식사를 할 수 있는지 반환한다.
bool canEveryoneEat(const vector<int>& menu);
//요리할 수 있는 음식 종류의 수
int M;
//food 번째 음식을 만들지 말지 여부를 결정한다.
int selectMenu(vector<int>& menu, int food) {
	//기저 사례  : 모든 음식에 대해 만들지 여부를 결정했을때
	if(food ==M){
		if(canEveryoneEat(menu)) return menu.size();
		//아무것도 못 먹는 사람이 있으면 아주 큰 값을 반환한다. 
		return INF;
	}
	// 이 음식을 만들지않는경우의 수를 생각해본다.
	int ret = selectMenu(menu, food + 1);
	menu.push_back(food);
	ret = min(ret, selectMenu(menu, food + 1));
	menu.pop_back();
	return ret;
}