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
#include <string>
#include <algorithm>
#include <memory>
#include <fstream>
#include <chrono>
#include <ratio>
#include <ctime>
#include "CalcMain.h"
#include "CalcNum.h"
#include "CalcAlpha.h"

using namespace std::chrono;

void CalcMain::start_main() {
    set_null(0, false);
    change_color(1,3);
    std::cout << "Hello! This is a program to calculate your Grade Point Average \n";
    space();

    std::cout << "You may calculate by either entering in numbers or letter grades \n";
    change_color(1,4);
    std::cout << "Enter in \"1\" for numbers or \"2\" for letters \n";
    std::cout << "Enter in \"H\" for the \"HELP PAGE\" \n";
    space();
    change_color(2,2);
    std::cout << "Choose the calculator type: ";
    while(!entered_correctly) {
        std::getline(std::cin, main_input);
        if(!is_lower(main_input)) {
            to_lowercase(main_input);
        }

        if(main_input == "1") {
            entered_correctly = true;
            clear_screen();
            to_calcnum();
        }
        else if(main_input == "2") {
            entered_correctly = true;
            clear_screen();
            to_calcalpha();
        }
        else if(main_input == "h") {
            entered_correctly = true;
            help();
        }
        else {
            change_color(4,4);
            std::cout << "Incorrect input" << std::endl;
            std::cout << "Try again: ";
        }
    }
}

void CalcMain::space() {
    std::cout << std::endl;
}

void CalcMain::change_color(unsigned int first_color, unsigned int second_color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, first_color | second_color | FOREGROUND_INTENSITY);
}

void CalcMain::help() {
    set_null(0, false);
    clear_screen();

    change_color(1,2);
        std::cout << "Hi! Welcome to the GPA Calculator Help Screen.\n";
        space();
        std::cout << "Below are some things that can help you: \n";
        space();

    change_color(4,4);
    std::cout << "***This program is not case-sensitive to any degree***\n";
    change_color(1,4);
    std::cout << "In the numbers calculator: \n";
    change_color(4,4);
        std::cout << "***Refrain from entering any non-numerical values, \n";
        std::cout << " negative numbers other than \"-1\" to calculate, and numbers greater than \"5.0\"*** \n";
    change_color(1,4);
    std::cout << "In the letters calculator: \n";
    change_color(4,4);
        std::cout << "***Refrain from entering any numerical values other than \"-1\" or \"-2\", \n";
        std::cout << " and letters other than the ones shown in the table below*** \n";
    space();

    change_color(1,4);
    std::cout << "How to use the program: \n";
        std::cout << " This is a program to calculate your Grade Point Average in two different ways. Follow these steps: \n";
        std::cout << "  1. From the menu, enter in \"1\" for the numbers calculator, \"2\" for the letters calculator, or \"H\" for this page \n";
        std::cout << "  2. When prompted, start entering your GPA values in letter or numerical form, depending on the calculator \n";
        change_color(4,4);
        std::cout << "     NOTE: For the letters calculator: Entering \"Y\" will ask you what type of class you have entered, \n";
        std::cout << "     entering \"N\" will not \n";
        std::cout << "     NOTE: You must press the \"ENTER\" key after each value \n";
        change_color(1,4);
        std::cout << "  3. After you have entered all of your values, press the \"ENTER\" key one more time and type in \"-1\" to calculate \n";
        change_color(4,4);
        std::cout << "     NOTE: If you entered an incorrect value, type in \"-2\" to go back to the previous period \n";
        std::cout << "     NOTE: Entering this integer will not affect your GPA value \n";
        change_color(1,4);
        std::cout << "  4. That's it! You will see text in purple containing all the information you need \n";

    space();
    std::cout << "Write to file functionality: \n";
        std::cout << " After you obtain your results, the program will automatically write them to a text file given \n";
        change_color(4,4);
        std::cout << " NOTE: The application and notepad file must be in the same folder directory \n";
        std::cout << " NOTE: The application must be named: " << from << '\n';
        std::cout << " NOTE: The notepad file must be named: " << to << '\n';
        change_color(1,4);
        std::cout << " Any other file paths will return in an error message in the program \n";
        std::cout << " You have the option to enter another file path for the program to write the data to \n";
        change_color(4,4);
        std::cout << " NOTE: You must enter this file path every time you want to write data to the file \n";
        change_color(1,4);

    space();

    change_color(2,2);
    std::cout << "Below is a Grade Point Average Table for your reference: \n";
        space();
        table();
    change_color(4,1);
        space();
    std::cout << "Contact Me: \n";
        std::cout << "Email me any suggestions at: dev.kedarkulkarni@gmail.com \n";
        space();

    change_color(4,4);
        std::cout << "This program was made by Kedar Kulkarni \n";

    restart();
}

void CalcMain::restart() {
    entered_correctly = false;
    space();
    change_color(1,2);
    std::cout << "Would you like to calculate your GPA? Enter in \"1 or 2\" to restart the program or \"S\" to stop it \n";
    std::cout << "1: Numbers; 2: Letters \n";
    space();
    std::cout << "Enter here: ";

    while(!entered_correctly) {
        std::getline(std::cin, restart_if);
        if(!is_lower(restart_if)) {
            to_lowercase(restart_if);
        }

        if(restart_if == "1") {
            entered_correctly = true;
            clear_screen();
            to_calcnum();
        }
        else if(restart_if == "2") {
            entered_correctly = true;
            clear_screen();
            to_calcalpha();
        }
        else if(restart_if == "s") {
            entered_correctly = true;
            clear_screen();
            end_screen();
        }
        else {
            change_color(4,4);
            std::cout << "Incorrect input" << std::endl;
            std::cout << "Try again: ";
        }
    }
}

void CalcMain::end_screen() {
    change_color(1,2);
    std::cout << "Thanks for calculating! I hope you liked this program \n";
    space();

    change_color(2,2);
    std::cout << "Email me any suggestions at dev.kedarkulkarni@gmail.com \n";
    space();

    change_color(1,4);
    std::cout << "Version: 1.3.1; 9.4.18 \n";
    space();

    change_color(4,4);
    std::cout << "This program was made by Kedar Kulkarni" << std::endl;

    std::cin.get();
}

void CalcMain::clear_screen() {
    HANDLE                     hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };

  hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  if (hStdOut == INVALID_HANDLE_VALUE) return;

  /* Get the number of cells in the current buffer */
  if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  /* Fill the entire buffer with spaces */
  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Fill the entire buffer with the current colors and attributes */
  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Move the cursor home */
  SetConsoleCursorPosition(hStdOut, homeCoords);
}

void CalcMain::table() {
     std::cout << "Grade Point Average Table: " << std::endl;


	std::cout << std::setfill('-') << std::setw(1) << "+" << std::setw(15) << "-" << std::setw(1) << "+" << std::setw(15) << "-" << std::setw(1) << "+" << std::endl;

	std::cout << std::setfill(' ') << std::setw(1) << "|" << std::setw(15) << std::left << "GPA" << std::setw(1) << "|" << std::setw(15) << std::left << "Letter Grade" << std::setw(1) << "|" << std::endl;

	std::cout << std::setfill('-') << std::setw(1) << "+" << std::setw(15) << "-" << std::setw(1) << "+" << std::setw(15) << "-" << std::setw(1) << "+" << std::endl;

	std::cout << std::setfill(' ') << std::setw(1) << "|" << std::setw(15) << std::left << "4.0-5.0" << std::setw(1) << "|" << std::setw(15) << std::left << " A+" << std::setw(1) << "|" << std::endl;

	std::cout << std::setfill('-') << std::setw(1) << "+" << std::setw(15) << "-" << std::setw(1) << "+" << std::setw(15) << "-" << std::setw(1) << "+" << std::endl;

	std::cout << std::setfill(' ') << std::setw(1) << "|" << std::setw(15) << std::left << "4.0" << std::setw(1) << "|" << std::setw(15) << std::left << " A" << std::setw(1) << "|" << std::endl;

	std::cout << std::setfill('-') << std::setw(1) << "+" << std::setw(15) << "-" << std::setw(1) << "+" << std::setw(15) << "-" << std::setw(1) << "+" << std::endl;

	std::cout << std::setfill(' ') << std::setw(1) << "|" << std::setw(15) << std::left << "3.7" << std::setw(1) << "|" << std::setw(15) << std::left << " A-" << std::setw(1) << "|" << std::endl;

	std::cout << std::setfill('-') << std::setw(1) << "+" << std::setw(15) << "-" << std::setw(1) << "+" << std::setw(15) << "-" << std::setw(1) << "+" << std::endl;

	std::cout << std::setfill(' ') << std::setw(1) << "|" << std::setw(15) << std::left << "3.3" << std::setw(1) << "|" << std::setw(15) << std::left << " B+" << std::setw(1) << "|" << std::endl;

	std::cout << std::setfill('-') << std::setw(1) << "+" << std::setw(15) << "-" << std::setw(1) << "+" << std::setw(15) << "-" << std::setw(1) << "+" << std::endl;

	std::cout << std::setfill(' ') << std::setw(1) << "|" << std::setw(15) << std::left << "3.0" << std::setw(1) << "|" << std::setw(15) << std::left << " B" << std::setw(1) << "|" << std::endl;

	std::cout << std::setfill('-') << std::setw(1) << "+" << std::setw(15) << "-" << std::setw(1) << "+" << std::setw(15) << "-" << std::setw(1) << "+" << std::endl;

	std::cout << std::setfill(' ') << std::setw(1) << "|" << std::setw(15) << std::left << "2.7" << std::setw(1) << "|" << std::setw(15) << std::left << " B-" << std::setw(1) << "|" << std::endl;

	std::cout << std::setfill('-') << std::setw(1) << "+" << std::setw(15) << "-" << std::setw(1) << "+" << std::setw(15) << "-" << std::setw(1) << "+" << std::endl;

	std::cout << std::setfill(' ') << std::setw(1) << "|" << std::setw(15) << std::left << "2.3" << std::setw(1) << "|" << std::setw(15) << std::left << " C+" << std::setw(1) << "|" << std::endl;

	std::cout << std::setfill('-') << std::setw(1) << "+" << std::setw(15) << "-" << std::setw(1) << "+" << std::setw(15) << "-" << std::setw(1) << "+" << std::endl;

	std::cout << std::setfill(' ') << std::setw(1) << "|" << std::setw(15) << std::left << "2.0" << std::setw(1) << "|" << std::setw(15) << std::left << " C" << std::setw(1) << "|" << std::endl;

	std::cout << std::setfill('-') << std::setw(1) << "+" << std::setw(15) << "-" << std::setw(1) << "+" << std::setw(15) << "-" << std::setw(1) << "+" << std::endl;

	std::cout << std::setfill(' ') << std::setw(1) << "|" << std::setw(15) << std::left << "1.7" << std::setw(1) << "|" << std::setw(15) << std::left << " C-" << std::setw(1) << "|" << std::endl;

	std::cout << std::setfill('-') << std::setw(1) << "+" << std::setw(15) << "-" << std::setw(1) << "+" << std::setw(15) << "-" << std::setw(1) << "+" << std::endl;

	std::cout << std::setfill(' ') << std::setw(1) << "|" << std::setw(15) << std::left << "1.3" << std::setw(1) << "|" << std::setw(15) << std::left << " D+" << std::setw(1) << "|" << std::endl;

	std::cout << std::setfill('-') << std::setw(1) << "+" << std::setw(15) << "-" << std::setw(1) << "+" << std::setw(15) << "-" << std::setw(1) << "+" << std::endl;

	std::cout << std::setfill(' ') << std::setw(1) << "|" << std::setw(15) << std::left << "1.0" << std::setw(1) << "|" << std::setw(15) << std::left << " D" << std::setw(1) << "|" << std::endl;

	std::cout << std::setfill('-') << std::setw(1) << "+" << std::setw(15) << "-" << std::setw(1) << "+" << std::setw(15) << "-" << std::setw(1) << "+" << std::endl;

	std::cout << std::setfill(' ') << std::setw(1) << "|" << std::setw(15) << std::left << "0.0" << std::setw(1) << "|" << std::setw(15) << std::left << " F" << std::setw(1) << "|" << std::endl;

	std::cout << std::setfill('-') << std::setw(1) << "+" << std::setw(15) << "-" << std::setw(1) << "+" << std::setw(15) << "-" << std::setw(1) << "+" << std::endl;
}

void CalcMain::results() {
    if(num_of_periods == 0) {
        space();
        change_color(1,4);
        std::cout << "Done! Here are your results: \n";
        space();
        std::cout << "Looks like you did not enter any periods \n";
        restart();
    }
    else {
        space();
        change_color(1,4);
        std::cout << "Done! Here are your results: \n";
        space();
        std::cout << "Number of periods entered: " << num_of_periods << '\n';
        std::cout << "Total sum: " << period_sum << '\n';
        std::cout << "Average GPA: " << total_avg << '\n';

        if (total_avg > a_grade) {
            std::cout << "Final Grade: A+" << std::endl;
            store_grade = "A+";
        }
        else if(total_avg == a_grade) {
            std::cout << "Final Grade: A" << std::endl;
            store_grade = "A";
        }
        else if ( 3.7 <= total_avg && total_avg < a_grade ) {
            std::cout << "Final Grade: A- with a difference of " << final_grade(a_grade, total_avg) << " from an A" << std::endl;
            store_grade = "A-";
        }
        else if ( 3.3 <= total_avg && total_avg < 3.9) {
            std::cout << "Final Grade: B+ with a difference of " << final_grade(a_grade, total_avg) << " from an A" << std::endl;
            store_grade = "B+";
        }
        else if (3.0 <= total_avg && total_avg < 3.3) {
            std::cout << "Final Grade: B with a difference of " << final_grade(a_grade, total_avg) << " from an A" << std::endl;
            store_grade = "B";
        }
        else if (2.7 <= total_avg && total_avg < 3.0) {
            std::cout << "Final Grade: B- with a difference of " << final_grade(a_grade, total_avg) << " from an A" << std::endl;
            store_grade = "B-";
        }
        else if (2.3 <= total_avg && total_avg < 2.7) {
            std::cout << "Final Grade: C+ with a difference of " << final_grade(a_grade, total_avg) << " from an A" << std::endl;
            store_grade = "C+";
        }
        else if (2.0 <= total_avg && total_avg < 2.3) {
            std::cout << "Final Grade: C with a difference of " << final_grade(a_grade, total_avg) << " from an A" << std::endl;
            store_grade = "C";
        }
        else if (1.7 <= total_avg && total_avg < 2.0) {
            std::cout << "Final Grade: C- with a difference of " << final_grade(a_grade, total_avg) << " from an A" << std::endl;
            store_grade = "C-";
        }
        else if (1.3 <= total_avg && total_avg < 1.7) {
            std::cout << "Final Grade: D+ with a difference of " << final_grade(a_grade, total_avg) << " from an A" << std::endl;
            store_grade = "D+";
        }
        else if (1.0 <= total_avg && total_avg < 1.3) {
            std::cout << "Final Grade: D with a difference of " << final_grade(a_grade, total_avg) << " from an A" << std::endl;
            store_grade = "D";
        }
        else {
            std::cout << "Final Grade: F with a difference of " << final_grade(a_grade, total_avg) << " from an A" << std::endl;
            store_grade = "F";
        }
        save_data(period_sum, num_of_periods, total_avg);
    }
}

void CalcMain::to_calcnum() {
    std::unique_ptr<CalcNum> pointernum = std::make_unique<CalcNum>();
    pointernum->num_calculate();
}

void CalcMain::to_calcalpha() {
    std::unique_ptr<CalcAlpha> pointeralpha = std::make_unique<CalcAlpha>();
    pointeralpha->alpha_calculate();
}

std::string CalcMain::to_lowercase(std::string& input_given) {
    std::transform(input_given.begin(), input_given.end(), input_given.begin(), &::tolower);
    return input_given;
}

bool CalcMain::is_lower(const std::string& input_given) {
    return std::any_of(input_given.begin(), input_given.end(), &::islower);
}

void CalcMain::set_null(unsigned int num, bool var) {
    period = num;
    period_sum = num;
    num_of_periods = num;
    total_avg = num;
    entered_correctly = var;
}

bool CalcMain::replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos) {
        return false;
    }

    str.replace(start_pos, from.length(), to);

    return true;
}

void CalcMain::save_data(float period_sum, float num_of_periods, float total_avg) {
        found_file = false;

        system_clock::time_point today = system_clock::now();
        tt = system_clock::to_time_t (today);


        CHAR pBuf[MAX_PATH];
        GetModuleFileName(NULL, pBuf, MAX_PATH); // Get directory of the application
        file_directory = pBuf;

        if(replace(file_directory, from, to)) {
            do {
                entered_correctly = false;

                std::ofstream data_file(file_directory.c_str(), std::ios::in | std::ios::ate); // std::ios_base::app
                if(data_file.is_open()) {
                    data_file << "------------------------------------" << std::endl;
                    data_file << std::endl;
                    data_file << ctime(&tt);
                    data_file << "Number of periods: " << num_of_periods << std::endl;
                    data_file << "Total sum: " << period_sum << std::endl;
                    data_file << "Average GPA: " << total_avg << std::endl;
                    if(store_grade == "A+") {
                        data_file << "Final Grade: " << store_grade << std::endl;
                    }
                    else if(store_grade == "A") {
                        data_file << "Final Grade: " << store_grade << std::endl;
                    }
                    else {
                        data_file << "Final Grade: " << store_grade << " with a difference of " << final_grade(a_grade, total_avg) << " from an A" << std::endl;
                    }

                    data_file << std::endl;
                    data_file.close();

                    store_grade.clear();
                    found_file = true;
                }
                else {
                    space();
                    change_color(4,4);
                    std::cout << "The notepad file path was not found \n";
                    std::cout << "The application and notepad file must be in the same folder directory \n";
                    std::cout << "The application must be named: " << from << '\n';
                    std::cout << "The notepad file must be named: " << to << '\n';
                    std::cout << "The file path: " << file_directory << " does not exist \n";

                    space();
                    change_color(1,4);
                    std::cout << "Would you like to store your data? Enter in \"Y\" if so and \"N\" if not. \n";
                    space();
                    std::cout << "Enter here: ";
                    while(!entered_correctly) {
                        std::getline(std::cin, store_if);
                        if(!is_lower(store_if)) {
                            to_lowercase(store_if);
                        }

                        if(store_if == "y") {
                            entered_correctly = true;
                            save_rand();
                        }
                        else if(store_if == "n") {
                            store_grade.clear();
                            entered_correctly = true;
                        }
                        else {
                            change_color(4,4);
                            std::cout << "Incorrect input" << std::endl;
                            std::cout << "Try again: ";
                        }
                    }
                }
            } while(!found_file && store_if != "n");
        }
        else {
            space();
            change_color(4,4);
            std::cout << "The application file path was not found \n";
            std::cout << "The application and notepad file must be in the same folder directory \n";
            std::cout << "The application must be named: " << from << '\n';
            std::cout << "The notepad file must be named: " << to << '\n';
            std::cout << "You can manually enter the directory of the file or terminate the program and follow the directions above \n";
            space();
            change_color(1,4);
            std::cout << "Would you like to store your data? Enter in \"Y\" if so and \"N\" if not. \n";
            space();
            std::cout << "Enter here: ";
            while(!entered_correctly) {
                std::getline(std::cin, store_if);
                if(!is_lower(store_if)) {
                    to_lowercase(store_if);
                }

                if(store_if == "y") {
                    entered_correctly = true;
                    save_rand();
                }
                else if(store_if == "n") {
                    store_grade.clear();
                    entered_correctly = true;
                }
                else {
                    change_color(4,4);
                    std::cout << "Incorrect input" << std::endl;
                    std::cout << "Try again: ";
                }
            }
        }
    restart();
}

void CalcMain::save_rand() {
    do {
        space();
        change_color(1,4);
        std::cout << "Enter the file name or \"S\" to cancel: ";
        std::getline(std::cin, rand_directory);
        if(rand_directory == "S" || rand_directory == "s") {
            store_grade.clear();
            break;
        }
        std::ofstream rand_data_file(rand_directory.c_str(), std::ios::in | std::ios::ate);

        if(rand_data_file.is_open()) {
            rand_data_file << "------------------------------------" << std::endl;
            rand_data_file << std::endl;
            rand_data_file << ctime(&tt);
            rand_data_file << "Number of periods: " << num_of_periods << std::endl;
            rand_data_file << "Total sum: " << period_sum << std::endl;
            rand_data_file << "Average GPA: " << total_avg << std::endl;
            if(store_grade == "A+") {
                rand_data_file << "Final Grade: " << store_grade << std::endl;
            }
            else if(store_grade == "A") {
                rand_data_file << "Final Grade: " << store_grade << std::endl;
            }
            else {
                rand_data_file << "Final Grade: " << store_grade << " with a difference of " << final_grade(a_grade, total_avg) << " from an A" << std::endl;
            }

            rand_data_file << std::endl;
            rand_data_file.close();

            store_grade.clear();
            found_file = true;
        }
        else {
            space();
            change_color(4,4);
            std::cout << "The file you entered does not exist" << std::endl;
            std::cout << "Try again: ";
        }
    } while(!found_file);
}

float CalcMain::final_grade(float a_grade, float total_avg) {
    return a_grade-total_avg;
}
