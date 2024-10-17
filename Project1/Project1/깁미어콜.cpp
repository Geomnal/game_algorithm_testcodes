#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std; //std 유기할게~


bool solution(vector<string> phone_book)
{
    bool answer = true; // 기본값은 true;

    unordered_map<string, int> hash; //hash 소환

    for (int i = 0; i < phone_book.size(); i++) // hash의 key값에 phone_book 넣기
    {
        hash[phone_book[i]] = 1; //119,97674223,1195524421이 저장된다.
    }

    for (int i = 0; i < phone_book.size(); i++) { 
        string number = ""; //확인용 string 변수 시전

        for (int j = 0; j < phone_book[i].size(); j++) 
        {
            number = number + phone_book[i][j]; //루프 돌때마다 1글자씩 추가. ex ) 1,11,119,1195,11955

            if (hash[number] && (phone_book[i] != number)) //hash에서 number과 같은 값이 있는 지 확인, 그리고 자신이 아니여야함. 현재 검사한 값과
                // 내가 저장한 값이 같으면 안됨
                answer = false; // 조건에 맞다면 false 반환.
        }
    }
    return answer;
}
int main()
{
    vector<string> phone_book = { "119", "97674223", "1195524421" };
    bool exit = solution(phone_book);
    cout << "접두어 유무 : " << exit;
}