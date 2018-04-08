#ifndef CALCMAIN_H
#define CALCMAIN_H

/* All rights to Kedar Kulkarni */

class CalcMain
{
    public:
        void start_main();

    protected:
        void space();
        void change_color(unsigned int first_color, unsigned int second_color);
        void help();
        void restart();
        void end_screen();
        void clear_screen();
        void table();
        void results();
        void to_calcnum();
        void to_calcalpha();
        void set_null(const unsigned int num, bool var);
        std::string to_lowercase(std::string& input_given);
        bool is_lower(const std::string& input_given);

        const unsigned int a_grade = 4;
        float period;
        float period_sum;
        float num_of_periods;
        float total_avg;
        std::string restart_if;
        bool entered_correctly;

    private:
        std::string main_input;
        std::string store_if;
        std::string store_grade;
        bool found_file = false;
        const std::string from = "GPACalc.exe";
        const std::string to = "GPAData.txt";
        bool replace(std::string& str, const std::string& from, const std::string& to);
        void save_data(float period_sum, float num_of_periods, float total_avg);
        float final_grade(float a_grade, float total_avg);
        void save_rand();
        time_t tt;
        std::string file_directory;
        std::string rand_directory;
};

#endif // CALCMAIN_H
