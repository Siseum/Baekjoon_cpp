#include <iostream>
#include <algorithm>

using namespace std;

int arr[300][300];
int N;
int M;
int R;

void Simulation(int start, int len, int en, int em)
{
	int Starti = start;
	int Startj = start;
	int plusCount = R % len;
	int Count = 0;
	int dir = 0;

	for (int i = 0; i < plusCount; i++)
	{
		int tempti = Starti;
		int temptj = Startj;
		Count = 0;
		int tempt1 = arr[Starti][Startj];
		int tempt2 = 0;
		while (Count < len)
		{
			if (dir == 0)
			{
				while (tempti < en - 1)
				{
					tempt2 = arr[tempti + 1][temptj];
					arr[tempti + 1][temptj] = tempt1;
					tempt1 = tempt2;
					Count++;
					tempti++;
				}
				dir = 1;
			}

			else if (dir == 1)
			{
				while (temptj < em - 1)
				{
					tempt2 = arr[tempti][temptj + 1];
					arr[tempti][temptj + 1] = tempt1;
					tempt1 = tempt2;
					Count++;
					temptj++;
				}
				dir = 2;
			}
			else if (dir == 2)
			{
				while (tempti > Starti)
				{
					tempt2 = arr[tempti - 1][temptj];
					arr[tempti - 1][temptj] = tempt1;
					tempt1 = tempt2;
					Count++;
					tempti--;
				}
				dir = 3;
			}

			else if (dir == 3)
			{
				while (temptj > Startj)
				{
					tempt2 = arr[tempti][temptj - 1];
					arr[tempti][temptj - 1] = tempt1;
					tempt1 = tempt2;
					Count++;
					temptj--;
				}
				dir = 0;
			}
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

	int Count = min(N, M) / 2;

	int cn = N;
	int cm = M;

	int en = N;
	int em = M;

	for (int i = 0; i < Count; i++)
	{
		int len = cn * 2 + (cm - 2) * 2;
		Simulation(i, len, en, em);
		en = en - 1;
		em = em - 1;
		cn = cn - 2;
		cm = cm - 2;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
}
