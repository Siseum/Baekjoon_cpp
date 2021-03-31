#include <iostream>
#include <algorithm>

using namespace std;

int T;


int main() 
{
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;

		long long dp[12] = { 0, };
		dp[1] = 1, dp[2] = 2, dp[3] = 4;

		for (int i = 4; i <= N; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		cout << dp[N] << endl;
	}
}
