#include <iostream>
#include <algorithm>

using namespace std;

int N;
int K;
int Mod = 1000000000;
long long dp[201][201];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i <= N; i++)
		dp[1][i] = 1;

	for (int k = 2; k <= K; k++)
	{
		for (int n = 0; n <= N; n++)
		{
			for (int i = 0; i <= n; i++)
			{
				dp[k][n] = (dp[k][n] + dp[k - 1][i]) % Mod;
			}
			
		}
	}

	cout << dp[K][N];
}
