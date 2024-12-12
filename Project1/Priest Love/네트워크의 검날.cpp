#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[1001];

/*
int find_union(int parent[], int n) // �ڽ��� ���� ������ ��ǥ ���Ҹ� ã�� ����.
{
    if (parent[n] == n)
    {
        return n;
    }
    parent[n] = find_union(parent, parent[n]);
    return parent[n];
}
*/

int find_union(int parent[], int n)
{
    if (parent[n] = n)
    {
        return n;
    }
    parent[n] = find_union(parent, parent[n]);
    return parent[n];
}


/*
void make_union(int parent[], int n, int m) // �ΰ��� ������ �������� �����ϱ� ���� ����.
{
    int a = find_union(parent, n);
    int b = find_union(parent, m);

    if (b > a)
    {
        parent[b] = a;
    }
    else
    {
        parent[a] = b;
    }

}

*/
void make_union(int parent[], int n, int m)
{
    int a = find_union(parent, n);
    int b = find_union(parent, m);
    if (b > a)
    {
        parent[b] = a;
    }
    else
    {
        parent[a] = b;
    }
}
int main()
{
    int N = 6;
    int M = 9;

    int x = 0;
    int y = 0;
    int cost = 0;

    int answer = 0;

    vector<pair<int, pair<int, int>>> vec;


    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    //�Է��� �޴´�. {���, {a, b}} ���·� �Է��� �޴´�.
    vec.push_back({ 5,{1,2} });
    vec.push_back({ 4,{1,3} });
    vec.push_back({ 2,{2,3} });
    vec.push_back({ 7,{2,4} });
    vec.push_back({ 6,{3,4} });
    vec.push_back({ 11,{3,5} });
    vec.push_back({ 3,{4,5} });
    vec.push_back({ 8,{4,6} });
    vec.push_back({ 8,{5,6} });

    sort(vec.begin(), vec.end()); // ����� �������� �����Ѵ�.

    for (int i = 0; i < vec.size(); i++)
    {

        int n = 0;
        int m = 0;
        n = vec[i].second.first;
        m = vec[i].second.second;

        if (find_union(parent, n) != find_union(parent, m)) //���μ� �������� Ȯ���ϴ� ����
        {
            make_union(parent, n, m);
            answer = answer + vec[i].first;
        }

    }


    cout << answer << endl;


}