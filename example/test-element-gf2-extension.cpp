/* 
 * Copyright (C) 2010 Antoine Joux and Vanessa Vitse 

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>. 
 */

/**
 *  \file test-element-gf2-extension.cpp
 *  \example test-element-gf2-extension.cpp
 *  \brief ElementGF2Extension regression tests.
 *  \ingroup examples
 *  \author Vanessa VITSE, Antoine JOUX, Titouan COLADON
 */

#include <iostream>
#include <vector>
#include "../include/element-gf2-extension.h"

using namespace F4;
using namespace std;

// Global variable
int F4::VERBOSE=2;

int main (int argc, char **argv)
{
    cout << endl;
    cout << "#########################################################" << endl;
    cout << "#                TEST ELEMENT GF2 EXTENSION             #" << endl;
    cout << "#########################################################" << endl << endl;
    
    typedef int32_t baseType;
    
    // Test static void setModulo(baseType modulo);
    /* Modulo = t^8+t^4+t^3+t+1 */
    cout << "________Test setModulo(baseType modulo)________" << endl;
    ElementGF2Extension<baseType>::setModulo(0x11B);
    ElementGF2Extension<baseType> e1;
    e1=ElementGF2Extension<baseType>::getModulo();
    cout << "Modulo =" << e1 << endl << endl;
    
    // Test static void setModulo(std::string modulo);
    cout << "________Test setModulo(std::string modulo)________" << endl;
    ElementGF2Extension<baseType>::setModulo(string("t^8+t^4+t^3+t+1"));
    e1=ElementGF2Extension<baseType>::getModulo();
    cout << "Modulo =" << e1 << endl << endl;
            
    // Test static baseType getModulo();
    cout << "________Test getModulo()________" << endl;
    e1=ElementGF2Extension<baseType>::getModulo();
    cout << "Modulo =" << e1 << endl << endl;
    
    // Test static void setVariableName(std::string var);
    cout << "________Test setVariableName(std::string var)________" << endl;
    ElementGF2Extension<baseType>::setVariableName(string("a"));
    ElementGF2Extension<baseType>::setModulo(string("a^8+a^4+a^3+a+1"));
    e1=ElementGF2Extension<baseType>::getModulo();
    cout << "Modulo =" << e1 << endl << endl;
            
    // Test static baseType getMask();
    cout << "________Test getMask()________" << endl;
    e1=ElementGF2Extension<baseType>::getMask();
    cout << "Mask =" << e1 << endl << endl;
    
    // Test ElementGF2Extension & operator=(baseType element);
    cout << "________Test operator=(baseType element)________" << endl;
    ElementGF2Extension<baseType> e2;
    e2=ElementGF2Extension<baseType>::getModulo() ^ 0xf;
    cout << "e2 = " << e2 << endl << endl;
    
    // Test ElementGF2Extension & operator=(std::string element);
    cout << "________Test operator=(std::string element)________" << endl;
    ElementGF2Extension<baseType> e3;
    e3=string("a^7+a^6+3*a^2+a");
    cout << "e3 =" << e3 << endl << endl;
    
    // Test baseType modulo ();
    cout << "________Test modulo ()________" << endl;
    e2.modulo();
    cout << "e2 = " << e2 << endl << endl;
            
    // Test baseType getElement ();
    cout << "________Test getElement ()________" << endl;
    cout << "e2 = " << e2.getElement() << endl << endl;
            
    // Test ElementGF2Extension<baseType> & addMult(ElementGF2Extension<baseType> const & element, ElementGF2Extension<baseType> const & mult);
    cout << "________Test addMult(ElementGF2Extension<baseType> const & element, ElementGF2Extension<baseType> const & mult)________" << endl;
    e3=string("a^4+a");
    e2=string("a^4+a+1");
    e1=string("a^2");
    e2.addMult(e3, e1);
    cout << "e2 = " << e2 << endl << endl;
    
    // Test ElementGF2Extension<baseType> & addMultBase2(ElementGF2Extension<baseType> const & element, ElementGF2Extension<baseType> const & mult);
    cout << "________Test addMultBase2(ElementGF2Extension<baseType> const & element, ElementGF2Extension<baseType> const & mult)________" << endl;
    e3=string("a^4+a");
    e2=string("a^4+a+1");
    e1=string("a^2");
    e2.addMultBase2(e3, e1);
    cout << "e2 = " << e2 << endl << endl;
    
    // Test ElementGF2Extension<baseType> & addMultBase4(ElementGF2Extension<baseType> const & element, ElementGF2Extension<baseType> const & mult);
    cout << "________Test addMultBase4(ElementGF2Extension<baseType> const & element, ElementGF2Extension<baseType> const & mult)________" << endl;
    e3=string("a^4+a");
    e2=string("a^4+a+1");
    e1=string("a^2");
    e2.addMultBase4(e3, e1);
    cout << "e2 = " << e2 << endl << endl;
    
    // Test ElementGF2Extension<baseType> & addMultBase16(ElementGF2Extension<baseType> const & element, ElementGF2Extension<baseType> const & mult);
    cout << "________Test addMultBase16(ElementGF2Extension<baseType> const & element, ElementGF2Extension<baseType> const & mult)________" << endl;
    e3=string("a^4+a");
    e2=string("a^4+a+1");
    e1=string("a^2");
    e2.addMultBase16(e3, e1);
    cout << "e2 = " << e2 << endl << endl;
    
    // Test ElementGF2Extension<baseType> & addMultBase256(ElementGF2Extension<baseType> const & element, ElementGF2Extension<baseType> const & mult);
    cout << "________Test addMultBase256(ElementGF2Extension<baseType> const & element, ElementGF2Extension<baseType> const & mult)________" << endl;
    e3=string("a^4+a");
    e2=string("a^4+a+1");
    e1=string("a^2");
    e2.addMultBase256(e3, e1);
    cout << "e2 = " << e2 << endl << endl;
    
    // Test ElementGF2Extension<baseType> & inverse();
    cout << "________Test inverse()________" << endl;
    e3=e2;
    e2.inverse();
    cout << "e2.inverse() = " << e2 << ", e2*e3 = " << (e2*e3) << endl << endl;
            
    // Test void printElementGF2Extension (std::ostream & stream) const;
    cout << "________Test printElementGF2Extension (std::ostream & stream)________" << endl;
    cout << "e2 = "; 
    e2.printElementGF2Extension(cout); 
    cout << endl << endl;
            
    // Test bool isZero() const;
    cout << "________Test isZero()________" << endl;
    cout << "e2 == 0: " << e2.isZero() << endl << endl;
            
    // Test bool isOne() const;
    cout << "________Test isOne()________" << endl;
    cout << "e2 == 1: " << e2.isOne() << endl << endl;
            
    // Test void setZero();
    cout << "________Test setZero()________" << endl;
    e2.setZero();
    cout << "e2 == 0: " << e2.isZero() << endl << endl;
            
    // Test void setOne();
    cout << "________Test setOne()________" << endl;
    e2.setOne();
    cout << "e2 == 1: " << e2.isOne() << endl << endl;
            
    // Test ElementGF2Extension & operator*=(ElementGF2Extension const & mult); 
    cout << "________Test operator*=(ElementGF2Extension const & mult)________" << endl;
    e3=string("a^7+a^6+3*a^2+a");
    e2=string("a^4+a+1");
    cout << "e3 = " << e3 << ", e2 = " << e2 << endl;
    e3*=e2;
    cout << "e3 *= e2: " << e3 << endl << endl;
    
    // Test ElementGF2Extension & multBase2(ElementGF2Extension const & mult); 
    cout << "________Test multBase2(ElementGF2Extension const & mult)________" << endl;
    e3=string("a^7+a^6+3*a^2+a");
    e2=string("a^4+a+1");
    cout << "e3 = " << e3 << ", e2 = " << e2 << endl;
    e3.multBase2(e2);
    cout << "e3 *= e2: " << e3 << endl << endl;
            
    // Test ElementGF2Extension & multBase4(ElementGF2Extension const & mult); 
    cout << "________Test multBase4(ElementGF2Extension const & mult)________" << endl;
    e3=string("a^7+a^6+3*a^2+a");
    e2=string("a^4+a+1");
    cout << "e3 = " << e3 << ", e2 = " << e2 << endl;
    e3.multBase4(e2);
    cout << "e3 *= e2: " << e3 << endl << endl;
    
    // Test ElementGF2Extension & multBase16(ElementGF2Extension const & mult); 
    cout << "________Test multBase16(ElementGF2Extension const & mult)________" << endl;
    e3=string("a^7+a^6+3*a^2+a");
    e2=string("a^4+a+1");
    cout << "e3 = " << e3 << ", e2 = " << e2 << endl;
    e3.multBase16(e2);
    cout << "e3 *= e2: " << e3 << endl << endl;
    
    // Test ElementGF2Extension & multBase256(ElementGF2Extension const & mult); 
    cout << "________Test multBase256(ElementGF2Extension const & mult)________" << endl;
    e3=string("a^7+a^6+3*a^2+a");
    e2=string("a^4+a+1");
    cout << "e3 = " << e3 << ", e2 = " << e2 << endl;
    e3.multBase256(e2);
    cout << "e3 *= e2: " << e3 << endl << endl;
    
    // Test ElementGF2Extension<baseType> operator * (ElementGF2Extension<baseType> const & element1, ElementGF2Extension<baseType> const & element2);
    cout << "________Test operator * (ElementGF2Extension<baseType> const & element1, ElementGF2Extension<baseType> const & element2)________" << endl;
    e3=string("a^7+a^6+3*a^2+a");
    e2=string("a^4+a+1");
    cout << "e3 = " << e3 << ", e2 = " << e2 << endl;
    cout << "e2 * e3: " << (e2*e3) << endl << endl;
    
    // Test ElementGF2Extension<baseType> operator - (ElementGF2Extension<baseType> const & element);
    cout << "________Test operator - (ElementGF2Extension<baseType> const & element)________" << endl;
    cout << "-e3: " << (-e3) << endl << endl;
    
    
    return 0;
}