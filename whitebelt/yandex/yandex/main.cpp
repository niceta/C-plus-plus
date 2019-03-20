#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <math.h>

using namespace std;

int s(int k)
{
	int sum = 0;
	while (k > 0) {
		sum += k % 10;
		k /= 10;
	}
	return sum;
}

bool isHard(int n)
{
	for (int k = 1; k < 9e+10; ++k)// смотри примечание!*
	{
		if (n * (s(k) + 1) == k + 1)
		{
			//qDebug()<<n;
			return false;
		}
		if (k >9e+10 - 1)
			break;
	}
	//qDebug()<<n;
	return true;
}
void B() {
	bool ok = true;
	int n = 1;
	while (!isHard(n))
	{
		++n;
	}

	cout << n;
	cin >> n;
}

void A() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a)
		cin >> i;

	int sumP = 0;
	int sumV = 0;

	int i = 0;
	
	sumP += a[0];
	sumV += a[1];
	
	int prevCardV = sumV;
	int prevCardP = sumP;

	for (i = 2; i < n; ++i) {
		if (prevCardP > prevCardV) {
			sumP += a[i];
			prevCardP = a[i];
		}
		else {
			sumV += a[i];
			prevCardV = a[i];
		}
	}

	if (sumP > sumV)
		cout << "Vasya";
	else
		cout << "Petya"; 
}

void C()
{
	string command;
	vector<string> resultTable;
	while (getline(cin, command))
	{
		stringstream stream(command);
		string name;
		stream >> name;
		if (name == "Result") {
			stream >> name;
		}
	}
}

void E()
{
	int n, a;
	cin >> n >> a;
	int kol2 = 0;
	int kol3 = 0;
	int kol4 = 0;
	int kol5 = 0;

	if (n % 2 == 0 && a != 2)
	{
		kol2 = n / 2;
		cout << pow(2, kol2) << endl;
		return;
	}
	else if (n % 2 != 0 && a != 2 && a != 3)
	{
		kol2 = n / 2 - 1;
		kol3 = 1;
		cout << pow(2, kol2) * 3 << endl;
		return;
	}
	else if (n % 2 == 0 && a == 2)
	{
		if (n % 3 == 0)
		{
			cout << pow(3, n / 3) << endl;
			return;
		}
		else if (n % 3 != 2 && and)
	}

}

int main()
{
	int k = 12345;
	
	C();

	cin >> k;
	return 0;
}