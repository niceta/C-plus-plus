#include "myalg.h"
#include "sqr.h"
#include "getrafstrict.h"

int main() {
	double sum = 0;
	for (int i = 101; i <= 200; ++i) {
		sum += 1. / i;
	}

	return 0;
}