#ifndef CALCNUM_H
#define CALCNUM_H

#include "CalcMain.h"

/* All rights to Kedar Kulkarni */

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
