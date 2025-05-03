#include <iostream>

class Fraction {
private:
    int numerator;   // صورت
    int denominator; // مخرج

    // تابع کم کردن کسر
    void reduce() {
        int gcd_value = gcd(numerator, denominator);
        numerator /= gcd_value;
        denominator /= gcd_value;
    }

    // تابع بازگشتی برای محاسبه GCD
    int gcd(int a, int b) {
        if (b == 0) 
            return a;
        return gcd(b, a % b);
    }

public:
    // سازنده
    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        reduce();
    }

    // عملگر برای نمایش کسر
    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
        os << frac.numerator << "/" << frac.denominator;
        return os;
    }

    // عملگر جمع
    Fraction operator+(const Fraction& other) {
        int new_numerator = numerator * other.denominator + other.numerator * denominator;
        int new_denominator = denominator * other.denominator;
        return Fraction(new_numerator, new_denominator);
    }

    // عملگر تفریق
    Fraction operator-(const Fraction& other) {
        int new_numerator = numerator * other.denominator - other.numerator * denominator;
        int new_denominator = denominator * other.denominator;
        return Fraction(new_numerator, new_denominator);
    }

    // عملگر ضرب
    Fraction operator*(const Fraction& other) {
        int new_numerator = numerator * other.numerator;
        int new_denominator = denominator * other.denominator;
        return Fraction(new_numerator, new_denominator);
    }

    // عملگر تقسیم
    Fraction operator/(const Fraction& other) {
        if (other.numerator == 0) {
            throw std::invalid_argument("Cannot divide by zero.");
        }
        int new_numerator = numerator * other.denominator;
        int new_denominator = denominator * other.numerator;
        return Fraction(new_numerator, new_denominator);
    }
};

int main() {
    try {
        Fraction frac1(1, 2); // 1/2
        Fraction frac2(1, 3); // 1/3

        std::cout << "Fraction 1: " << frac1 << std::endl;
        std::cout << "Fraction 2: " << frac2 << std::endl;

        Fraction sum = frac1 + frac2;
        std::cout << "Sum: " << sum << std::endl;

        Fraction difference = frac1 - frac2;
        std::cout << "Difference: " << difference << std::endl;

        Fraction product = frac1 * frac2;
        std::cout << "Product: " << product << std::endl;

        Fraction quotient = frac1 / frac2;
        std::cout << "Quotient: " << quotient << std::endl;

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}