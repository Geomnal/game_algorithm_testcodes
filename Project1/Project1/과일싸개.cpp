#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, int m, vector<int> score)
{
    vector<int> box;
    int answer = 0;
    sort(score.begin(), score.end());
    while(score.size() >= m)
    {
        for (int i = 0; i < m; i++)
        {
            if (i == m - 1)
            {
                int tmp = score.back();
                box.push_back(tmp);
            }
            score.pop_back();
        }
    }

    for (int i = 0; i < box.size(); i++)
    {
        answer = answer + box[i] * m;
    }
    return answer;
}

int main()
{
    int k = 3;
    int m = 4;
    vector<int> score = { 1,2,3,1,2,3,1 };

    int result = solution(k, m, score);
    cout << result << endl;

}