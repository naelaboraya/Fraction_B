#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>

namespace ariel {
    
}
		
class Fraction {
	
	private :
	//members:
	int _numerator;
	int _denominator;
	
	
	public :
	//constructors:
	Fraction ();//default
	Fraction (int numerator , int denominator);
	Fraction (const Fraction& other);
	Fraction(float value);

	//move constructor
	Fraction(Fraction&& other) noexcept;
	
	//copy assignment operator
	Fraction& operator=(const Fraction& other);

    //move assignment operator
    Fraction& operator=(Fraction&& other) noexcept;

	//destructor
	~Fraction(){}

	//getters:
	int getNumerator() const{
		return this->_numerator;
	}

	int getDenominator() const{
		return this->_denominator;
	}

	//setters:
	void setNumerator(int numerator){
		this->_numerator = numerator;
	}

	void setDenominator(int denominator){
		if(denominator == 0){//checking if the denominator is valid (!= 0) first
			throw std::invalid_argument("denominator cant be zero !!");
		}
		this->_denominator = denominator;
	}

	

	//functions:
	friend Fraction operator+ (const Fraction& frac1 , const Fraction& frac2);
	friend Fraction operator+ (const Fraction& frac , const float& num);
	friend Fraction operator+ (const  float& num , const Fraction& frac);
	friend Fraction operator- (const Fraction& frac1 , const Fraction& frac2);
	friend Fraction operator- (const Fraction& frac , const float& num);
	friend Fraction operator- (const float& num , const Fraction& frac);
	friend Fraction operator* (const Fraction& frac1 , const Fraction& frac2);
	friend Fraction operator* (const Fraction& frac , const float& num);
	friend Fraction operator* (const  float& num , const Fraction& frac);
	friend Fraction operator/ (const Fraction& frac1 , const Fraction& frac2);
	friend Fraction operator/(const Fraction& frac, float num);
	friend Fraction operator/(float num , const Fraction& frac);  
	friend bool operator== (const Fraction& frac1 , const Fraction& frac2);
	friend bool operator== (const Fraction& frac, float num);
	friend bool operator== (float num, const Fraction& frac);
	friend bool operator!= (const Fraction& frac1 , const Fraction& frac2);
	friend bool operator!= (const Fraction& frac, float num);
	friend bool operator!= (float num, const Fraction& frac);
	friend bool operator>(const Fraction& frac1, const Fraction& frac2);
	friend bool operator>(const Fraction& frac, float num);
	friend bool operator>(float num, const Fraction& frac);
   	friend bool operator<(const Fraction& frac1, const Fraction& frac2);
	friend bool operator<(const Fraction& frac, float num);
	friend bool operator<(float num, const Fraction& frac);
   	friend bool operator>=(const Fraction& frac1, const Fraction& frac2);
	friend bool operator>=(const Fraction& frac, float num);
	friend bool operator>=(float num, const Fraction& frac);
   	friend bool operator<=(const Fraction& frac1, const Fraction& frac2);
	friend bool operator<=(const Fraction& frac, float num);
	friend bool operator<=(float num, const Fraction& frac);
   	friend Fraction& operator++(Fraction& frac);
   	friend Fraction operator++(Fraction& frac , int dummy_flag_for_postfix_increment);
   	friend Fraction& operator--(Fraction& frac);
   	friend Fraction operator--(Fraction& frac , int dummy_flag_for_postfix_increment);
   	friend std::ostream& operator<< (std::ostream& output, const Fraction& frac);
    friend std::istream& operator>> (std::istream& input , Fraction& frac);

	std::string toString();
   	
};


int LCM(int num1 , int num2);
Fraction reduce(int numerator , int denominator);
Fraction floatToFraction(float num);
int compareFractions(const Fraction& frac1, const Fraction& frac2);
float fractionToDecimal(const Fraction& frac);
float truncateToThreeDigits(float value);



#endif
