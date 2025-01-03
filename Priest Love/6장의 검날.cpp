#include <iostream>
#include <vector>


using namespace std;
int arr[9]; // 길
int visited[9]; // 방문 표시
bool is_arrive = false;

void Bfs(int num, int target);

int main() {

	//for (int i = 1; i < sizeof(arr) / sizeof(*arr);i++) //약간 어렵게 표현하면 배열 arr의 크기
	for (int i = 1; i < 9; i++) {
		arr[i] = 1;

	}
	//arr[7] = 0; //사과를 먹지 못할 경우 만들기.

	int dinosaur = 3;
	int apple = 8;


	Bfs(dinosaur, apple);


	if (is_arrive) {
		cout << "공룡이 사과를 먹었습니다." << endl;
	}
	else {
		cout << "공룡이 사과를 먹지 못했습니다" << endl;
	}



}

void Bfs(int num, int target) {

	visited[num] = 1;
	if (num == target) {
		is_arrive = true;
	}

	cout << "현재 위치는 " << num << endl;
	int d_x[2] = { -1, +1 }; // 좌 우 이동

	int next_x;

	for (int i = 0; i < 2; i++) // i가 2까지인 이유는 d_x의 크기가 2라서
	{
		next_x = num + d_x[i]; //현재 위치에서 다음위치를 계산한다.

		if (next_x >= 0 && next_x <= 8) //다음 이동범위가 배열 안에 존재할 수 있는가 체크
		{
			if (visited[next_x] == 0 && arr[next_x] == 1) //다음 이동이 방문하지 않았고, 길이 연결되어 있는가 체크
			{
				Bfs(next_x, target);
			}
		}
	}
	cout << endl; // 공백을 넣음으로 써 재귀함수가 작동한 다는 것을 확인했고 재귀함수 때분에 공백이 여럿 발생한다.
}