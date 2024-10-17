// ConsoleApplication5.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>
#include <vector>
#include <format>
using namespace std;
void Bubblesort(vector<int> vec)
{
    cout << "���� ������ �����մϴ�" << endl;
    int tmp; // temporaray �Ͻ�����, �ӽð��� �����ϱ� ���� ����

    for (int k = vec.size() - 1; k > 0; k--)/// vec.size() - 1�� ����, å������ for(int k=0; k<vec.size()-1; k++)
        ///                                  for(int i=0; i<vec.size() - (k+1); i++) �̷��� ����
    {

        for (int i = 0; i < k; i++)
        {


            if (vec[i] > vec[i + 1])
            {

                tmp = vec[i + 1];       // �ӽð��� �����ϱ� ���� ������ ���� ���� �־� ���´�.
                vec[i + 1] = vec[i];
                vec[i] = tmp;
                cout << "���� ��" << endl;
                for (int i = 0; i < vec.size(); i++) {
                    cout << vec[i] << ' ';
                }
                cout << endl << endl;

            }

        }


    }

    cout << "���� �迭 : ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << ' ';
    }
    cout << endl << endl;

}
void insertsort(vector<int> G)
{
    cout << "���� ������ �����մϴ�" << endl;
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
                cout << "���� ��" << endl;
                for (int i = 0; i < G.size(); i++) {
                    cout << G[i] << ' ';
                }
                cout << endl << endl;
            }
        }
    }
    cout << "���� �迭 : ";
    for (int i = 0; i < G.size(); i++)
    {
        cout << G[i] << " ";
    }
    cout << endl;
}
int partition(vector<int>& vec, int low, int high) {
    int pivot = vec[high];  // ������ ��Ҹ� �ǹ����� ����
    int i = low - 1;  // ���� ������ ������ �ε���

    for (int j = low; j < high; j++) {
        if (vec[j] <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);  // �ǹ��� ������ ��ġ�� �̵�
    return i + 1;  // �ǹ��� ��ġ�� ��ȯ
}

void quickSort(vector<int>& vec, int low, int high) {
    if (low < high) {
        int pi = partition(vec, low, high);  // ���� �� �ǹ��� ��ġ ��ȯ

        // �ǹ��� �������� ���ʰ� ������ ����Ʈ�� ��������� ����
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
    cout << "���� �� �迭: ";
    printVector(vec);

    quickSort(vec, 0, vec.size() - 1);  // �� ���� ����

    cout << "�� ���� �� �迭: ";
    printVector(vec);

    int Geomnal = vec.size();
    Bubblesort(vec);
    insertsort(vec);


}

// ���α׷� ����: <Ctrl+F5> �Ǵ� [�����] > [��������� �ʰ� ����] �޴�
// ���α׷� �����: <F5> Ű �Ǵ� [�����] > [����� ����] �޴�

// ������ ���� ��: 
//   1. [�ַ�� Ž����] â�� ����Ͽ� ������ �߰�/�����մϴ�.
//   2. [�� Ž����] â�� ����Ͽ� �ҽ� ��� �����մϴ�.
//   3. [���] â�� ����Ͽ� ���� ��� �� ��Ÿ �޽����� Ȯ���մϴ�.
//   4. [���� ���] â�� ����Ͽ� ������ ���ϴ�.
//   5. [������Ʈ] > [�� �׸� �߰�]�� �̵��Ͽ� �� �ڵ� ������ ����ų�, [������Ʈ] > [���� �׸� �߰�]�� �̵��Ͽ� ���� �ڵ� ������ ������Ʈ�� �߰��մϴ�.
//   6. ���߿� �� ������Ʈ�� �ٽ� ������ [����] > [����] > [������Ʈ]�� �̵��ϰ� .sln ������ �����մϴ�.
