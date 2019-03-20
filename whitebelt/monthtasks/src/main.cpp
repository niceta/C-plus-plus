#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct day
{
	int num;
	vector<string> tasks;
};

void fillVec(vector<day> &v, int begin, int end)
{
	for (int i = begin; i <= end; ++i)
	{
		v[i].num = i + 1;
	}
}

int main()
{
	vector<day> days(31);
	fillVec(days, 0, 30);

	int currentMonth = 1;
	int numOper;

	cin >> numOper;

	for (int i = 0; i < numOper; ++i)
	{
		string curOper;
		cin >> curOper;

		if (curOper == "ADD")
		{
			int k;
			string task;
			cin >> k >> task;
			days[k - 1].tasks.push_back(task);
		}

		if (curOper == "NEXT")
		{
			++currentMonth;

			if (currentMonth > 12)
				currentMonth = 1;

			vector<string> temp;
			temp.clear();

			int prevSize = days.size();

			if (currentMonth == 2)
			{
				for (int k = 28; k < prevSize; ++k)
					temp.insert(temp.end(), days[k].tasks.begin(),
											days[k].tasks.end());

				days.resize(28);
			}

			bool cond = ((currentMonth % 2 == 1) && currentMonth < 8) ||
						((currentMonth % 2 == 0) && currentMonth >= 8);

			if (cond)
			{
				days.resize(31);
				fillVec(days, prevSize, days.size());
			}

			if (!cond && currentMonth != 2)
			{
				temp.insert(temp.end(), days[days.size() - 1].tasks.begin(),
										days[days.size() - 1].tasks.end());

				days.resize(30);
			}

			days[days.size() - 1].tasks.insert(days[days.size() - 1].tasks.end(),
											   temp.begin(), temp.end());
		}

		if (curOper == "DUMP")
		{
			int k;
			cin >> k;

			cout << days[k - 1].tasks.size() << " ";
			for (auto x : days[k - 1].tasks)
			{
				cout << x << " ";
			}

			cout << endl;
		}
	}

	return 0;
}
