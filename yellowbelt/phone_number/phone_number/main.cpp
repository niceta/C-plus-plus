#include <iostream>
#include "phone_number.h"

int main() {
  try {
    PhoneNumber phoneNumber("+7-1233");
    cout << phoneNumber.GetInternationalNumber() << endl;
  }
  catch (invalid_argument &e) {
    cout << e.what();
  }
  system("pause");
  return 0;
}