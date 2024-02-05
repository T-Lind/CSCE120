/******************************************************************************

File: main.cpp
Author: Prof. Lupoli & Andrew Nemec
Date: 2/16/2021
Section: 
E-mail: slupoli@tamu.edu
Description:
This file contains C++  code that will simulate data collected from a track 
event with 9 lanes. The code will sort the order, then display the results

Updates
Author: J. Michael Moore & Paul Taele
Author: J. Michael Moore

Input information format
<Time (double)> <Abbreviated Country (String)> <Uniform number (int)> <Lastname (String)>
32.7 USA 12 Moore
36.5 RUS 35 Polsley
45.8 ENG 73 Teale
52.34 CHN 14 Nemec
76.45 ITY 23 Lupoli     

*******************************************************************************/

#include <iostream>
#include <cstring>
#include "parallel_tracks.h"

using std::cin;
using std::cout;
using std::endl;

#define N_LANES 9

int main() {
    double time[N_LANES];
    char country[N_LANES][STRING_SIZE];
    unsigned int number[N_LANES];
    char lastname[N_LANES][STRING_SIZE];
    unsigned int rank[N_LANES];

    prep_double_array(time);
    prep_unsigned_int_array(number);
    prep_string_array(country);
    prep_string_array(lastname);

    if (!get_runner_data(time, country, number, lastname)) {
        cout << "Error reading data" << endl;
        return 1;
    }

    get_ranking(time, rank);


    print_results(time, country, lastname, rank);

    // this is not required in C++ but many people still explitly add it
    return 0;
}

