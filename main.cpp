#include <iostream>
#include <cmath>

using namespace std;

int main() {
    char operation;
    int numValues;
    double result = 0.0;

    cout << "Enter the operation you want to perform (+, -, *, /, l for log, % for modulus): ";
    cin >> operation;

    if (operation == 'l') {
        double base, number;
        cout << "Enter the base for the logarithm: ";
        cin >> base;
        cout << "Enter the number: ";
        cin >> number;
        if (base <= 0 || base == 1 || number <= 0) {
            cout << "Invalid input for logarithm calculation." << endl;
        } else {
            result = log(number) / log(base);
            cout << "The result is: " << result << endl;
        }
    } else {
        cout << "Enter the number of values: ";
        cin >> numValues;

        if (numValues < 2 && operation != '!') {
            cout << "At least two values are required for this operation." << endl;
            return 1;
        }

        double values[numValues];

        for (int i = 0; i < numValues; ++i) {
            cout << "Enter value " << i + 1 << ": ";
            cin >> values[i];
        }

        switch (operation) {
            case '+':
                result = 0;
                for (int i = 0; i < numValues; ++i) {
                    result += values[i];
                }
                break;
            case '-':
                result = values[0];
                for (int i = 1; i < numValues; ++i) {
                    result -= values[i];
                }
                break;
            case '*':
                result = 1;
                for (int i = 0; i < numValues; ++i) {
                    result *= values[i];
                }
                break;
            case '/':
                result = values[0];
                for (int i = 1; i < numValues; ++i) {
                    if (values[i] == 0) {
                        cout << "Division by zero is not allowed." << endl;
                        return 1;
                    }
                    result /= values[i];
                }
                break;
            case '%':
                result = (int)values[0];
                for (int i = 1; i < numValues; ++i) {
                    if ((int)values[i] == 0) {
                        cout << "Modulus by zero is not allowed." << endl;
                        return 1;
                    }
                    result %= (int)values[i];
                }
                break;
            default:
                cout << "Invalid operation selected." << endl;
                return 1;
        }

        cout << "The result is: " << result << endl;
    }

    return 0;
}
