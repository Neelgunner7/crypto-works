#include <iostream>
#include <cmath>
using namespace std;

void ECC(double a, double b, double x1, double x2);

int main() {
    // Declare variables
    double a, b, x1, x2;
    string choice;
    // Loop until user enters x
    do {
        // Gather input parameters
        cout << "Welcome to Elliptic Curve Point Addition" << endl;
        cout << "Curve: y^2 = x^3+ax+b" << endl;
        cout << "a:";
        cin >> a;
        cout << "b:";
        cin >> b;
        // Loop to check for valid x-values
        do {
            cout << "Please provide x-value for P coordinate:";
            cin >> x1;
            if (pow(x1, 3) + (a * x1) + b < 0) {
                cout << "Invalid x-value, please try again" << endl;
            }
        }while(pow(x1, 3) + (a * x1) + b < 0);
        do {
            cout << "Please provide x-value for Q coordinate:";
            cin >> x2;
            if (pow(x2, 3) + (a * x2) + b < 0) {
                cout << "Invalid x-value, please try again" << endl;
            }
        }while(pow(x2, 3) + (a * x2) + b < 0);

        ECC(a, b, x1, x2); // Calculate the Elliptic Curve point addition

        cout << "Try again? (x for exit):";
        cin >> choice;
        cout << endl;
    }while(choice != "x");
    return 0;
}

void ECC(double a, double b, double x1, double x2){
    // Declare variables
    double y1, y2, m, yint;
    double x3, y3;

    // Calculate corresponding y1, y2, slope and y-intercept of line
    y1 = sqrt(pow(x1, 3) + (a * x1) + (b));
    y2 = sqrt(pow(x2, 3) + (a * x2) + (b));

    m = (y2-y1)/(x2-x1);
    if(x2 == x1){
        // If P and Q are the same point, calculate the derivative
        // of the curve at point P to find the slope
        m = (3*pow(x1,2)+a)/(2*y1);
    }
    yint = y1 - (m*x1);

    // x3 calculated by comparing coefficients with general form cubic (x-x1)(x-x2)(x-x3)
    // with the cubic found by substituting the line y=mx+yint into our curve y^2=x^3+ax+b
    x3 = pow(m,2)-x1-x2;
    y3 = sqrt(pow(x3, 3) + (a * x3) + (b));

    // If the calculated y-value is on the line, then
    // take the negative root, else leave it unchanged
    if(y3 == (m*x3 + yint)){
        y3 = -y3;
    }

    // Display results
    cout << endl;
    cout << "Given the curve y^2=x^3+" << a << "x" << "+" << b << endl;
    cout << "Point P = (" << x1 << ", " << y1 << ")" << endl;
    cout << "Point Q = (" << x2 << ", " << y2 << ")" << endl;
    cout << "Result P+Q = R: (" << x3 << ", " << y3 << ")" << endl;
    cout << endl;
}
