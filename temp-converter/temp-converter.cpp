#include "temp-converter.hpp"
using namespace std;

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

    string tempstr = argv[1];
    Temperature conv_temp_one;
    Temperature conv_temp_two;

    Temperature temp = Temperature(tempstr);

    if (temp.unit == CELSIUS) {
        conv_temp_one = temp.to_fahr();
        conv_temp_two = temp.to_kelv();
    } else if (temp.unit == FAHRENHEIT) {
        conv_temp_one = temp.to_cels();
        conv_temp_two = temp.to_kelv();
    } else {
        conv_temp_one = temp.to_cels();
        conv_temp_two = temp.to_fahr();
    }

    cout << "The converted temperature is: " << conv_temp_one.to_str()
         << " or " << conv_temp_two.to_str() << endl;

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

    if (finalchar != CELSIUS and finalchar != FAHRENHEIT
            and finalchar != KELVIN) {
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
