#include <iostream>
#include <vector>


using namespace std;
int arr[9]; // ��
int visited[9]; // �湮 ǥ��
bool is_arrive = false;

void Dfs(int num, int target);

int main() {

	//for (int i = 1; i < sizeof(arr) / sizeof(*arr);i++) //�ణ ��ư� ǥ���ϸ� �迭 arr�� ũ��
	for (int i = 1; i < 9; i++) {
		arr[i] = 1;

	}
	//arr[7] = 0; //����� ���� ���� ��� �����.

	int dinosaur = 3;
	int apple = 8;


	Dfs(dinosaur, apple);


	if (is_arrive) {
		cout << "������ ����� �Ծ����ϴ�." << endl;
	}
	else {
		cout << "������ ����� ���� ���߽��ϴ�" << endl;
	}



}

void Dfs(int num, int target) {

	visited[num] = 1;
	if (num == target) {
		is_arrive = true;
	}

	cout << "���� ��ġ�� " << num << endl;
	int d_x[2] = { -1, +1 }; // �� �� �̵�

	int next_x;

	for (int i = 0; i < 2; i++) // i��  2������ ������ d_x�� ũ�Ⱑ 2��
	{
		next_x = num + d_x[i]; //���� ��ġ���� ������ġ�� ����Ѵ�.

		if (next_x >= 0 && next_x <= 8) //���� �̵������� �迭 �ȿ� ������ �� �ִ°� üũ
		{
			if (visited[next_x] == 0 && arr[next_x] == 1) //���� �̵��� �湮���� �ʾҰ�, ���� ����Ǿ� �ִ°� üũ
			{
				Dfs(next_x, target);
			}
		}
	}
	cout << endl; // ������ �������� �� ����Լ��� �۵��� �ٴ� ���� Ȯ���߰� ����Լ� ���п� ������ ���� �߻��Ѵ�.
}

