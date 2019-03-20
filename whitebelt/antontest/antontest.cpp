// antontest.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int q, daynum;
	cin >> q;

	int days_in_months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int current_month = 0;

	vector<string> month_plan(days_in_months[current_month % 11]);
	string carry_tasks;

	//cout << endl;

	for (int i = 0; i < q; ++i) {
		int days_difference = days_in_months[current_month+1] - days_in_months[current_month];
		string operation_code;
		cin >> operation_code;

		if (operation_code == "ADD") {
			cin >> daynum;
			string task;
			cin >> task;
			month_plan[daynum-1] += (task);
			month_plan[daynum-1] += (" ");
		}	//end of the ADD operation

		else {
			if (operation_code == "DUMP") {
				cin >> daynum;
				if (month_plan[daynum-1].front() == ' ') {	//в некоторых случаях добавляется
					month_plan[daynum-1].erase(0,1);	//пробел перед делами. эти строки его удаляют.
				};
				cout << count(begin(month_plan[daynum-1]), end(month_plan[daynum-1]), ' ') << " ";
				while (month_plan[daynum-1].back() == ' ') {	//ищем последний пробел в строке
					month_plan[daynum-1].pop_back();		//удаляем последний пробел
				}
				cout << month_plan[daynum-1] << endl;
				month_plan[daynum-1].push_back(' ');		//добавляем последний пробел, чтобы потом все хорошо склеивалось
			}   //end of the DUMP operation

			else if (operation_code == "NEXT") {
				if (days_difference >= 0) {
					month_plan.resize(month_plan.size() + days_difference);
					current_month = ((current_month + 1) % 11);		//переход года с помощью %
				} else if (days_difference < 0){
					//string carry_tasks; //перенести дела с последних дней месяца
					for (int j = 0; j < abs(days_difference); j++){
						carry_tasks += month_plan[month_plan.size()-j];
					}
					month_plan[days_in_months[(current_month + 1) % 11]-1] += carry_tasks;
					carry_tasks = "";	//обнуляем строку переносимых дел
					month_plan.resize(month_plan.size() + days_difference);
					current_month = ((current_month + 1) % 11);		//переход года с помощью %
				}		//end of th else if
			}    //end of the NEXT operation
		} 	//end of the else for dump or next operations
	}		//end of the for (i) loop
	return 0;
}

