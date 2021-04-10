#include <iostream>
#include <algorithm>

using namespace std;

int N;
int Result;
int Mod = 10007;
int dp[1001][10];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % Mod;
			}
		}
	}

	for (int i = 0; i < 10; i++)
		Result = (Result + dp[N][i]) % Mod;

	cout << Result;
}
