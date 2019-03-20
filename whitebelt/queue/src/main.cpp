#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int n, size,
		worryNum, quietNum;

	vector<int> queue;
	queue.clear();

	cin >> n;

	for (size_t i = 0; i < n; ++i)
	{
		string curCom;
		cin >> curCom;

		if (curCom == "COME")
		{
			cin >> size;
			queue.resize(queue.size() + size);

			if (size > 0)
			{
				for (size_t k = (queue.size() - size); k < queue.size(); ++k)
					queue[k] = 0;
			}
		}

		if (curCom == "WORRY")
		{
			cin >> worryNum;
			queue[worryNum] = 1;
		}

		if (curCom == "QUIET")
		{
			cin >> quietNum;
			queue[quietNum] = 0;
		}

		if (curCom == "WORRY_COUNT")
		{
			int worry = 0;
			for (auto x : queue)
			{
				if (x == 1)
					++worry;
			}
			cout << worry << endl;
		}

	}
	return 0;
}
