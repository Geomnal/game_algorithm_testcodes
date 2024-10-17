// ConsoleApplication5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <format>
using namespace std;
void Bubblesort(vector<int> vec)
{
    cout << "버블 정렬을 시작합니다" << endl;
    int tmp; // temporaray 일시적인, 임시값을 저장하기 위한 변수

    for (int k = vec.size() - 1; k > 0; k--)/// vec.size() - 1에 주의, 책에서는 for(int k=0; k<vec.size()-1; k++)
        ///                                  for(int i=0; i<vec.size() - (k+1); i++) 이렇게 구현
    {

        for (int i = 0; i < k; i++)
        {


            if (vec[i] > vec[i + 1])
            {

                tmp = vec[i + 1];       // 임시값을 저장하기 위한 변수에 값을 집어 넣어 놓는다.
                vec[i + 1] = vec[i];
                vec[i] = tmp;
                cout << "현재 값" << endl;
                for (int i = 0; i < vec.size(); i++) {
                    cout << vec[i] << ' ';
                }
                cout << endl << endl;

            }

        }


    }

    cout << "최종 배열 : ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << ' ';
    }
    cout << endl << endl;

}
void insertsort(vector<int> G)
{
    cout << "삽입 정렬을 시작합니다" << endl;
    for (int i = 0; i < G.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            int temp = 0;
            if (G[i] < G[j])
            {
                int temp = G[i];
                G[i] = G[j];
                G[j] = temp;
                cout << "현재 값" << endl;
                for (int i = 0; i < G.size(); i++) {
                    cout << G[i] << ' ';
                }
                cout << endl << endl;
            }
        }
    }
    cout << "현재 배열 : ";
    for (int i = 0; i < G.size(); i++)
    {
        cout << G[i] << " ";
    }
    cout << endl;
}
int partition(vector<int>& vec, int low, int high) {
    int pivot = vec[high];  // 마지막 요소를 피벗으로 선택
    int i = low - 1;  // 작은 값들의 마지막 인덱스

    for (int j = low; j < high; j++) {
        if (vec[j] <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);  // 피벗을 적절한 위치로 이동
    return i + 1;  // 피벗의 위치를 반환
}

void quickSort(vector<int>& vec, int low, int high) {
    if (low < high) {
        int pi = partition(vec, low, high);  // 분할 후 피벗의 위치 반환

        // 피벗을 기준으로 왼쪽과 오른쪽 리스트를 재귀적으로 정렬
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}

void printVector(const vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << ' ';
    }
    cout << endl;
}
int main()
{
    vector<int> vec = { 1, 5, 6, 4, 2,3 };
    cout << "정렬 전 배열: ";
    printVector(vec);

    quickSort(vec, 0, vec.size() - 1);  // 퀵 정렬 실행

    cout << "퀵 정렬 후 배열: ";
    printVector(vec);

    int Geomnal = vec.size();
    Bubblesort(vec);
    insertsort(vec);


}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
