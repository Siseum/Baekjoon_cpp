#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int M;
int Count;

int arr[1001][1001];
bool visit[1001];

void dfs(int Start)
{
	for (int i = 1; i <= N; i++)
	{
		if (arr[Start][i] == 1 && visit[i] == false)
		{
			visit[i] = true;
			dfs(i);
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 1; i <= M; i++)
	{
		int a = 0;
		int b = 0;
		cin >> a >> b;

		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		if (visit[i] == false)
		{
			Count++;
			dfs(i);
		}
	}

	cout << Count;
}
