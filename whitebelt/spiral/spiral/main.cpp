#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <math.h>
using namespace std;

void problem1() {
	int n = 1169;

	int s = n / 2;

	long int amount = 1;
	long int step = 2;
	long int i = 0;
	long int value = 1;
	while (i < s) {
		for (int k = 0; k < 4; ++k) {
			value += step;
			amount += value;
		}
		step += 2;
		++i;
	}
	cout << amount << endl;
}

bool isSimple(const int n) {
	if (n == 1)
		return false;
	for (int i = 2; i < sqrt(n) + 1; ++i) {
		if (n % i == 0)
			return false;
	}
	return true;
}



int reverseNum(int value) {
	int temp = 0;
	while (value > 0) {
		temp = 10 * temp + value % 10;
		value /= 10;
	}
	return temp;
}

bool isPalindrom(int value) {
	if (value == reverseNum(value))
		return true;
	else
		return false;
}

void problem3() {
	int k = 0;
	int value;
	for (int i = 1; i < 13739; ++i) {
		value = i;
		for (int j = 1; j <= 50; ++j) {
			int temp = value + reverseNum(value);
			if (isPalindrom(temp)) {
				++k;
				break;
			} else {
				value = temp;
			}
		}
	}

	cout << 13739 - k << endl;
}

void problem4() {
	set<long> res;
	int a = 142;
	int b = 106;

	for (int i = 3; i < a; ++i) {
		for (int j = 3; j < b; ++j) {
			long temp = (long)pow(i, j);
			res.insert(temp);
		}
	}
	cout << res.size() << endl;
}

//int a[10];
vector<int> a;
set<int> simpleNums;
/*
n - осталось набрать слагаемых на сумму n
k - слагаемые не больше k
i - номер очередного слагаемого

В массиве a, начиная с i-го элемента, перебрать все возможные
варианты разложения числа n на слагаемые, не превосходящие k.
*/
int dec(int n, int k, int i, int s) {
	// не нашли ни одного разложения в простые числа, вернем 0
	if (n < 0) /*|| n < k)*/ {
		a.clear();
		return 0;
	}
	if (n == 0) {
		// Просьба разложить 0 означает, что раскладывать уже нечего и
		// и уже нет остаточного значения, котрое нужно разложить.
		// Значит в массиве {a[0], a[1], ... a[i-1]} находится некоторое готовое разложение
		// исходного числа n = m.
		
		if (a.size() == s) {
			int j;
			set<bool> isOk;
			for (j = 0; j < i; j++) {
				//printf("%d ", a[j]);
				if (simpleNums.count(a[j]) == 1)
					isOk.insert(true);
				else
				{
					isOk.insert(false);
					break;
				}				
			}
			// если все элементы разложения - простые числа, вернем 1
			if (isOk.size() == 1 && isOk.count(true) == 1) {
				a.clear();
				throw 1;
			}
			//printf("\n");
		}
		else
			// разложение не подошло - очистим массив
			a.clear();
	}
	else {
		if (n - k >= 0) {
			//a[i] = k; // фиксируем i-ое слагаемое
			a.push_back(k);
			dec(n - k, k, i + 1, s);
		}

		if (k - 1 > 0) {
			dec(n, k - 1, i, s);
		}
	}
	a.clear();
	return 0;
}

void problem22() {
	for (int i = 2; i <= 15890; ++i) {
		if (isSimple(i))
			simpleNums.insert(i);
	}
	simpleNums.insert(2);

	int m, i, j;
	//int S[10][10];
	long amount = 0;
	for (int k = 1; k <= 10; ++k) {
		for (int l = 1; l <= 10; ++l) {
			try {
				dec(k, k, 0, l);
			}
			catch (int i) {
				amount += i;
			}
		}
	}
	cout << amount << endl;
	//dec(m, m, 0);
}

void problem2() {
	int N = 15890;
	for (int i = 1; i <= N; ++i) {
		if (isSimple(i))
			simpleNums.insert(i);
	}
	simpleNums.insert(2);
	int size = simpleNums.size();
	int amount = 0;
	for (int n = 1; n <= N; ++n) {
		for (int k = 1; k <= n / 2; ++k) {
			if (k == 1) {
				if (simpleNums.count(n) == 1)
					++amount;
			}
			else if (k == 2) {
				for (const auto &item : simpleNums) {
					if (simpleNums.count(n - item) != 0) {
						++amount;
						break;
					}
					if (item >= n)
						break;
				}
			}
			else if (k > 2) {
					++amount;
			}
		}
	}
	cout << amount << endl;
}

vector<int> parseNum(int n) {
	vector<int> res;
	while (n > 0) {
		int temp = n % 10;
		n /= 10;
		res.push_back(temp);
	}
	reverse(begin(res), end(res));
	return res;
}

bool isWonderfulNum(int n) {
	vector<int> p = parseNum(n);
	bool isOk[7] = {true, true, true, true, true, true, true};
	int tempAmount = 0;
	for (int i = 0; i < p.size(); ++i) {
		int j = i;
		while (tempAmount <= 10) {
			tempAmount += p[j];
			++j;
			if (j == p.size())
				break;
		}

		if (tempAmount - p[j - 1] == 10 || (j == p.size() && tempAmount == 10)) {
			for (int k = i; k < j - 1; ++k)
				isOk[k] = true;
			tempAmount = 0;
			if (j == p.size())
				break;

			continue;
		}

		isOk[j - 1] = false;
		tempAmount = 0;
	}
	for (int m = 0; m < 7; ++m) {
		if (isOk[m] == false)
			return false;
	}
	return true;
}
void problem5() {
	int k = 0;
	for (int i = 1; i <= 9400000; ++i) {
		if (isWonderfulNum(i))
			++k;
	}
	cout << k << endl;
}

int main()
{
	
	//problem1();
	//problem4();
	//problem3();
	//problem2();
	//problem5();
	int n; 
	cin >> n;
	return 0;
}