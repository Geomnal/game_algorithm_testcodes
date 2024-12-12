#include<iostream>

using namespace std;

int main()
{

    string parent = "Hello world";

    string target = "world";

    int parent_hash = 0;
    int target_hash = 0;

    //pow 는 power(제곱)의 약자, 2^0 = 1 
    int pow = 1;
    for (int i = 1; i < target.size(); i++) {
        pow = pow * 2;
    }

    int pow_or = pow; // 제곱값 저장해놓기, power_original 약자.


    // target의 hash값 구하기. 아래 수식의 t는 target의 약자.
    // t[0] * 2^4 + t[1] * 2^3 + t[2] * 2^2 + t[3] * 2^1 + t[4] * 2^0;
    int tmp = 0;
    for (int i = 0; i < target.size(); i++)
    {
        tmp = target[i];
        cout << target[i] << " : " << tmp << endl;

        target_hash = target_hash + target[i] * pow;
        pow = pow / 2;

        cout << target_hash << endl;

    }
    cout << endl << endl << endl;


    // 문자열에서 첫번째 해쉬값 찾기.
    pow = pow_or;

    for (int i = 0; i < target.size(); i++)
    {
        tmp = parent[i];
        cout << parent[i] << " : " << tmp << endl;

        parent_hash = parent_hash + parent[i] * pow;
        pow = pow / 2;

        cout << parent_hash << endl;

    }

    for (int i = 1; i <= parent.size() - target.size(); i++)
    {
        tmp = parent[target.size() - 1 + i];

        cout << parent[target.size() - 1 + i] << " : " << tmp << endl;

        parent_hash = 2 * (parent_hash - parent[i - 1] * pow_or) + parent[target.size() - 1 + i];
        cout << "현재 해쉬 값은 : " << parent_hash << endl << endl;
        if (parent_hash == target_hash)
        {
            cout << "동일한 hash 값을 찾았습니다." << endl;
        }
    }


}