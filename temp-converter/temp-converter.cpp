#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <cctype>

#include "temp-converter.h"

using namespace std;

int valid_temp(string);
string remove_unit(string);
string cels_to_fahr(string);
string fahr_to_cels(string);
string kelvin_to_cels(string);
string cels_to_kelvin(string);
string kelvin_to_fahr(string);
string fahr_to_kelvin(string);

int main(int argc, char **argv)
{
    if (!argv[1]) {
        cout << "Problem: You haven't input an argument." << endl;
        exit(1);
    }

    if (!valid_temp(argv[1])) {
        cout << "Problem: You haven't specified a proper temperature." << endl;
        cout << "Please input in form: 16.5C or 29.1F or 67.3K" << endl;
        exit(2);
    }

    string temp = argv[1];
    string conv_temp_one;
    string conv_temp_two;
    char orig_unit = temp[temp.length() - 1];

    if (orig_unit == 'C') {
        conv_temp_one = cels_to_fahr(temp);
        conv_temp_two = cels_to_kelvin(temp);
    } else if (orig_unit == 'F') {
        conv_temp_one = fahr_to_cels(temp);
        conv_temp_two = fahr_to_kelvin(temp);
    } else {
        conv_temp_one = kelvin_to_cels(temp);
        conv_temp_two = kelvin_to_fahr(temp);
    }

    cout << "The converted temperature is: " << conv_temp_one
         << " or " << conv_temp_two << endl;

    return 0;
}

int valid_temp(string tempstr)
{
    char finalchar = tempstr[tempstr.length() - 1];
    int dotcount = 0;

    for (int i = 0; i < tempstr.length() - 1; i++) {
        if (!isdigit(tempstr[i])) {
            if (tempstr[i] == '.') {
                dotcount++;
            } else {
                if (i == 0 and tempstr[i] != '-') {
                    return false;
                    // Can be minus number
                } else if (i != 0) {
                    return false;
                    // Otherwise no non-digits
                }
            }
        }
    }

    if (dotcount > 1) {
        return false;
        // Only allowed one full stop
    }

    if (finalchar != 'C' and finalchar != 'F' and finalchar != 'K') {
        return false;
        // Final character must be valid temp unit
    }

    if (finalchar == 'K') {
        if (tempstr[0] == '-') {
            return false;
            // Can't have below absolute zero
        }
    }

    return true;
}

string cels_to_fahr(string tempstr)
{
    float temp = atof(tempstr.c_str());

    float conv_temp = temp * CELS_FAHR_FACTOR + CELS_FAHR_DIFF;

    ostringstream conv_tempstream;
    conv_tempstream << conv_temp << 'F';
    string conv_tempstr = conv_tempstream.str();
    return conv_tempstr;
}

string fahr_to_cels(string tempstr)
{
    double temp = atof(tempstr.c_str());

    float conv_temp = (temp - CELS_FAHR_DIFF) / CELS_FAHR_FACTOR;

    ostringstream conv_tempstream;
    conv_tempstream << conv_temp << 'C';
    string conv_tempstr = conv_tempstream.str();
    return conv_tempstr;
}

string kelvin_to_cels(string tempstr)
{
    float temp = atof(tempstr.c_str());

    float conv_temp = temp + ABS_ZERO;

    ostringstream conv_tempstream;
    conv_tempstream << conv_temp << 'C';
    string conv_tempstr = conv_tempstream.str();
    return conv_tempstr;
}

string cels_to_kelvin(string tempstr)
{
    float temp = atof(tempstr.c_str());

    float conv_temp = temp - ABS_ZERO;

    ostringstream conv_tempstream;
    conv_tempstream << conv_temp << 'K';
    string conv_tempstr = conv_tempstream.str();
    return conv_tempstr;
}

string kelvin_to_fahr(string tempstr)
{
    return cels_to_fahr(kelvin_to_cels(tempstr));
}

string fahr_to_kelvin(string tempstr)
{
    return cels_to_kelvin(fahr_to_cels(tempstr));
}
