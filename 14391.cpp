#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int map[4][4];
bool Select[4][4] = { false, };
int Row, Col, Result = 0;

void dfs(int Count) 
{
	int y = Count / Col;
	int x = Count % Col;

	if (Count == Row * Col)
	{
		int sum = 0;

		for (int i = 0; i < Row; i++)
		{
			int tSum = 0;
			for (int j = 0; j < Col; j++)
			{
				if (Select[i][j] == 1)
				{
					tSum *= 10;
					tSum += map[i][j];
				}
				else
				{
					sum += tSum;
					tSum = 0;
				}
			}
			sum += tSum;
		}

		for (int i = 0; i < Col; i++) {
			int tSum = 0;
			for (int j = 0; j < Row; j++) {
				if (Select[j][i] == 0) {
					tSum *= 10; 
					tSum += map[j][i];
				}
				else {
					sum += tSum;
					tSum = 0; 
				}
			}
			sum += tSum;
		}
		Result = max(Result, sum);
		return;
	}

	Select[y][x] = 1;
	dfs(Count + 1);
	Select[y][x] = 0;
	dfs(Count + 1);


}

int main() 
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	cin >> Row >> Col;

	string str;

	for (int i = 0; i < Row; i++) {

		cin >> str;

		for (int j = 0; j < Col; j++)

			map[i][j] = str[j] - '0';

	}

	dfs(0);

	cout << Result;

	return 0;
}
