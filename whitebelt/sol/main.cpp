#include <iostream>
#include <cmath>

using namespace std;

int main() {
  double A, B, C;
  cin >> A >> B >> C;

  // ����� ������������
  double D = B * B - 4 * A * C;

  // ���� A ����� ����, �� ��������� ��������: Bx + C = 0
  if (A == 0) {

    // Bx = -C => x = -C / B
    if (B != 0) {
      cout << -C / B << endl;
    }
    // ���� B ����� ����, ������ ���

  } else if (D == 0) {  // ������ � ������� ��������������

    // ������ ����� ����
    cout << -B / (2 * A) << endl;

  } else if (D > 0) {  // � ������ � ������������� �������������� ����� ���

    double r1 = (-B + sqrt(D)) / (2 * A);
    double r2 = (-B - sqrt(D)) / (2 * A);

    cout << r1 << " " << r2 << endl;

  }
  // ���� ������������ �����������, �������������� ������ ���

  return 0;
}
