#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int V;
int E;
vector<int> arr[20001];
int graph[20001] = { 0, };
bool is_end = false;

void dfs(int Start, int color)
{
	if (color == 1)
		color = 2;
	else
		color = 1;

	for (int i = 0; i < arr[Start].size(); i++)
	{
		int index = arr[Start][i];
		if (graph[Start] == graph[index])
		{
			is_end = true;
			return;
		}

		if (graph[index] == 0 && graph[Start] != graph[index])
		{
			graph[index] = color;
			dfs(index, color);
		}
	}
}

int main()
{
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		for (int i = 0; i < 20001; i < i++)
		{
			graph[i] = 0;
			arr[i].clear();
		}

		int color = 1;
		is_end = false;

		cin >> V >> E;

		for (int i = 0; i < E; i++)
		{
			int a = 0;
			int b = 0;

			cin >> a >> b;

			arr[a].push_back(b);
			arr[b].push_back(a);
		}

		for (int i = 1; i <= V; i++)
		{
			if (is_end)
				break;
			if (graph[i] == 0)
			{
				graph[i] = color;
				dfs(i, color);
			}
		}
		
		if (is_end)
			cout << "NO" << "\n";
		else
			cout << "YES" << "\n";

	}

}
