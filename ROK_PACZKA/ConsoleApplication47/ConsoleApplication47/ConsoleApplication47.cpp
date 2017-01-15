// ConsoleApplication47.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

template<bool condition, int v1, int v2>
struct If_then_else {
	static const int result = v1;
};

template<int v1, int v2>
struct If_then_else<false, v1, v2> {
	static const int result = v2;
};

template<int v1, int v2>
struct smax {
	static const int result = If_then_else<(v1 >= v2), v1, v2>::result;
};

template<int v1, int v2>
struct smin {
	static const int result = If_then_else<(v1 < v2), v1, v2>::result;
};

struct LazyOverflowPolicy {
	static void handleOverflow() {}
};

struct ThrowingOverflowPolicy {
	static void handleOverflow() {
		throw std::overflow_error("Overflow error!");
	}
};

int digits(int base) {
	return (base < 10 ? 0 :
		(base < 100 ? 1 :
		(base < 1000 ? 2 :
		(base < 10000 ? 3 :
		(base < 100000 ? 4 :
		(base < 1000000 ? 5 :
		(base < 10000000 ? 6 :
		(base < 100000000 ? 7 :
		(base < 1000000000 ? 8 :
		(base < 10000000000 ? 9 :
		10))))))))));
}

template<int size, typename basic_type = unsigned int, typename long_type = unsigned long long, long_type base = 1000000000, class OverflowPolicy = ThrowingOverflowPolicy>
class NSizeNatural {
private:
	basic_type val[size];

public:
	NSizeNatural() {
		for (int i = 0; i < size; i++) {
			val[i] = 0;
		}
	}

	NSizeNatural(basic_type val) {
		this->val[0] = val;
		for (int i = 1; i < size; i++) {
			this->val[i] = 0;
		}
	}

	NSizeNatural(basic_type *first, basic_type *afterLast) {
		for (int i = 0; i < size; i++) {
			val[i] = 0;
		}
		copy(first, afterLast, val);
	}

	const basic_type& operator[](int i) const {
		return val[i];
	}

	basic_type& operator[](int i) {
		return val[i];
	}

	template<int other_size>
	NSizeNatural<smax<size, other_size>::result, basic_type, long_type, base, OverflowPolicy> operator+(const NSizeNatural<other_size, basic_type, long_type, base, OverflowPolicy> &other) {
		NSizeNatural<smax<size, other_size>::result, basic_type, long_type, base, OverflowPolicy> result;
		lldiv_t dt = lldiv(0, base);
		for (int i = 0; i < smax<size, other_size>::result; i++) {
			dt = lldiv(dt.quot + (i < size ? val[i] : 0) + (i < other_size ? other[i] : 0), base);
			result[i] = dt.rem;
		}
		if (dt.quot != 0) {
			OverflowPolicy::handleOverflow();
		}
		return result;
	}

	template<int other_size>
	NSizeNatural<smax<size, other_size>::result, basic_type, long_type, base, OverflowPolicy> operator*(const NSizeNatural<other_size, basic_type, long_type, base, OverflowPolicy> &other) {
		NSizeNatural<smax<size, other_size>::result, basic_type, long_type, base, OverflowPolicy> result;
		NSizeNatural<size + other_size, basic_type, long_type, base, OverflowPolicy> temp;
		bool found = true;
		int digit = 0;
		long_type carry = 0;
		for (; found; digit++) {
			long_type oldCarry = carry;
			carry /= base;
			temp[digit] = (basic_type)(oldCarry - carry * base);
			found = false;
			for (int i = digit < other_size ? 0 : digit - other_size + 1; i < size && i <= digit; i++) {
				long_type pval = temp[digit] + val[i] * (long_type)other[digit - i];
				if (pval >= base) {
					long_type quot = pval / base;
					carry += quot;
					pval -= quot * base;
				}
				temp[digit] = (basic_type)pval;
				found = true;
			}
		}
		for (; carry > 0; digit++)
		{
			temp[digit] = (basic_type)(carry % base);
			carry /= base;
		}
		for (int i = 0; i < smax<size, other_size>::result; i++) {
			result[i] = temp[i];
		}
		if (temp[smax<size, other_size>::result] != 0) {
			OverflowPolicy::handleOverflow();
		}
		return result;
	}

	template<int other_size>
	bool operator<(const NSizeNatural<other_size, basic_type, long_type, base, OverflowPolicy> &other) {
		int i = smax<size, other_size>::result - 1;
		for (; i > smin<size, other_size>::result - 1; i--) {
			if (size > other_size ? val[i] : other[i] != 0) {
				return size > other_size ? false : true;
			}
		}
		for (i = smin<size, other_size>::result - 1; i >= 0; i--) {
			if (val[i] < other[i]) {
				return true;
			}
		}
		return false;
	}

	template<int other_size>
	bool operator>(const NSizeNatural<other_size, basic_type, long_type, base, OverflowPolicy> &other) {
		int i = smax<size, other_size>::result - 1;
		for (; i > smin<size, other_size>::result - 1; i--) {
			if (size > other_size ? val[i] : other[i] != 0) {
				return size > other_size ? true : false;
			}
		}
		for (i = smin<size, other_size>::result - 1; i >= 0; i--) {
			if (val[i] > other[i]) {
				return true;
			}
		}
		return false;
	}

	template<int other_size>
	bool operator<=(const NSizeNatural<other_size, basic_type, long_type, base, OverflowPolicy> &other) {
		return !(*this > other);
	}

	template<int other_size>
	bool operator>=(const NSizeNatural<other_size, basic_type, long_type, base, OverflowPolicy> &other) {
		return !(*this < other);
	}

	template<int other_size>
	bool operator==(const NSizeNatural<other_size, basic_type, long_type, base, OverflowPolicy> &other) {
		int i = smin<size, other_size>::result - 1;
		for (; i >= 0; i--) {
			if (val[i] != other[i]) {
				return false;
			}
		}
		for (i = smax<size, other_size>::result - 1; i > smin<size, other_size>::result - 1; i--) {
			if (size > other_size ? val[i] : other[i] != 0) {
				return false;
			}
		}
		return true;
	}

	template<int other_size>
	bool operator!=(const NSizeNatural<other_size, basic_type, long_type, base, OverflowPolicy> &other) {
		return !(*this == other);
	}

	friend ostream& operator<<(ostream &out, const NSizeNatural &v) {
		int index = size - 1;
		for (; v.val[index] == 0 && index > 0; index--);
		bool first = true;
		for (int i = index; i >= 0; i--) {
			if (first) {
				out << v.val[i];
				first = false;
			}
			else {
				out << setfill('0') << setw(digits(base)) << v.val[i];
			}
		}
		return out;
	}
};

NSizeNatural<6> fibonacci(int n) {
	NSizeNatural<6> a = 0, b = 1, temp;
	if (n == 0) {
		return 0;
	}
	for (int i = 0; i < n - 1; i++) {
		temp = b;
		b = b + a;
		a = temp;
	}
	return b;
}

namespace std {
	template<int size, typename basic_type, typename long_type, long_type base, class OverflowPolicy>
	class numeric_limits<NSizeNatural<size, basic_type, long_type, base, OverflowPolicy>> {
	public:
		static const bool is_specialized = true;
		static const bool is_signed = false;
		static const bool is_integer = true;
		static const bool is_exact = true;
		static const bool has_infinity = false;
		static const bool has_quiet_NaN = false;
		static const bool has_signaling_NaN = false;
		static const bool is_bounded = true;
		static const bool is_modulo = false;

		static NSizeNatural<size, basic_type, long_type, base, OverflowPolicy> min() {
			NSizeNatural<size, basic_type, long_type, base, OverflowPolicy> result;
			return result;
		}

		static NSizeNatural<size, basic_type, long_type, base, OverflowPolicy> lowest() {
			NSizeNatural<size, basic_type, long_type, base, OverflowPolicy> result;
			return result;
		}

		static NSizeNatural<size, basic_type, long_type, base, OverflowPolicy> max() {
			NSizeNatural<size, basic_type, long_type, base, OverflowPolicy> result = base - 1;
			basic_type matrix[size];
			for (int i = 0; i < size; i++) {
				matrix[i] = 1;
			}
			NSizeNatural<size, basic_type, long_type, base, OverflowPolicy> multiplier(matrix, matrix + size);
			result = result * multiplier;
			return result;
		}
	};
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << numeric_limits<double>::max() << endl;
	long long abbb;
	int ccc = 2147483647;
	int ddd = 2;
	abbb = ccc*ddd;
	cout << abbb << endl;
	cout << numeric_limits<NSizeNatural<4, unsigned int, unsigned long long, 98>>::max() << endl;
	cout << fibonacci(100) << endl; //dodawanie
	unsigned int tab1[] = { 4, 2, 1 };
	unsigned int tab2[] = { 4, 9 };
	NSizeNatural<5, unsigned int, unsigned long long, 10> w(tab1, tab1 + 3); //mnozenie w bazie 10
	NSizeNatural<2, unsigned int, unsigned long long, 10> x(tab2, tab2 + 2);
	NSizeNatural<2> y = 999999999; //mnozenie w bazie 10^9
	unsigned int tab3[] = { 999999999, 9 };
	NSizeNatural<4> z(tab3, tab3 + 2);
	cout << w * x << endl << y * z << endl;
	NSizeNatural<6> a = 124; //porownania
	NSizeNatural<3> b = 124;
	if (a >= b) {
		cout << "Tak!";
	}
	cout << numeric_limits<double>::is_signed << endl;
	int c;
	cin >> c;
	return 0;
}

