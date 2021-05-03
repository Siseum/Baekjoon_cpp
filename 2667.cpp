#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
char arr[25][25];
bool visit[25][25];
queue<pair<int,int>> q;
int Count;
vector<int>CountVector;

void bfs(int i, int j)
{
	Count++;
	int temptCount = 0;
	pair<int, int> qpair;
	qpair.first = i;
	qpair.second = j;
	visit[i][j] = true;
	q.push(qpair);

	while (!q.empty())
	{
		int t_i = q.front().first;
		int t_j = q.front().second;

		// 위
		if (t_i - 1 >=0 && arr[t_i - 1][t_j] == '1' && visit[t_i - 1][t_j] == false)
		{
			visit[t_i - 1][t_j] = true;
			qpair.first = t_i - 1;
			qpair.second = t_j;
			q.push(qpair);
		}

		// 아래
		if (t_i + 1 < N && arr[t_i + 1][t_j] == '1' && visit[t_i + 1][t_j] == false)
		{
			visit[t_i + 1][t_j] = true;
			qpair.first = t_i + 1;
			qpair.second = t_j;
			q.push(qpair);
		}

		// 왼쪽
		if (t_j - 1 >= 0 && arr[t_i][t_j - 1] == '1' && visit[t_i][t_j - 1] == false)
		{
			visit[t_i][t_j - 1] = true;
			qpair.first = t_i;
			qpair.second = t_j - 1;
			q.push(qpair);
		}

		//오른쪽
		if (t_j + 1 < N && arr[t_i][t_j + 1] == '1' && visit[t_i][t_j + 1] == false)
		{
			visit[t_i][t_j + 1] = true;
			qpair.first = t_i;
			qpair.second = t_j + 1;
			q.push(qpair);
		}

		q.pop();
		temptCount++;
	}

	CountVector.push_back(temptCount);
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == '1' && visit[i][j] == false)
				bfs(i, j);
		}
	}


	sort(CountVector.begin(), CountVector.end());

	cout << Count << "\n";

	for (int i = 0; i < Count; i++)
		cout << CountVector[i] << "\n";

}
