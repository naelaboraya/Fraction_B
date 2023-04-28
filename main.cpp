/**
 * main file for fraction
 * @author Nael Aboraya
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;


int main() {
    
    //--------------------fraction + fraction-------------------------------
    Fraction f1(5,12);
    Fraction f2(6,20);
    Fraction sum = f1+f2;
    cout << sum.toString() << endl;
    //---------------------fraction + int------------------------------------
    Fraction f3(5,12);
    int num = 1;
    Fraction sum2 = f3+num;
    cout << sum2.toString() << endl;
    //-----------------------int + fraction------------------------------------
    Fraction f4(5,12);
    int num2 = 2;
    Fraction sum3 = num2+f3;
    cout << sum3.toString() << endl;
    //------------------------fraction + float----------------------------------
    Fraction f5 (5,12);
    float num3 = 0.583;
    Fraction sum4 = f5+num3;
    cout << sum4.toString() << endl;
    //-------------------------float+fraction-----------------------------------
    Fraction f6(5,12);
    float num4 = 20.637;
    Fraction sum5 = num4+f6;
    cout << sum5.toString() << endl;


    //*******************************************************************************//
    
    //--------------------fraction - fraction-------------------------------
    Fraction f7(5,12);
    Fraction f8(6,20);
    Fraction sub = f1-f2;
    cout << sub.toString() << endl;
    //---------------------fraction - int------------------------------------
    Fraction f9(5,12);
    int number = 1;
    Fraction sub2 = f9-num;
    cout << sub2.toString() << endl;
    //-----------------------int - fraction------------------------------------
    Fraction f10(5,12);
    int number2 = 1;
    Fraction sub3 = number2-f10;
    cout << sub3.toString() << endl;
    //------------------------fraction - float----------------------------------
    Fraction f11 (5,12);
    float number3 = 0.583;
    Fraction sub4 = f11-number3;
    cout << sub4.toString() << endl;
    //-------------------------float - fraction-----------------------------------
    Fraction f12(5,12);
    float number5 = 20.637;
    Fraction sub5 = number5-f12;
    cout << sub5.toString() << endl;


     //*******************************************************************************//

    //---------------------fraction * fraction------------------------------------   
    Fraction f13 (2,3);
    Fraction f14 (4,5);
    Fraction mul1 = f13*f14;
    cout << mul1.toString() << endl;

     //---------------------fraction * int------------------------------------

    Fraction f15(4,50);
    Fraction f16(3,3);
    int _num1 = 1;
    Fraction mul2 = f15*_num1;
    Fraction mul3 = f15*f16;
    cout << mul2.toString() << endl;
    cout << mul3.toString() << endl;

    //---------------------int * fraction------------------------------------

    Fraction f17(4,50);
    int _num2 = 2;
    Fraction mul4 = _num2 * f17;
    cout << mul4.toString() << endl;

    //---------------------fraction * float-----------------------------------

    Fraction f18(4,50);
    float _num3 = 12.5;
    Fraction mul5 = f18*_num3;
    cout << mul5.toString() << endl;

    //---------------------float * fraction-----------------------------------

    Fraction f19(4,50);
    float _num4 = 12.5;
    Fraction mul6 = _num4 * f19;
    cout << mul6.toString() << endl;

    //*******************************************************************************//

    //---------------------fraction / fraction-----------------------------------

    Fraction f20(2,3);
    Fraction f21(5,9);
    Fraction div1 = f20/f21;
    cout << div1.toString() << endl;

    //---------------------fraction / int-----------------------------------
    Fraction f22(20,2);
    int _num5 = 2;
    Fraction div2 = f22/_num5;
    Fraction div3 = f22/1;
    cout << div2.toString() << endl;
    cout << div3.toString() << endl;

    //---------------------int / fraction-----------------------------------

    int _num6 = 1;
    Fraction f23(4,5);
    Fraction div4 = _num6 / f23;
    cout << div4.toString() << endl;

     //---------------------fraction / float-----------------------------------

     Fraction f24(25,36);
     float _num7 = 6.254;
     Fraction div5 = f24 / _num7;
     cout << div5.toString() << endl;

    //---------------------float / fraction-----------------------------------

    Fraction f25 (17,51);
    float _num8 = 8.663;
    Fraction div6 = _num8 / f25;
    cout << div6.toString() << endl;

    //-------------------------fraction == fraction-----------------------------

    Fraction f26(1,4);
    Fraction f27(25,100);
    cout << (f26==f27) << endl;

    //--------------------------fraction == int ---------------------------------
    
    Fraction f28 (6,3);
    int eq1= 2;
    cout << (f28 == eq1) << endl;

    //----------------------------fraction == flloat-------------------------------

    Fraction f29(20,4);
    float eq2 = 5.000;
    cout << (f29==eq2) << endl;

    //--------------------!=----------------------------

    Fraction f30 (30,4);
    Fraction f31 (31,4);
    cout << (f30 != f31) << endl;
    cout << (f30 != 7) << endl;
    cout << (7 != f30) << endl;
    cout << ((float)7.5 != f30) << endl;
    cout << ((float)7.5 == f30) << endl;
    cout << (f30 != (float)7.5) << endl;
    cout << (f30 == (float)7.5) << endl;

     //-------------------->,<,>=,<=----------------------------
     Fraction f32 (3,4);
     Fraction f33 (2,3);
     cout << (f32 > f33) << endl;//should be true
     cout << (f32 > 0) << endl;   
     cout << (1 > f32) << endl;
     cout << (f32 > (float)0.75) << endl;//should be false 
     cout << (f32 > (float)0.74) << endl;//should be true 
     cout << ((float)0.75 > f32) << endl;//should be false
     cout << ((float)0.76 > f32) << endl;//should be true
     cout << (f33 < f32) << endl;  
     cout << (f33 < (float)0.65) << endl; //should be false
     cout << (f33 < (float)0.67) << endl; //should be true
     cout << (f33 < 0) << endl; //should be false
     cout << (f33 < 1) << endl; //should be true
     Fraction neg(-4,6); 
     cout << (neg < 0) << endl; //should be true
     cout << (f32>=f33) << endl;//should be true
     cout << (f33>=f32) << endl;//should be false
     cout << (f32>=0) << endl;//sohuld be true
     cout << (1>=f32) << endl;//sohuld be true
     cout << (f32>=(float)0.5) << endl;//sohuld be true
     cout << (f32>=(float)0.8) << endl;//sohuld be false
     cout << ((float)0.5>=f32) << endl;//sohuld be false
     cout << ((float)0.8>=f32) << endl;//sohuld be true
     cout << (f32 >= f32) << endl;//true
     cout << (f32 <= f32) << endl;//true
     cout << (f32 <= f33) << endl;//false
     cout << (f33 <= f32) << endl;//true
     cout << (f32<=(float)0.5) << endl;//sohuld be false
     cout << (f32<=(float)0.8) << endl;//sohuld be true
     cout << (f32<=0) << endl;//sohuld be false
     cout << (f32<=1) << endl;//sohuld be true

     //-------------------- ++,-- ----------------------------

     Fraction f34(6,4);  
     cout << (f34++).toString() << endl;//should be 6/4
     cout << (++f34).toString() << endl;//should be 7/2
     cout << (f34--).toString() << endl;//should be 7/2
     cout << (--f34).toString() << endl;//should be 3/2


    //-------------------- <<,>> ----------------------------

    Fraction _stdout1 (8,2);
    Fraction _stdout2 (10,15);
    Fraction _stdout3 (-8,2);
    Fraction _stdout4 (-10,15);
    cout << _stdout1 << endl;
    cout << _stdout2 << endl;
    cout << _stdout3 << endl;
    cout << _stdout4 << endl;
    
    Fraction f;
    cout << "Enter numerator and denominator of the fraction: ";
    cin >> f ;
    cout << "the fraction you entered is : " << f << endl;//should be as f



}