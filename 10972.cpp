#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
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

	int index = N - 1;

	while (index > 0 && v[index - 1] > v[index])
		index--;

	if (index == 0)
	{
		cout << -1;
		return 0;
	}

	int index2 = N - 1;

	while (v[index - 1] >= v[index2])
		index2--;

	swap(v[index - 1], v[index2]);
	index2 = N - 1;

	while (index < index2)
	{
		swap(v[index], v[index2]);
		index++;
		index2--;
	}

	for (int i = 0; i < N; i++)
		cout << v[i] << ' ';

}
