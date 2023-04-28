#include "Fraction.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <limits.h>
using namespace std;

//constructors:
Fraction::Fraction() : _numerator(0), _denominator(1) {
    //default constructor , init values are : 0/1
}


Fraction::Fraction (int numerator , int denominator){
    if(denominator == 0){//checking if denominator = 0 , dont initialize the fraction and throw an error
        throw std::invalid_argument("denominator can't be 0");
    }
    this->_numerator = numerator;
    this->_denominator = denominator;
}

Fraction::Fraction (const Fraction& other){
    this->_numerator = other._numerator;
    this->_denominator = other._denominator;
}

Fraction::Fraction(float value) {
    std::string str_value = std::to_string(value);
    std::string str_fraction = str_value.substr(str_value.find('.') + 1, 3);
    int numerator = std::stoi(str_fraction);
    int denominator = pow(10, str_fraction.size());
    Fraction f = floatToFraction(value);
    _numerator = f.getNumerator();
    _denominator = f.getDenominator();
}

//-----------------------------Move Constructor--------------------
Fraction::Fraction(Fraction&& other) noexcept {
    _numerator = other._numerator;
    _denominator = other._denominator;
    other._numerator = 0;
    other._denominator = 1;
}

//------------------------------------------------------------------


//-----------------------------Assignments-------------------------------
Fraction& Fraction::operator=(const Fraction& other) {
    if (this != &other) {
        _numerator = other._numerator;
        _denominator = other._denominator;
    }
    return *this;
}

Fraction& Fraction::operator=(Fraction&& other) noexcept {
    if (this != &other) {
        _numerator = std::exchange(other._numerator, 0);
        _denominator = std::exchange(other._denominator, 1);
    }
    return *this;
}


//-----------------------------------------------------------------------

//functions:

// /*A function that calculates the lowest common multiple*/
int LCM(int num1, int num2) {
    if (num1 == 0 || num2 == 0) {
        return 1; // return 1 instead of 0 to avoid division by zero errors
    }
    int absNum1 = abs(num1);
    int absNum2 = abs(num2);
    int product = absNum1 * (absNum2 / std::__gcd(absNum1, absNum2));
    return (num1 < 0 && num2 < 0) ? abs(product) : product;
}

 /*A function that simplifies the fraction*/
Fraction reduce(int numerator , int denominator){
    int gcd = std::__gcd(numerator,denominator);
    int reduced_numerator = numerator/gcd;
    int reduced_denominator = denominator/gcd;
    return Fraction(reduced_numerator,reduced_denominator);
}

/*A function that converts a float into a fraction*/
Fraction floatToFraction(float num){
    int sign = (num < 0) ? -1 : 1;
    num *= sign;
    int wholePart = floor(num);
    num -= wholePart;
    int maxDenominator = 1000;
    int numerator = round(num * maxDenominator);
    int denominator = maxDenominator;
    numerator += wholePart * denominator;
    numerator *= sign;
    return reduce(numerator, denominator);
}

/*A function that converts a fraction to float (returns the float-value of a fraction)*/
/*The function is good for comparisons , and it takes 3 digits after the decimal point*/
float fractionToDecimal(const Fraction& frac) {
    float quotient = static_cast<float>(frac.getNumerator()) / frac.getDenominator();
    float rounded = roundf(quotient * 1000) / 1000; // round to first 3 digits after decimal point
    return rounded;
}

/*A function that takes a float and returs it but with only 3 digits after the decimal point*/
float truncateToThreeDigits(float value) {
    float rounded = roundf(value * 1000) / 1000; // round to first 3 digits after decimal point
    return rounded;
}


/*A function that compares two fractions*/
int compareFractions(const Fraction& frac1, const Fraction& frac2) {
    int lcm_den = LCM(frac1.getDenominator(), frac2.getDenominator());
    int num1 = frac1.getNumerator() * (lcm_den / frac1.getDenominator());
    int num2 = frac2.getNumerator() * (lcm_den / frac2.getDenominator());
    if (num1 < num2) {
        return -1;
    } else if (num1 > num2) {
        return 1;
    } else {
        return 0;
    }
}

//--------------------adding----------------------------

Fraction operator+ (const Fraction& frac1 , const Fraction& frac2){
    //1.make a common denominator (LCM)
    //2.add the numerators
    //3.simplify the fraction
    if((frac1.getNumerator() == std::numeric_limits<int>::max()
    && frac1.getDenominator() != std::numeric_limits<int>::max()) 
    || (frac2.getDenominator() == std::numeric_limits<int>::max()
    && frac2.getDenominator() != std::numeric_limits<int>::max())
    || (frac1.getNumerator() <= std::numeric_limits<int>::min()+100)
    && (frac2.getNumerator() <= std::numeric_limits<int>::min()+100)){
        throw std::overflow_error("too large number!");
    }
    int lcm = LCM(frac1._denominator , frac2._denominator);
    int common_denominator = (lcm > 0) ? lcm : 1;
    int sum_numerator = ((common_denominator/frac1._denominator)*frac1._numerator) + ((common_denominator/frac2._denominator)*frac2._numerator);
    return reduce(sum_numerator , common_denominator);
}


Fraction operator+ (const Fraction& frac , const float& num){
    Fraction frac2 = floatToFraction(num);
    return frac + frac2;//calling frac+frac function
}

Fraction operator+ (const  float& num ,const Fraction& frac){
    Fraction frac1 = floatToFraction(num);
    return frac1 + frac;
}

 //--------------------substraction----------------------------

Fraction operator- (const Fraction& frac1 , const Fraction& frac2){
    //1.make a common denominator (LCM)
    //2.add the numerators
    //3.simplify the fraction
    if((frac1.getNumerator() <= std::numeric_limits<int>::min()+100
    && frac2.getNumerator() <= std::numeric_limits<int>::min()+100) 
    || (frac1.getNumerator() >= std::numeric_limits<int>::max()-100
    && frac2.getNumerator() <= std::numeric_limits<int>::min()+100)){
        throw std::overflow_error("too large number!");
    }
    int common_denominator = LCM(frac1._denominator , frac2._denominator);
    int sum_numerator = ((common_denominator/frac1._denominator)*frac1._numerator) - ((common_denominator/frac2._denominator)*frac2._numerator);
    return reduce(sum_numerator , common_denominator);
}

Fraction operator- (const Fraction& frac , const float& num){
    Fraction frac2 = floatToFraction(num);
    return frac - frac2;//calling frac+frac function
}

Fraction operator- (const  float& num , const Fraction& frac){
    Fraction frac1 = floatToFraction(num);
    return frac1 - frac;
}


//--------------------multiplication----------------------------

Fraction operator* (const Fraction& frac1 , const Fraction& frac2){
    //1.multiply the numerators and make them one numerator 
    //2.multiply the denominators and make them one common denominator
    if((frac1.getNumerator() == std::numeric_limits<int>::max()
    && frac1.getDenominator() != std::numeric_limits<int>::max()) 
    || (frac1.getDenominator() == std::numeric_limits<int>::max()
    && frac1.getNumerator() != std::numeric_limits<int>::max()) 
    || (frac2.getNumerator() == std::numeric_limits<int>::max()
    && frac2.getDenominator() != std::numeric_limits<int>::max())
    || (frac2.getDenominator() == std::numeric_limits<int>::max()
    && frac2.getDenominator() != std::numeric_limits<int>::max())){
        throw std::overflow_error("too large number!");
    }
    int new_numerator = frac1._numerator * frac2._numerator;
    int new_denominator = frac1._denominator * frac2._denominator;
    return reduce(new_numerator,new_denominator);
}


Fraction operator* (const Fraction& frac , const float& num){
    Fraction frac2 = floatToFraction(num);
    return frac * frac2;
}

Fraction operator* (const  float& num , const Fraction& frac){
    Fraction frac1 = floatToFraction(num);
    return frac1 * frac;
}

//--------------------division----------------------------

Fraction operator/ (const Fraction& frac1 , const Fraction& frac2){
    //1.multiply the numerator of the first fraction with the denominator of the second , and make the result numerator
    //2.multiply the denomirator of the first fraction with the numerator of the second . and make the result the denominator
    if(frac2 == 0){
        throw std::runtime_error("denominator cant be zero!");
    }
    if((frac1.getNumerator() == std::numeric_limits<int>::max()
    && frac1.getDenominator() != std::numeric_limits<int>::max()) 
    || (frac1.getDenominator() == std::numeric_limits<int>::max()
    && frac1.getNumerator() < std::numeric_limits<int>::max()-100) ){
        throw std::overflow_error("too large number!");
    }
    int new_numerator = frac1._numerator * frac2._denominator;
    int new_denominator = frac1._denominator * frac2._numerator;
    return reduce(new_numerator,new_denominator);
}



Fraction operator/ (const Fraction& frac , float num){
    if(num == 0){
        throw std::runtime_error("denominator cant be zero!");
    }
    Fraction frac2 = floatToFraction(num);
    return frac / frac2;
}

Fraction operator/ (float num , const Fraction& frac){
    if(frac == 0){
        throw std::runtime_error("denominator cant be zero!");
    }
    Fraction frac1 = floatToFraction(num);
    return frac1 / frac;
}

//--------------------equals----------------------------

bool operator== (const Fraction& frac1 , const Fraction& frac2){
    Fraction left = reduce(frac1._numerator,frac1._denominator);
    Fraction right = reduce(frac2._numerator,frac2._denominator);
     if (fractionToDecimal(frac1) == fractionToDecimal(frac2)){
        return true;
    }
    return left.getNumerator()==right.getNumerator() && left.getDenominator()==right.getDenominator();
}


bool operator== (const Fraction& frac, float num){
    Fraction left = reduce(frac._numerator,frac._denominator);
    Fraction right = floatToFraction(num);
    if (fractionToDecimal(frac) == truncateToThreeDigits(num)){
        return true;
    }
    return left.getNumerator()==right.getNumerator() && left.getDenominator()==right.getDenominator();
}

bool operator== (float num, const Fraction& frac){
    Fraction left = floatToFraction(num);
    Fraction right = reduce(frac._numerator,frac._denominator);
    if (fractionToDecimal(frac) == truncateToThreeDigits(num)){
        return true;
    }
    return left.getNumerator()==right.getNumerator() && left.getDenominator()==right.getDenominator();
}

//--------------------not equals----------------------------

bool operator!= (const Fraction& frac1 , const Fraction& frac2){
    return (!(frac1 == frac2));
}


bool operator!= (const Fraction& frac, float num){
    return (!(frac == num));
}

bool operator!= (float num, const Fraction& frac){
     return (!(num == frac));
}

//--------------------greater than----------------------------

bool operator>(const Fraction& frac1, const Fraction& frac2) {
    return compareFractions(frac1, frac2) > 0;
}

bool operator>(const Fraction& frac1 , float num){
    Fraction frac2 = floatToFraction(num);
    return compareFractions(frac1, frac2) > 0;

}

bool operator>(float num , const Fraction& frac){
    Fraction frac1 = floatToFraction(num);
    return compareFractions(frac1, frac) > 0;

}

//--------------------less than----------------------------

bool operator<(const Fraction& frac1, const Fraction& frac2){
    //determining by cross multiplication
    return compareFractions(frac1, frac2) < 0;
}


bool operator<(const Fraction& frac, float num){
   Fraction frac2 = floatToFraction(num);
   return compareFractions(frac , frac2) < 0;
}

bool operator<(float num, const Fraction& frac){
    Fraction frac1 = floatToFraction(num);
    return compareFractions(frac1, frac) < 0;
}

//--------------------greater than / equals----------------------------

bool operator>=(const Fraction& frac1, const Fraction& frac2){
    return ((frac1>frac2)||(frac1==frac2))? true:false;
}


bool operator>=(const Fraction& frac, float num){
    return ((frac>num)||(frac==num))? true:false;
}

bool operator>=(float num, const Fraction& frac){
    return ((num>frac)||(num==frac))? true:false;
}

//--------------------less than / equals----------------------------

bool operator<=(const Fraction& frac1, const Fraction& frac2){
    return ((frac1<frac2)||(frac1==frac2))? true:false;
}

bool operator<=(const Fraction& frac, float num){
    return ((frac<num)||(frac==num))? true:false;
}

bool operator<=(float num, const Fraction& frac){
    return ((num<frac)||(num==frac))? true:false;
}

//--------------------increment----------------------------

Fraction& operator++(Fraction& frac){
    //changes (increments) the fraction itself (reference) and then returns it
    frac = frac + 1;
    return frac;
}

Fraction operator++(Fraction& frac , int dummy_flag_for_postfix_increment){
    //creates a copy of the original fraction, increments it, and returns the copy
    Fraction result(frac);
    frac = frac +1;
    return result;
}

//--------------------decrement----------------------------

Fraction& operator--(Fraction& frac){
    //changes (decrements) the fraction itself (reference) and then returns it
    frac = frac - 1;
    return frac;
}

Fraction operator--(Fraction& frac , int dummy_flag_for_postfix_increment){
    //creates a copy of the original fraction, decrements it, and returns the copy
    Fraction result(frac);
    frac = frac - 1;
    return result;
}

//--------------------IO----------------------------

std::ostream& operator<< (std::ostream& output, const Fraction& frac){//doesnt modify the object
    Fraction result = reduce(frac._numerator,frac._denominator);
    if (result._denominator < 0) { // if denominator is negative, move sign to numerator
        result._numerator *= -1;
        result._denominator *= -1;
    }
    if (result._numerator < 0 && result._denominator > 0) { // if numerator is negative and denominator is positive, move sign to numerator
        output << "-" << abs(result._numerator) << "/" << result._denominator;
    }
    else {
        output << result._numerator << "/" << result._denominator;
    }
    return output;
}

std::istream& operator>> (std::istream& input, Fraction& frac) {
    int numerator = 0, denominator = 0;
    input >> numerator >> denominator;
    
    if (denominator == 0) {
        throw std::runtime_error("Denominator cannot be zero!");
    }
    
    frac.setNumerator(numerator);
    frac.setDenominator(denominator);
    
    return input;
}




//------------------------toString----------------------------------

/*A toString function that describes the fracton (as it is)*/
std::string Fraction::toString(){
    std::string info = "";
    if(this->_numerator == this->_denominator){
        return "1";
    }
    if(this->_denominator == 1){
        return std::to_string(this->_numerator);
    }
    info+= std::to_string(this->_numerator);
    info+="/";
    info+= std::to_string(this->_denominator);
    return  info;
}