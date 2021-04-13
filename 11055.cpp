#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1001];
int dp[1001];
int Result;

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	for (int i = 1; i <= N; i++)
	{
		for (int j = i - 1; j >= 1; j--)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = max(dp[i], dp[j]);
			}

		}
		dp[i] += arr[i];
		Result = max(Result, dp[i]);
	}
	cout << Result;
}
