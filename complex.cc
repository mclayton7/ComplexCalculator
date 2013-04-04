// Complex Number Class implementation
// Mac Clayton, 2012
// ECE 3090 Lab 1

#include <iostream>
#include <string>
#include <math.h>
#include "complex.h"
#include "string-parse.h"

using namespace std;

//Complex default constructor:
Complex::Complex() {
    real = 0;
    imag = 0;
    num = true;
}

// Alternate constructor with doubles:
Complex::Complex(double& r, double& i) {
    real = r;
    imag = i;
    num = true;
}

//Alternate constructor that parses a string:
Complex::Complex(std::string& st) {
    string temp;
    num = true;
    if (st[0] == '(') {
        temp = RemoveParens(st);
    } else {
        temp = st;
    }
    StringVec_t op;
    CharVec_t del;
    StringParse(temp, ",>", op, del);
    if (del[0] == ',') {
        real = ToDouble(op[0]);
        imag = ToDouble(op[1]);
    } else if (del[0] == '>') {
        double mag = ToDouble(op[0]);
        double angle = ToDouble(op[1]);
        real = mag * cos((angle * M_PI / 180));
        imag = mag * sin((angle * M_PI / 180));
    }else if (del[0] == 0) {
        real = ToDouble(op[0]);
        imag = 0;
    }else {
        cout << "Error in String Conversion" << endl;
    }    
}
    
//Implement member functions:
//Magnitude Calctulator:
double Complex::magCalc() {
    double mag = sqrt( pow(real, 2) + pow(imag, 2)); //uses the math.h library to take the square root of the sum of the squares of the real and imaginary parts.
    return mag;
}

//Angle Calculator:
double Complex::angleCalc() {
    double angle = atan2(imag, real); //arctan(y/x) for the angle  
    angle = angle * 180.0 / M_PI;
    return angle;
}

Complex Complex::conjCreate() {
    Complex A;
    A.real = real;
    A.imag = (-1) * imag;
    return A;
}

//Print Member function:
void Complex::Print() {
    if (num == true) {
        if (imag == 0) {
            cout << " = " << real << endl;
        }else {
            cout << " = (" << real << "," << imag << ")" << endl;
        }
    }else {
        cout << " = NaN" << endl;
    }
}

//Implement operator overloads:
Complex Complex::operator+(const Complex& rhs) {
    Complex rTemp;
    rTemp.num = num && rhs.num;
    rTemp.real = real + rhs.real;
    rTemp.imag = imag + rhs.imag;
    return rTemp;
}

Complex Complex::operator-(const Complex& rhs) {
    Complex rTemp;
    rTemp.num = num && rhs.num;
    rTemp.real = real - rhs.real;
    rTemp.imag = imag - rhs.imag;
    return rTemp;
}

Complex Complex::operator*(const Complex& rhs) {
    Complex rTemp;
    rTemp.num = num && rhs.num;
    rTemp.real = real * (rhs.real) - (imag * rhs.imag);
    rTemp.imag = (imag * rhs.real) + (real * rhs.imag);

    return rTemp;
}

Complex Complex::operator/(const Complex& rhs) {
    Complex B = rhs;
    Complex A;
    Complex t1;
    A.real = real;
    A.imag = imag;
    A.num = num && rhs.num;
    double temp = B.magCalc();
    if (temp == 0) {
        A.num = false;
    }else {
        Complex C = A * B.conjCreate();
        t1 = B * B;
        double m = t1.magCalc();
        A.real = C.real / m;
        A.imag = C.imag / m;
    }
    return A;
}

