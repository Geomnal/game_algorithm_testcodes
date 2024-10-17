#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std; //std �����Ұ�~


bool solution(vector<string> phone_book)
{
    bool answer = true; // �⺻���� true;

    unordered_map<string, int> hash; //hash ��ȯ

    for (int i = 0; i < phone_book.size(); i++) // hash�� key���� phone_book �ֱ�
    {
        hash[phone_book[i]] = 1; //119,97674223,1195524421�� ����ȴ�.
    }

    for (int i = 0; i < phone_book.size(); i++) { 
        string number = ""; //Ȯ�ο� string ���� ����

        for (int j = 0; j < phone_book[i].size(); j++) 
        {
            number = number + phone_book[i][j]; //���� �������� 1���ھ� �߰�. ex ) 1,11,119,1195,11955

            if (hash[number] && (phone_book[i] != number)) //hash���� number�� ���� ���� �ִ� �� Ȯ��, �׸��� �ڽ��� �ƴϿ�����. ���� �˻��� ����
                // ���� ������ ���� ������ �ȵ�
                answer = false; // ���ǿ� �´ٸ� false ��ȯ.
        }
    }
    return answer;
}
int main()
{
    vector<string> phone_book = { "119", "97674223", "1195524421" };
    bool exit = solution(phone_book);
    cout << "���ξ� ���� : " << exit;
}