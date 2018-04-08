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
