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
  * \file term.inl
  * \brief Definition of Term methods.
  * \author Vanessa VITSE, Antoine JOUX, Titouan COLADON
  */

#ifndef F4_TERM_INL
#define F4_TERM_INL

namespace F4
{
    template <typename Element>
    Term<Element>::Term(Element coeff, Monomial * mon): _coefficient(coeff), _monomial(mon)
    {
    }
    
    template <typename Element>
    Term<Element>::~Term()
    {
        _coefficient.~Element();
    }
}

#endif // F4_TERM_INL