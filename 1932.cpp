#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[501][501];
int dp[501][501];
int Result;

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j == 1)
			{
				dp[i][j] = dp[i - 1][j] + arr[i][j];
			}

			else if (j == i)
			{
				dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
			}

			else
			{
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
			}

			Result = max(Result, dp[i][j]);
		}
	}

	cout << Result;

}
