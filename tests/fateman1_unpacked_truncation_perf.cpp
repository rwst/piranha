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

#include "fateman1.hpp"

#define BOOST_TEST_MODULE fateman1_unpacked_test
#include <boost/test/unit_test.hpp>

#include <boost/lexical_cast.hpp>

#include "../src/environment.hpp"
#include "../src/monomial.hpp"
#include "../src/mp_integer.hpp"
#include "../src/polynomial.hpp"
#include "../src/settings.hpp"

using namespace piranha;

// Fateman's polynomial multiplication test number 1. Calculate:
// f * (f+1)
// where f = (1+x+y+z+t)**20, using unpacked monomials. Truncate the result to degree 20 and 30.

BOOST_AUTO_TEST_CASE(fateman1_unpacked_test)
{
	environment env;
	if (boost::unit_test::framework::master_test_suite().argc > 1) {
		settings::set_n_threads(boost::lexical_cast<unsigned>(boost::unit_test::framework::master_test_suite().argv[1u]));
	}
	polynomial<integer,monomial<signed char>>::set_auto_truncate_degree(20);
	BOOST_CHECK_EQUAL((fateman1<integer,monomial<signed char>>().size()),10626u);
	polynomial<integer,monomial<signed char>>::set_auto_truncate_degree(30);
	BOOST_CHECK_EQUAL((fateman1<integer,monomial<signed char>>().size()),46376u);
}
