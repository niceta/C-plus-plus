#include <iostream>
#include <cstdint>

using namespace std;

int main() {
	size_t n, ro;
	cin >> n >> ro;
	
	uint64_t sum = 0;

	cout << sizeof(size_t) << " " << sizeof(uint64_t);
	for (size_t i = 0; i < n; ++i) {
		size_t w, h, d;
		cin >> w >> h >> d;

		uint64_t v = w * h * d;
		sum += v * ro;
	}

	cout << sum;

	return 0;
}