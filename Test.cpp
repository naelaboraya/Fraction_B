#include "sources/Fraction.hpp"
#include "doctest.h"
#include <sstream>
using namespace std;


TEST_CASE("Default constructor") {//should initialize fraction as 0/1
    Fraction f;
    CHECK(f.getNumerator() == 0);
    CHECK(f.getDenominator() == 1);
}

TEST_CASE("Normal Constructor") {
    Fraction f1(3, 4);
    CHECK(f1.getNumerator() == 3);
    CHECK(f1.getDenominator() == 4);

    Fraction f2(-5, 2);
    CHECK(f2.getNumerator() == -5);
    CHECK(f2.getDenominator() == 2);

    CHECK_THROWS_AS(Fraction(1, 0), std::invalid_argument);
}

TEST_CASE("Copy constructor") {//should copy the same valeus
    Fraction f1(2, 3);
    Fraction f2(f1);
    CHECK(f1.getNumerator() == f2.getNumerator());
    CHECK(f1.getDenominator() == f2.getDenominator());

    Fraction f3(4, 5);
    Fraction f4(f3);
    CHECK(f3.getNumerator() == f4.getNumerator());
    CHECK(f3.getDenominator() == f4.getDenominator());
}

TEST_CASE("Addition"){
    //checks if '+' works and gives the most reduces form  

    Fraction f1(5,12);
    Fraction f2(6,20);

    Fraction sum = f1+f2;
    CHECK(sum.getNumerator() == 43);
    CHECK(sum.getDenominator() == 60);

    Fraction sum2 = f1+1;
    CHECK(sum2.getNumerator() == 17);
    CHECK(sum2.getDenominator() == 12);

    Fraction sum3 = 1+f1;
    CHECK(sum2 == sum3);

    float fl1 = 20.637;
    CHECK_NOTHROW(f1+20.637);
}

TEST_CASE("Substraction"){
    Fraction f3(5,12);
    Fraction f4(6,20);

    Fraction sub = f3-f4;
    CHECK(sub.getNumerator() == 7);
    CHECK(sub.getDenominator() == 60);

    Fraction sub2 = f3-1;
    CHECK(sub2.getNumerator() == -7);
    CHECK(sub2.getDenominator() == 12);

    CHECK_NOTHROW(f3-20.637);
}

TEST_CASE("Mul"){
    Fraction f4 (2,3);
    Fraction f5 (4,5);

    Fraction mul1 = f4*f5;
    CHECK(mul1.getNumerator() == 8);
    CHECK(mul1.getDenominator() == 15);

    Fraction f6(4,50);
    float num = 12.5;
    CHECK((f6*num).getNumerator()==1);
    CHECK((f6*num).getDenominator()==1);

    CHECK_NOTHROW(f6*0);
}

TEST_CASE("Division"){
    Fraction f7(2,3);
    Fraction f8(5,9);

    Fraction div1 = f7/f8;
    CHECK(div1.getNumerator()== 6);
    CHECK(div1.getDenominator()==5);

    CHECK((f8/1).getNumerator()==5); 
    CHECK((f8/1).getDenominator()==9);

    CHECK_NOTHROW(f7/1);
    CHECK_THROWS(f7/0);

}

TEST_CASE("=="){
    Fraction f9 (1,4);
    Fraction f10 (25,100);
    CHECK(f9==f10);
    
    Fraction f11 (6,3);
    CHECK(2==f11);

    Fraction zero(0,1);
    Fraction one(1,1);

    CHECK(zero == 0);
    CHECK(one ==1);
}

TEST_CASE("!="){
    Fraction f12 (30,4);
    Fraction f13 (31,4);

    CHECK(f12!=f13);
    CHECK_FALSE(f12 != 7.5);
}

TEST_CASE(">,<,>=,<="){
    Fraction f13(3,4);
    Fraction f14(2,3);

    CHECK(f13 > f14);
    CHECK(f13 > 0);
    CHECK(1 > f13);

    CHECK_FALSE(f13 > 0.75);
    CHECK_FALSE(f14<f14);
    CHECK(f14<f13);
    CHECK_FALSE(f14+1<f13);

    CHECK(f13>=f13+0);
    CHECK_FALSE(f14>=f13);
    
    CHECK(f13<=f13);
    CHECK_FALSE(!(f14<=f13));

}

TEST_CASE("IO") {

    // test << :
    Fraction f15(5, 12);
    std::ostringstream oss;
    oss << f15;
    CHECK(oss.str() == "5/12");

    // test >> :
    Fraction f2;
    std::istringstream iss("6\n20");
    iss >> f2;
    CHECK(f2.getNumerator() == 6);
    CHECK(f2.getDenominator() == 20);

}