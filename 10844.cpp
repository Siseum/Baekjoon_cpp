#include <iostream>
#include <algorithm>

using namespace std;

int N;
int Mod = 1e9;
long long dp[101][10];


int main()
{
	cin >> N;

	for (int i = 1; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			if (j == 0)
				dp[i][j] = (dp[i - 1][1]) % Mod;

			else if (j == 9)
				dp[i][j] = (dp[i - 1][8]) % Mod;

			else
			{
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % Mod;
			}
		}
	}

	long long Result = 0;

	for (int i = 0; i < 10; i++)
		Result += dp[N][i] % Mod;
	cout << Result % Mod;
}
