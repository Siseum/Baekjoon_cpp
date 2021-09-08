#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N = 0;
	int num = 0;

	cin >> N;
	
	priority_queue<int> maxHeap;
	priority_queue<int,vector<int>, greater<int>> minHeap;
	
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (maxHeap.size() == minHeap.size())
			maxHeap.push(num);
		else
			minHeap.push(num);

		if (!minHeap.empty() && !maxHeap.empty() && maxHeap.top() > minHeap.top())
		{
			int n1 = maxHeap.top();
			int n2 = minHeap.top();

			maxHeap.pop();
			minHeap.pop();

			maxHeap.push(n2);
			minHeap.push(n1);
		}

		cout << maxHeap.top() << '\n';
	}

}
