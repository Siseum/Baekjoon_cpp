#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

int N;
int M;
int R;

int arr[300][300];
int Result[300][300];

void Simulation()
{
	int s_i = 0;
	int s_j = 0;
	int t_i = 0;
	int t_j = 0;
	int e_i = N;
	int e_j = M;
	int dir = 0;
	int Count = 0;

	while (Count < N * M)
	{
		if (dir == 0)
		{
			while (t_i < e_i - 1)
			{
				Result[t_i + 1][t_j] = arr[t_i][t_j];
				Count++;
				t_i++;
			}
			dir = 1;
		}

		else if (dir == 1)
		{
			while (t_j < e_j - 1)
			{
				Result[t_i][t_j + 1] = arr[t_i][t_j];
				Count++;
				t_j++;
			}
			dir = 2;
		}
		else if (dir == 2)
		{
			while (t_i > s_i)
			{
				Result[t_i - 1][t_j] = arr[t_i][t_j];
				Count++;
				t_i--;
			}
			dir = 3;
		}

		else if (dir == 3)
		{
			while (t_j > s_j)
			{
				Result[t_i][t_j - 1] = arr[t_i][t_j];
				Count++;
				t_j--;
			}
			dir = 0;
			s_i = s_i + 1;
			s_j = s_j + 1;
			t_i = s_i;
			t_j = s_j;
			e_i = e_i - 1;
			e_j = e_j - 1;
		}
	}
}

int main()
{
	cin >> N >> M >> R;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < R; i++)
	{
		Simulation();
		memcpy(arr, Result, sizeof(arr));
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << Result[i][j] << " ";
		cout << "\n";
	}

}
