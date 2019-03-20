#include "phone_tests.h"

void tests() {
  PhoneNumber number("+7-909-9000");
  assertEqual(number.GetInternationalNumber(), "+7-909-9000");
}
