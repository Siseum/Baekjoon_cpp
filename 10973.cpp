#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> Result;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int tempt = 0;
		cin >> tempt;
		Result.push_back(tempt);
	}

	int Index = N - 1;
	int Index2 = N - 1;

	for (Index = N - 1; Index > 0; Index--)
	{
		if (Result[Index] < Result[Index - 1])
			break;
	}

	if (Index == 0)
	{
		cout << "-1";
		return 0;
	}

	while (Index2 > Index)
	{
		if (Result[Index - 1] > Result[Index2])
		{
			break;
		}
		Index2--;
	}

	swap(Result[Index-1], Result[Index2]);

	Index2 = N - 1;

	while (Index2 > Index)
	{
		swap(Result[Index], Result[Index2]);
		Index++;
		Index2--;
	}


	for (int i = 0; i < N; i++)
	{
		cout << Result[i] << " ";
	}

}
