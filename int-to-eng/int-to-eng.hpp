#include <iostream> // <<
#include <cstdlib> // exit()
#include <stdexcept> // std::out_of_range, std::invalid_argument
using namespace std;

#define THOUSAND 1000
#define MILLION 1000000
#define BILLION 1000000000

string int_to_eng(int);
bool is_valid_int(string);
string how_to_say_hundreds(int);
string how_to_say_tens(int);
string word_for_tens(int);
string word_for_ones(int);
string word_for_teens(int);
