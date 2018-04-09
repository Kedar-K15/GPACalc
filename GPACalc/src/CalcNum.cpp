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
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <sstream>
#include <string>
#include <Windows.h>
#include <algorithm>
#include "CalcNum.h"
#include "CalcMain.h"

void CalcNum::num_calculate() {
    set_null(0, false);

    change_color(1,3);
    std::cout << "Hello! Use this program to calculate your GPA using numbers" << std::endl;
    space();

    change_color(4,4);
    std::cout << "Do not enter negative numbers other than \"-1\" or numbers greater than \"5.0\" " << std::endl;
    space();

    change_color(1,2);
    std::cout << "Press the \"ENTER\" key to continue or enter in \"H\" to refer the \"HELP PAGE\" " << std::endl;

    std::getline(std::cin, num_input);
    if(!is_lower(num_input)) {
        to_lowercase(num_input);
    }

    if(num_input == "h") {
        help();
    }
    else {
        do {
            space();
            change_color(2,2);
            std::cout << "Enter the periods " << "(" << num_of_periods+1 << ")" << " GPA or enter in \"-1\" to calculate: ";
            while(std::getline(std::cin, period_input)) {
                std::stringstream ss_f(period_input);
                if(ss_f >> period) {
                    if(ss_f.eof() && period <= max && period >= min) {
                        // Success
                        num_of_periods++;
                        period_sum += period;
                        break;
                    }
                }

                if(!ss_f.eof()) {
                    change_color(4,4);
                    std::cout << "Incorrect input. Try again: ";
                }
                if(period > max && ss_f.eof()) {
                    change_color(4,4);
                    space();
                    std::cout << "Do not enter a number greater than the max range of \"5.0\" " << std::endl;
                    std::cout  << "Try again: ";
                }
                if(period < min && ss_f.eof()) {
                    change_color(4,4);
                    space();
                    std::cout << "Do not enter a number less than \"-1\" for calculation purposes only" << std::endl;
                    std::cout << "Try again: ";
                }
            }

            if(period == min) {
                period_sum += 1.0;
                num_of_periods -= 1.0;
                total_avg = period_sum/num_of_periods;
            }
        } while(period != min);

        results();
    }
}
