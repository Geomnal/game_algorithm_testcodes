#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int arr[9]; // ��
int visited[9]; // �湮 ǥ��
bool is_arrive = false;

void BFS()
{

}

int main() {

	//for (int i = 1; i < sizeof(arr) / sizeof(*arr);i++) //�ణ ��ư� ǥ���ϸ� �迭 arr�� ũ��
	for (int i = 1; i < 9; i++) {
		arr[i] = 1;

	}
	//arr[7] = 0; //����� ���� ���� ��� �����.

	int d_x[2] = { -1, +1 }; // �� �� �̵� 

	queue<int> q;

	int dinosaur = 3;
	int apple = 8;

	q.push(dinosaur);
	visited[dinosaur] = 1;

	int next_x;


	while (!q.empty()) {


		dinosaur = q.front();

		q.pop();

		cout << "���� ������ ��ġ�� " << dinosaur << endl;

		for (int i = 0; i < 2; i++) {  // 2�� d_x�� ũ��
			next_x = dinosaur + d_x[i];
			if (dinosaur == apple)
			{
				is_arrive = true;
			}
			if (next_x >= 0 && next_x <= 8) {	//���� �̵������� �迭 �ȿ� ������ �� �ִ°� üũ
				if (visited[next_x] == 0 && arr[next_x] == 1) {	//���� �̵��� �湮���� �ʾҰ�,
					//���� ����Ǿ� �ִ°� üũ
					q.push(next_x);
					visited[next_x] = 1;
					cout << "���� q�� �����ϴ� : " << next_x << endl;

				}
			}
		}
		cout << endl;
	}

	if (is_arrive) 
	{
		cout << "������ ����� �Ծ����ϴ�." << endl;
	}
	else 
	{
		cout << "������ ����� ���� ���߽��ϴ�" << endl;
	}


}