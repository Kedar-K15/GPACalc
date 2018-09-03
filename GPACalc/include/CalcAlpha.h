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
#ifndef CALCALPHA_H
#define CALCALPHA_H

#include "CalcMain.h"
#include <unordered_map>

class CalcAlpha : protected CalcMain
{
    public:
        void alpha_calculate();

    private:
        bool in_map(const std::string& grade, const std::unordered_map<std::string,float>& given);

        std::string advanced_if;
        std::string letter_input;
        std::string alpha_input;
        std::string which_advanced;
        const float honors = 0.5;
        const unsigned int AP = 1.0;
        bool terminated;
        bool selected_advanced;
        std::vector<int> history;

        std::unordered_map<std::string,float> grades = {
            {"a", 4},
            {"a-", 3.7},
            {"b+", 3.3},
            {"b", 3},
            {"b-", 2.7},
            {"c+", 2.3},
            {"c", 2},
            {"c-", 1.7},
            {"d+", 1.3},
            {"d", 1.0},
            {"f", 0},
    };
};

#endif // CALCALPHA_H
