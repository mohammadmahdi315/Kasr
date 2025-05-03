#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    // Constructors
    Complex(float r = 0, float i = 0) : real(r), imag(i) {}
    
    // Copy constructor
    Complex(const Complex& other) : real(other.real), imag(other.imag) {}

    // Getter functions
    float getReal() const { return real; }
    float getImag() const { return imag; }

    // Setter functions
    void setReal(float r) { real = r; }
    void setImag(float i) { imag = i; }

    // Overloaded operators
    Complex operator+(const Complex& obj) const {
        return Complex(real + obj.real, imag + obj.imag);
    }

    Complex operator-(const Complex& obj) const {
        return Complex(real - obj.real, imag - obj.imag);
    }

    Complex operator*(const Complex& obj) const {
        return Complex(
            real * obj.real - imag * obj.imag,
            real * obj.imag + imag * obj.real
        );
    }

    Complex operator/(const Complex& obj) const {
        float denominator = obj.real * obj.real + obj.imag * obj.imag;
        return Complex(
            (real * obj.real + imag * obj.imag) / denominator,
            (imag * obj.real - real * obj.imag) / denominator
        );
    }

    // Compound assignment operators
    Complex& operator+=(const Complex& obj) {
        real += obj.real;
        imag += obj.imag;
        return *this;
    }

    Complex& operator-=(const Complex& obj) {
        real -= obj.real;
        imag -= obj.imag;
        return *this;
    }

    Complex& operator*=(const Complex& obj) {
        float tempReal = real * obj.real - imag * obj.imag;
        imag = real * obj.imag + imag * obj.real;
        real = tempReal;
        return *this;
    }

    Complex& operator/=(const Complex& obj) {
        float denominator = obj.real * obj.real + obj.imag * obj.imag;
        float tempReal = (real * obj.real + imag * obj.imag) / denominator;
        imag = (imag * obj.real - real * obj.imag) / denominator;
        real = tempReal;
        return *this;
    }

    // Unary operators
    Complex operator+() const {
        return *this;
    }

    Complex operator-() const {
        return Complex(-real, -imag);
    }

    // Comparison operators
    bool operator==(const Complex& obj) const {
        return (real == obj.real) && (imag == obj.imag);
    }

    bool operator!=(const Complex& obj) const {
        return !(*this == obj);
    }

    // Other useful functions
    float magnitude() const {
        return sqrt(real * real + imag * imag);
    }

    float phase() const {
        return atan2(imag, real);
    }

    Complex conjugate() const {
        return Complex(real, -imag);
    }

    // Friend functions for stream operations
    friend ostream& operator<<(ostream& out, const Complex& C) {
        out << C.real;
        if (C.imag >= 0) {
            out << " + " << C.imag << "i";
        } else {
            out << " - " << -C.imag << "i";
        }
        return out;
    }

    friend istream& operator>>(istream& in, Complex& C) {
        cout << "Enter real part: ";
        in >> C.real;
        cout << "Enter imaginary part: ";
        in >> C.imag;
        return in;
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(1, -2);
    
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    
    Complex c3 = c1 + c2;
    cout << "c1 + c2 = " << c3 << endl;
    
    Complex c4 = c1 - c2;
    cout << "c1 - c2 = " << c4 << endl;
    
    Complex c5 = c1 * c2;
    cout << "c1 * c2 = " << c5 << endl;
    
    Complex c6 = c1 / c2;
    cout << "c1 / c2 = " << c6 << endl;
    
    cout << "Magnitude of c1: " << c1.magnitude() << endl;
    cout << "Phase of c1: " << c1.phase() << " radians" << endl;
    cout << "Conjugate of c1: " << c1.conjugate() << endl;
    
    Complex c7;
    cin >> c7;
    cout << "You entered: " << c7 << endl;
    
    return 0;
}