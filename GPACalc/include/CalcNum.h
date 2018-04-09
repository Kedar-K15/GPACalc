/**
GPACalc: A program that calculates one's Grade Point Average
Copyright (C) 2018  Kedar Kulkarni

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
**/
#ifndef CALCNUM_H
#define CALCNUM_H

#include "CalcMain.h"

class CalcNum : protected CalcMain
{
    public:
        void num_calculate();

    private:
        unsigned const int max = 5;
        const int min = -1;
        std::string period_input;
        std::string num_input;
};

#endif // CALCNUM_H
