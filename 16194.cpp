#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

int N;
int dp[1001];
int p[1001];

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> p[i];

	memset(dp, 123456789, sizeof(dp));
	dp[0] = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			dp[i] = min(dp[i], dp[i - j] + p[j]);
		}
	}

	cout << dp[N];
}
