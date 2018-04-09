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
#include <string>
#include <unordered_map>
#include <stdexcept>
#include "CalcAlpha.h"
#include "CalcMain.h"

bool CalcAlpha::in_map(const std::string& grade, const std::unordered_map<std::string,float>& given) {
    std::unordered_map<std::string,float>::const_iterator found = given.find(grade);
    return found != given.end();
}

void CalcAlpha::alpha_calculate() {
    set_null(0, false);
    terminated = false;
    selected_advanced = false;

    change_color(1,3);
    std::cout << "Hello! Use this program to calculate your GPA using letters" << std::endl;
    space();

    change_color(4,4);
    std::cout << "Only enter letters shown on the table in the \"HELP PAGE\" and do not enter numbers other than \"-1\" to calculate" << std::endl;
    space();

    change_color(1,2);
    std::cout << "Press the \"ENTER\" key to continue or enter in \"H\" to refer the \"HELP PAGE\" " << std::endl;

    std::getline(std::cin, alpha_input);
    if(!is_lower(alpha_input)) {
        to_lowercase(alpha_input);

    }

    if(alpha_input == "h") {
        help();
    }
    else {
        change_color(2,2);
        space();
        std::cout << "Are there any honors or AP classes in your schedule? Enter in \"Y\" if so and \"N\" if not" << std::endl;
        space();
        std::cout << "Enter here: ";
        while(!entered_correctly) {
            std::getline(std::cin, advanced_if);
            if(!is_lower(advanced_if)) {
                to_lowercase(advanced_if);
            }

            if(advanced_if == "y") {
                selected_advanced = true;
                entered_correctly = true;
            }
            else if(advanced_if == "n") {
                entered_correctly = true;
            }
            else {
                change_color(4,4);
                std::cout << "Incorrect input. Try again: ";
            }
        }

        do {
            entered_correctly = false;
            space();
            change_color(2,2);
            std::cout << "Enter the periods " << "(" << num_of_periods+1 << ")" << " letter GPA or enter in \"-1\" to calculate: ";
            try {
                std::getline(std::cin, letter_input);
                if(!(is_lower(letter_input))) {
                    to_lowercase(letter_input);
                }

                if(!in_map(letter_input, grades) && letter_input != "-1") {
                    change_color(4,4);
                    std::cout << "Incorrect input. Try again: " << std::endl;
                }
                else if(letter_input == "-1") {
                    total_avg = period_sum/num_of_periods;
                    terminated = true;
                }
                else {
                    num_of_periods++;
                    period = grades.at(letter_input);
                    if(selected_advanced) {
                        change_color(4,3); // white
                        space();
                        std::cout << "Enter \"HN\" for honors, \"AP\" for AP, or \"N\" for neither: ";

                        while(!entered_correctly) {
                            std::getline(std::cin, which_advanced);
                            if(!(is_lower(which_advanced))) {
                                to_lowercase(which_advanced);
                            }

                            if(which_advanced == "hn") {
                                period_sum += (period+honors);
                                entered_correctly = true;
                            }
                            else if(which_advanced == "ap") {
                                period_sum += (period+AP);
                                entered_correctly = true;
                            }
                            else if(which_advanced == "n") {
                                period_sum += period;
                                entered_correctly = true;
                            }
                            else {
                                std::cout << "Incorrect input. Try again: ";
                            }
                        }
                    }
                    else {
                        period_sum += period;
                    }
                }
            }
            catch (const std::out_of_range& oor) {
                space();
                change_color(4,4);
                std::cout << "Out of range error: " << oor.what() <<  std::endl;
                std::cout << "Contact the developer about your issue" << std::endl;
                restart();
                break;
            }
        } while(letter_input != "-1");

        if(terminated) {
            results();
        }
    }
}
