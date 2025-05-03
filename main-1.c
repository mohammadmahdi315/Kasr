#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

// تابع برای ارزیابی عبارت postfix
double evaluatePostfix(const string& expression) {
    stack<double> s;
    stringstream ss(expression);
    string token;

    while (ss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && token.length() > 1 && isdigit(token[1]))) { // بررسی اعداد منفی
            double num;
            try {
                num = stod(token);
                s.push(num);
            } catch (const invalid_argument& e) {
              throw runtime_error("Invalid number format: " + token);
            } catch (const out_of_range& e) {
              throw runtime_error("Number out of range: " + token);
            }


        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (s.size() < 2) {
                throw runtime_error("Not enough operands for operator: " + token);
            }
            double operand2 = s.top();
            s.pop();
            double operand1 = s.top();
            s.pop();

            if (token == "+") {
                s.push(operand1 + operand2);
            } else if (token == "-") {
                s.push(operand1 - operand2);
            } else if (token == "*") {
                s.push(operand1 * operand2);
            } else if (token == "/") {
              if (operand2 == 0) {
                  throw runtime_error("Division by zero");
              }
                s.push(operand1 / operand2);
            }
        } else {
            throw runtime_error("Invalid token: " + token);
        }
    }

    if (s.size() != 1) {
        throw runtime_error("Invalid expression: Extra operands or operators");
    }

    return s.top();
}

int main() {
    string expression;

    cout << "Enter a postfix expression: ";
    getline(cin >> ws, expression); // استفاده از getline برای خواندن ورودی با فضا

    try {
        double result = evaluatePostfix(expression);
        cout << "Result: " << result << endl;
    } catch (const runtime_error& error) {
        cerr << "Error: " << error.what() << endl;
    }

    return 0;
}