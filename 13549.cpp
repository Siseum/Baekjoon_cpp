#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int K;
int Count = 1234567890;
queue<pair<int, int>> que;
bool visit[200001];

void bfs()
{
	while (!que.empty())
	{
		int tempt = que.front().first;
		Count = que.front().second;

		if (tempt == K)
			return;

		que.pop();


		if (tempt * 2 < 200001 && visit[tempt * 2] == false)
		{
			visit[tempt * 2] = true;
			que.push({ tempt * 2,Count });
		}

		if (tempt - 1 >= 0 && visit[tempt - 1] == false)
		{
			visit[tempt - 1] = true;
			que.push({ tempt - 1,Count + 1 });
		}

		if (tempt + 1 < 200001 && visit[tempt + 1] == false)
		{
			visit[tempt + 1] = true;
			que.push({ tempt + 1,Count + 1 });
		}


	}

}


int main()
{
	cin >> N >> K;

	visit[N] = true;
	que.push({ N,0 });

	bfs();

	cout << Count;
}
