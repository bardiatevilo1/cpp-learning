/*
 * Stretch goals:
 *   - Polar form constructor: Complex(r, theta, polar_tag)
 *   - Static factory:         Complex::from_polar(r, theta)
 *   - Verify Euler's identity: exp(i*pi) + 1 == 0 (within epsilon)
 *   - DFT toy example using your class (foreshadows Fourier work)
 */

#include <cmath>
#include <iostream>
#include <numbers>

class Complex {
	double re;
	double im;

  public:
	Complex(double re, double im) : re{re}, im{im} {};
	Complex() : re{0.0}, im{0.0} {};

	// Empty struct to distinguish polar coord constructor
	struct polar_tag {};
	Complex(double r, double theta, polar_tag);

	static Complex from_polar(double r, double theta) {
		return Complex(r * std::cos(theta), r * std::sin(theta));
	}

	Complex operator+(const Complex &z) const {
		return Complex(re + z.re, im + z.im);
	}

	Complex operator-(const Complex &z) const {
		return Complex(re - z.re, im - z.im);
	}

	Complex operator*(const double &c) const { return Complex(re * c, im * c); }

	Complex operator*(const Complex &z) const {
		return Complex(re * z.re - im * z.im, re * z.re + im * z.re);
	}

	Complex conjugate() const { return Complex(re, -im); }

	Complex operator/(double c) const { return Complex(re / c, im / c); }

	Complex operator/(const Complex &z) const {
		Complex conjugate = z.conjugate();
		double denom = z.re * z.re + z.im * z.im;
		return (*this * conjugate) / denom;
	}

	bool operator==(const Complex &z) const {
		double eps = 1e-9;
		return std::abs(re - z.re) < eps && std::abs(im - z.im) < eps;
	}

	double modulus() const { return sqrt(re * re + im * im); }

	double arg() const { return atan2(im, re); }

	Complex exp() const {
		return Complex(std::cos(im), std::sin(im)) * std::exp(re);
	}

	Complex pow(int n) const {
		double r = modulus();
		double theta = arg();
		return Complex(std::cos(n * theta), std::sin(n * theta)) *
			   std::pow(r, n);
	}

	friend Complex operator*(double c, const Complex &z) { return z * c; }

	friend std::ostream &operator<<(std::ostream &os, const Complex &z) {
		os << z.re << " + " << z.im << "i";
		return os;
	}
};

int main() {
	// Euler's identity
	Complex euler = Complex(0.0, std::numbers::pi).exp() + Complex(1.0, 0.0);

	if (euler == Complex(0.0, 0.0))
		std::cout << "Euler's identity verified" << std::endl;

	return 0;
}
