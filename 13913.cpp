#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int K;
queue<pair<int,int>> q;
vector<int> vRoute;
bool visit[100001];
int route[100001];
int Count;

void bfs()
{
	while (!q.empty())
	{
		int tempt = q.front().first;
		Count = q.front().second;

		q.pop();

		if (tempt == K)
		{
			vRoute.push_back(tempt);
			while (tempt != N)
			{
				vRoute.push_back(route[tempt]);
				tempt = route[tempt];
			}

			return;
		}
			

		if (tempt * 2 <= 100000 && visit[tempt * 2] == false)
		{
			visit[tempt * 2] = true;
			route[tempt * 2] = tempt;
			q.push(pair<int, int>(tempt * 2, Count + 1));
		}
		if (tempt - 1 >= 0 && visit[tempt - 1] == false)
		{
			visit[tempt - 1] = true;
			route[tempt - 1] = tempt;
			q.push(pair<int, int>(tempt - 1, Count + 1));
		}
		if (tempt + 1 <= 100000 && visit[tempt + 1] == false)
		{
			visit[tempt + 1] = true;
			route[tempt + 1] = tempt;
			q.push(pair<int, int>(tempt + 1, Count + 1));
		}
	}
}

int main()
{
	cin >> N >> K;

	q.push(pair<int, int>(N, 0));
	visit[N] = true;

	bfs();

	cout << Count << "\n";
	
	for (int i = vRoute.size() - 1; i >= 0; i--)
		cout << vRoute[i] << " ";

}
