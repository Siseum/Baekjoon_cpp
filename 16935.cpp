#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

int N;
int M;
int arr[101][101];
int Result[101][101];

void Simulation(int Select)
{
	if (Select == 1)
	{

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
				Result[i][j] = arr[N + 1 - i][j];
		}
	}

	else if (Select == 2)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
				Result[i][j] = arr[i][M + 1 - j];
		}
	}

	else if (Select == 3)
	{
		for (int i = 1; i <= M; i++)
		{
			for (int j = 1; j <= N; j++)
				Result[i][j] = arr[N + 1 - j][i];
		}
		int t_m = M;
		int t_n = N;

		M = t_n;
		N = t_m;
	}

	else if (Select == 4)
	{
		for (int i = 1; i <= M; i++)
		{
			for (int j = 1; j <= N; j++)
				Result[i][j] = arr[j][M+1-i];
		}
		int t_m = M;
		int t_n = N;

		M = t_n;
		N = t_m;
	}

	else if (Select == 5)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (i <= N / 2 && j <= M / 2)
					Result[i][j] = arr[i + N / 2][j];
				else if (i <= N / 2 && j > M / 2)
					Result[i][j] = arr[i][j - M / 2];
				else if (i > N / 2 && j <= M / 2)
					Result[i][j] = arr[i][j + M / 2];
				else if (i > N / 2 && j > M / 2)
					Result[i][j] = arr[i - N / 2][j];
			}
		}
	}

	else if (Select == 6)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (i <= N / 2 && j <= M / 2)
					Result[i][j] = arr[i][j + M / 2];
				else if (i <= N / 2 && j > M / 2)
					Result[i][j] = arr[i + N / 2][j];
				else if (i > N / 2 && j <= M / 2)
					Result[i][j] = arr[i - N / 2][j];
				else if (i > N / 2 && j > M / 2)
					Result[i][j] = arr[i][j - M / 2];
			}
		}
	}
}

int main()
{
	int Count = 0;
	int Select = 0;
	cin >> N >> M >> Count;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < Count; i++)
	{
		cin >> Select;

		Simulation(Select);

		memcpy(arr, Result, sizeof(arr));
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			cout << Result[i][j] << " ";
		cout << "\n";
	}
}
