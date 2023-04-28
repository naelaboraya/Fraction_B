/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;


int main() {
    // Fraction a(5,3), b(14,21);
    // cout << "a: " << a << "b: " << b << endl;
    // cout << "a+b" << a+b << endl; 
    // cout << "a-b" << a-b << endl; 
    // cout << "a/b" << a/b << endl; 
    // cout << "a*b" << a*b << endl; 
    // cout << "2.3*b" << 2.3*b << endl; 
    // cout << "a+2.421" << a+2.421 << endl; 
    // Fraction c = a+b-1;
    // cout << c++ << endl;
    // cout << --c << endl;

    // cout << "c >=b ? : " << (c >= b) << endl;
    // if (a > 1.1) cout << " a is bigger than 1.1" << endl;
    // else cout << " a is smaller than 1.1" << endl;

    // Fraction f1(-500,1000);
    // Fraction f3(1000,-3000);
    // int lcm_den = LCM(f1.getDenominator(), f3.getDenominator());
    // int num1 = f1.getNumerator() * (lcm_den / f1.getDenominator());
    // int num2 = f3.getNumerator() * (lcm_den / f3.getDenominator());

    // cout << lcm_den << endl;
    // cout << num1 << num2 << endl;
    // cout << (f1>f3) << endl;
    // cout << (f1<f3) << endl;

    // double complex_num1 = 4.321;
    // Fraction ftest = floatToFraction(complex_num1);
    // Fraction frac1{2, 3};
    // cout << floatToFraction(complex_num1) << endl;
    // cout << frac1 << endl;
    // cout << (frac1>complex_num1) << endl;
    // cout << (frac1<complex_num1) << endl;
    // cout << (ftest == frac1) << endl;
    // cout << (ftest < frac1) << endl;
    // cout << (ftest > frac1) << endl;

    // Fraction frac5{1,2};
    // Fraction frac6{3, -4};

    // std::stringstream ss_out;
    // ss_out << frac5 << " and " << frac6;
    
    // cout << ss_out.str() << endl;

    // ss_out.str("");
    // Fraction neg_frac{-7, 9};
    // cout << neg_frac << "not reduced" << endl;
    // ss_out << neg_frac;
    // cout << ss_out.str() << "(first ss)" << endl;

    // Fraction red = reduce(neg_frac.getNumerator() , neg_frac.getDenominator());
    // cout << red << "(reduced)" << endl;
    // ss_out.str("");
    // ss_out << red;
    // cout << ss_out.str() << "(second ss)" << endl;

    // float ffff = 0.3333333;
    // Fraction a = floatToFraction(ffff);
    // Fraction frac34(ffff);
    // cout << a << endl;
    // cout << frac34 << endl;
    Fraction frac = 5.321- Fraction(2,3);
    float a = fractionToDecimal(frac);
    Fraction frac1(2327,500);
    float b = fractionToDecimal(frac1);
    cout << frac << endl;
    cout << a << endl;
    cout << frac1 << endl;
    cout << b << endl;
    
    cout << (4.654 == 4.654) << endl;

    cout << fractionToDecimal(frac) << endl;
     cout << fractionToDecimal(frac1) << endl;
    
    int max_int = std::numeric_limits<int>::max();
    Fraction maxtest(max_int-1,1);
    Fraction one(1,1);
    Fraction add = maxtest + one ;
}   

