#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <exception>

using namespace std;

class Rational {
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
    	num = 0;
    	denum = 1;
    }

    Rational(int numerator, int denominator) {
        // Реализуйте конструктор
    	if (denominator == 0) {
    		throw invalid_argument("Invalid argument");
    	}
    	shortcut(numerator, denominator);
    }

    int Numerator() const {
        // Реализуйте этот метод
    	return num;
    }

    int Denominator() const {
        // Реализуйте этот метод
    	return denum;
    }

    void setNumerator (int n) {
    	num = n;
    	shortcut(num, denum);
    }

    void setDenominator (int d) {
    	denum = d;
    	shortcut(num, denum);
    }
private:
    // Добавьте поля
    void shortcut(int n, int d) {
    	const int NOD = getNOD(abs(n), abs(d));

    	    	num = n / NOD;
    	    	denum = d / NOD;

    	    	if (denum < 0) {
    	    		num = -num;
    	    		denum = -denum;
    	    	} else if (num == 0) {
    	    		denum = 1;
    	    	}
    }

    int getNOD(int a, int b) {
    	while (a > 0 && b > 0) {
    		if (a > b)
    			a %= b;
    		else
    			b %= a;
    	}

    	return a + b;
    }

    int num;
    int denum;
};

bool operator==(const Rational &r1, const Rational &r2) {
	return (r1.Numerator() == r2.Numerator()) &&
		   (r1.Denominator() == r2.Denominator());
}

bool operator<(const Rational &r1, const Rational &r2) {
	if (r1.Denominator() == r2.Denominator()) {
		return r1.Numerator() < r2.Numerator();
	} else {
		if (r1.Numerator() == r2.Numerator()) {
			return r1.Denominator() > r2.Denominator();
		} else {
			return r1.Numerator() * r2.Denominator() <
				   r2.Numerator() * r1.Denominator();
		}
	}
}

bool operator<=(const Rational &r1, const Rational &r2) {
	return r1 < r2 || r1 == r2;
}

bool operator!=(const Rational &r1, const Rational &r2) {
	return !(r1 == r2);
}

Rational operator+(const Rational &r1, const Rational &r2) {
	return  		 { r1.Numerator()   * r2.Denominator() +
	  	  	  	  	   r2.Numerator()   * r1.Denominator() ,
					   r1.Denominator() * r2.Denominator() };
}

Rational operator*(const Rational &r1, const Rational &r2) {
	return { r1.Numerator()   * r2.Numerator(),
			 r1.Denominator() * r2.Denominator() };
}

Rational operator-(const Rational &r1, const Rational &r2) {
	return r1 + r2 * Rational{-1, 1};
}

Rational operator/(const Rational &r1, const Rational &r2) {
	if (r2.Numerator() == 0)
		throw domain_error("Division by zero");
	return r1 * Rational(r2.Denominator(), r2.Numerator());
}

ostream& operator<<(ostream& stream, const Rational& r) {
	stream << r.Numerator() << '/' << r.Denominator();
	return stream;
}

istream& operator>>(istream& stream, Rational& r) {
	int numerator;
	int denominator;
	stream >> numerator;
	stream.ignore(1);
	stream >> denominator;

	Rational temp(numerator, denominator);

	r = temp;
	return stream;
}

void input() {
	Rational r1, r2;
	char operation;

	cin >> r1 >> operation >> r2;

	if (operation == '+') {
		cout << r1 + r2;
	} else if (operation == '-') {
		cout << r1 - r2;
	} else if (operation == '*') {
		cout << r1 * r2;
	} else if (operation == '/') {
		cout << r1 / r2;
	}
}

int main() {
	try {
		input();
	} catch (exception& ex) {
		cout << ex.what() << endl;
	}

    return 0;
}
