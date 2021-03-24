#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int Result;
vector<int> v;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int tempt = 0;
		cin >> tempt;
		v.push_back(tempt);
	}

	sort(v.begin(), v.end());
	
	while (next_permutation(v.begin(), v.end()))
	{
		int tempt = 0;
		for (int i = N-1; i > 0; i--)
		{
			tempt = tempt + abs(v[i] - v[i - 1]);
		}
		Result = max(Result, tempt);
	}

	cout << Result;

}
