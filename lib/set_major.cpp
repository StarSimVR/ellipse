/*
 * Copyright (C) 2022 Kevin Matthes
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
 * \author      Kevin Matthes
 * \brief       The setter for `Ellipse :: major`.
 * \copyright   (C) 2022 Kevin Matthes.
 *              This file is licensed GPL 2 as of June 1991.
 * \date        2022
 * \file        set_major.cpp
 * \note        See `LICENSE' for full license.
 *              See `README.md' for project details.
 *
 * Since `major` is a private attribute, it should be set exclusively using this
 * method.
 */

/******************************************************************************/

/*
 * Includes.
 */

#include "Ellipse.hpp"



/**
 * \brief   Reset this ellipse's major.
 *
 * Set this ellipse's major to `0.f`.
 */

inline void Ellipse :: set_major (void)
{
    this -> set_major (0.f);
    return;
}



/**
 * \brief   The setter method for `Ellipse :: major`.
 * \param   major   This ellipse's major.
 *
 * Since `major` is a private attribute, it should be set exclusively using this
 * method.
 */

inline void Ellipse :: set_major (const float major)
{
    this -> major = major;
    return;
}

/******************************************************************************/
