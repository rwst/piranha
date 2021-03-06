/***************************************************************************
 *   Copyright (C) 2009-2011 by Francesco Biscani                          *
 *   bluescarni@gmail.com                                                  *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef PIRANHA_SFINAE_TYPES_HPP
#define PIRANHA_SFINAE_TYPES_HPP

#include <array>

namespace piranha
{

namespace detail
{

// Types for SFINAE-based type traits.
// Guidelines for usage:
// - decltype-based SFINAE,
// - use std::is_same in the value of the type trait,
// - use (...,void(),yes/no()) in the decltype in order to avoid problems with
//   overloads of the comma operator.
struct sfinae_types
{
	struct yes {};
	struct no {};
};

}

}

#endif
