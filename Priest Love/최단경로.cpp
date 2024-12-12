#include <iostream>
#include <queue>

using namespace std;

const int INF = 999999;

vector<pair<int, int>> arr[20001];
int d[20001];
int route[20001];

int main() {

	int V = 5;
	int E = 6;
	int K = 1;

	int cost = 0;

	////======================제출==================
	//// 테스트를 원하면 이 부분을 주석처리 하고, ===테스트==를 주석 해제하세요

	//cin >> V >> E >> K;
	//int a = 0;
	//int b = 0;

	//for (int i = 0; i < E; i++) {
	//	cin >> a >> b >> cost;
	//	arr[a].push_back({ cost,b });
	//}
	////==================================================================


	// ===============테스트===========

	arr[5].push_back({ 1,1 });
	arr[1].push_back({ 2,2 });
	arr[1].push_back({ 3,3 });
	arr[2].push_back({ 4, 3 });
	arr[2].push_back({ 5, 4 });
	arr[3].push_back({ 6, 4 });
	//==============================

	for (int i = 1; i <= V; i++) {
		d[i] = INF;
	}

	//우선순위 queue, 값이 낮은 순서대로 저장.
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({ 0, K });
	d[K] = 0;
	route[K] = K;

	int cur_cost = 0;
	int cur_pos = 0;

	while (!pq.empty())
	{
		cur_cost = pq.top().first;
		cur_pos = pq.top().second;

		pq.pop();


		for (int i = 0; i < arr[cur_pos].size(); i++)
		{

			int next_cost = arr[cur_pos][i].first;
			int next_pos = arr[cur_pos][i].second;

			//기존값 > 현재 비용 + 다음 이동 비용
			if (d[next_pos] > cur_cost + next_cost)
			{
				d[next_pos] = cur_cost + next_cost;
				pq.push({ d[next_pos], next_pos });
				route[next_pos] = cur_pos;
			}
		}
	}


	for (int i = 1; i <= V; i++) {
		if (d[i] == INF) {
			cout << "INF" << endl;
		}
		else {
			cout << d[i] << endl;
		}

	}
	cout << endl;


	int target = 4;

	cout << endl;
	cout << target << " -> ";

	while (target != K)
	{
		target = route[target];
		if (target == K)
		{
			cout << target << endl;
		}
		else {

			cout << target << " -> ";
		}
	}





}