#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int arr[100001];
int dp[100001];


int main()
{
	int Result = 0;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	dp[1] = arr[1];
	Result = dp[1];

	for (int i = 2; i <= N; i++)
	{
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		Result = max(Result, dp[i]);
	}

	cout << Result;

}

