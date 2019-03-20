#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  double a, b, c;
  cin >> a >> b >> c;

  if (a == 0 && b == 0 && c != 0) {
  	  cout << "";
  	  return 0;
    }

  if (a == 0) {
	  double res = -(c / b);
	  cout << res;
	  return 0;
  }

  double d = sqrt(b * b - 4 * a * c);

  if (d > 0) {
	  cout << (-b + d) / (2 * a) << " ";
	  cout << (-b - d) / (2 * a);
	  return 0;
  }

  if (d == 0) {
	  cout << -b / (2 * a);
	  return 0;
  }
  else
  {
	  cout << "";
  }

  return 0;
}
