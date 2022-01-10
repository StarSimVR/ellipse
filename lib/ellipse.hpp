/*
 * Copyright (C) 2021 Kevin Matthes
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/**
 * \file    ellipse.hpp
 * \brief   Introducing the `Ellipse' class.
 *
 * \author      Kevin Matthes
 * \copyright   (C) 2021 Kevin Matthes, 2022 Niklas Leukroth.
 *              This file is licensed GPL 2 as of June 1991.
 * \date        2021 -- 2022
 * \note        See `LICENSE' for full license.
 *              See `README.md' for project details.
 */

/******************************************************************************/

/*
 * Security settings.
 */

#pragma once
#ifndef __ELLIPSE_HPP__
#define __ELLIPSE_HPP__

/*
 * Make dll under windows, else compile normally
*/
#ifdef _WINDOWS
#ifdef _MAKEDLL
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __declspec(dllimport)
#endif	// ! _MAKEDLL
#else
#define EXPORT
#endif	// !_WINDOWS



/*
 * Includes.
 */

#include <cmath>
#include <functional>
#include <vector>


using std::abs;
using std::acos;
using std::cos;
using std::function;
using std::sin;
using std::sqrt;
using std::vector;



/*
* Class definition.
*/

class Ellipse
{
private:
	float   major{ 0. };
	float   minor{ 0. };

	function <float(const float)>  x
	{ [=](const float t) -> float {return cos(t); } };

	function <float(const float)>  y
	{ [=](const float t) -> float {return sin(t); } };

	function <float(const float)>  z
	{ [=](const float t) -> float {return 0.f * t; } };

public:
	EXPORT Ellipse(const float r
		, const float e
		, const float cx
		, const float cy
		, const float cz
		, const float tx
		, const float ty
		, const float tz
		, const float nx
		, const float ny
		, const float nz
	);

	EXPORT vector <float> eval(const float t);
};

/*
 * End of header.
 */

// Tidying up.
#ifndef __ELLIPSE_INTERNAL__
#endif  // ! __ELLIPSE_INTERNAL__

// Leaving the header.
#endif  // ! __ELLIPSE_HPP__

/******************************************************************************/
