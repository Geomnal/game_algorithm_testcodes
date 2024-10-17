#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
int map[9];
int visitcount[9];
void GeomnalDFS(int player, int finish) //DFS 예시 함수 (재귀 함수 사용)
{
    int dinosaur = player;
    int next_d;
    int apple = finish;
    cout << "악! 황근출 해병님의 현재 위치는 : " << dinosaur << endl;
    if (dinosaur == finish)
    {
        cout << "악! 황근출 해병님이 아쎄이에게 도착했습니다!!" << endl;
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
void GeomnalBFS(int player, int finish) //BFS 예시 함수 queue 사용
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
        cout << "악! 현재 황근출 해병님의 위치는 " << cur_dino << " 입니다!" << endl;
        q.pop();
        
        if (cur_dino == finish)
        {
            cout << "악! 황근출 해병님이 아쎄이에게 도착했습니다!!" << endl;
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
    cout << "황근출 해병님의 사로를 입력하세요 : ";
    cin >> m_player;
    cout << endl;
    cout << "아쎄이의 사로를 입력하세요(8보단 작아야 함) : ";
    cin >> m_finish;
    cout << "반갑다 아쎄이! 난 황근출 해병이라고 한다!" << endl;
    cout << "내가 지금 탈영을 한 기열 찐빠 아쎄이를 잡으려고 화장실을 탐색 할 것인데, DFS와 BFS중 뭐가 더 좋은지 입력하도록!!" << endl;
    cout << "나의 대답은.. : ";
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
        cout << "새끼..기열! 선임의 말을 장난으로 알다니!" << endl;
        cout << "사망하셨습니다.";
        return 0;
    }
}