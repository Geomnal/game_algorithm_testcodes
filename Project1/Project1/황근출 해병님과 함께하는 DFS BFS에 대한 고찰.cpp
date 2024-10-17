#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
int map[9];
int visitcount[9];
void GeomnalDFS(int player, int finish) //DFS ���� �Լ� (��� �Լ� ���)
{
    int dinosaur = player;
    int next_d;
    int apple = finish;
    cout << "��! Ȳ���� �غ����� ���� ��ġ�� : " << dinosaur << endl;
    if (dinosaur == finish)
    {
        cout << "��! Ȳ���� �غ����� �ƽ��̿��� �����߽��ϴ�!!" << endl;
    }
    int d_x[2] = { -1,1 };
    visitcount[dinosaur] = 1;
    int len_arr = sizeof(map) / sizeof(*map);
    for (int i = 1; i < len_arr; i++)
    {
        map[i] = 1;
    }

    for (int i = 0; i < 2; i++)
    {
        next_d = dinosaur + d_x[i];
        if (next_d >= 0 && next_d <= 8)
        {
            
            if (map[next_d] == 1 && visitcount[next_d]==0 && dinosaur != apple)
            {
                GeomnalDFS(next_d, finish);
            }
        }
    }

    
}
void GeomnalBFS(int player, int finish) //BFS ���� �Լ� queue ���
{
    int dinosaur = player;
    int next_d;
    int apple = finish;
    queue<int> q;
    q.push(player);
    visitcount[player] = 1;
    int d_x[2] = { -1,1 };
    int len_arr = sizeof(map) / sizeof(*map);
    for (int i = 1; i < len_arr; i++)
    {
        map[i] = 1;
    }
    while (!q.empty())
    {
        int cur_dino = q.front();
        cout << "��! ���� Ȳ���� �غ����� ��ġ�� " << cur_dino << " �Դϴ�!" << endl;
        q.pop();
        
        if (cur_dino == finish)
        {
            cout << "��! Ȳ���� �غ����� �ƽ��̿��� �����߽��ϴ�!!" << endl;
            return;
        }
        for (int i = 0; i < 2; i++)
        {
            int next_d = cur_dino + d_x[i];

            if (next_d >= 1 && next_d < 9 && visitcount[next_d] == 0 && map[next_d] == 1)
            {
                q.push(next_d);          
                visitcount[next_d] = 1;  
            }
        }
    }


}

int main()
{
    string answer = "";
    int m_player;
    int m_finish;
    cout << "Ȳ���� �غ����� ��θ� �Է��ϼ��� : ";
    cin >> m_player;
    cout << endl;
    cout << "�ƽ����� ��θ� �Է��ϼ���(8���� �۾ƾ� ��) : ";
    cin >> m_finish;
    cout << "�ݰ��� �ƽ���! �� Ȳ���� �غ��̶�� �Ѵ�!" << endl;
    cout << "���� ���� Ż���� �� �⿭ ��� �ƽ��̸� �������� ȭ����� Ž�� �� ���ε�, DFS�� BFS�� ���� �� ������ �Է��ϵ���!!" << endl;
    cout << "���� �����.. : ";
    cin >> answer;
    cout << endl;
    if (answer == "DFS")
    {
        GeomnalDFS(m_player, m_finish);
    }
    else if (answer == "BFS")
    {
        GeomnalBFS(m_player, m_finish);
    }
    else
    {
        cout << "����..�⿭! ������ ���� �峭���� �˴ٴ�!" << endl;
        cout << "����ϼ̽��ϴ�.";
        return 0;
    }
}