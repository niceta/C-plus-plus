#include <iostream>
#include <string>
#include <deque>
using namespace std;


int main () {
	int x, n;
	cin >> x >> n;

	deque<string> expr = { to_string (x) };
	char prev_op = '*';
	for (int i = 0; i < n; ++i) {
		char op;
		int val;
		cin >> op >> val;
		if ((prev_op == '-' || prev_op == '+') 
			&& (op == '*' || op == '/')) {
			expr.push_front ("(");
			expr.push_back (")");
		}
		expr.push_back (" " + string (1, op) + " ");
		expr.push_back (to_string (val));
		prev_op = op;
	}

	for (const auto& i : expr) {
		cout << i;
	}

	return 0;
}