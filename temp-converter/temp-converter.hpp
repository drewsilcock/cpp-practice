#include <iostream> // For `<<`
#include <sstream> // For `ostringstream`
#include <cstdlib> // For `exit`
using namespace std;

// Constants for conversion calculations
#define CELS_FAHR_FACTOR 1.8
#define CELS_FAHR_DIFF 32
#define ABS_ZERO -273.15
#define CELSIUS 'C'
#define FAHRENHEIT 'F'
#define KELVIN 'K'

// Function declarations
int valid_temp(string);

class Temperature {
    protected:
        float cels_to_fahr(float temp)
        {
            return temp * CELS_FAHR_FACTOR + CELS_FAHR_DIFF;
        }

        float fahr_to_cels(float temp)
        {
            return (temp - CELS_FAHR_DIFF) / CELS_FAHR_FACTOR;
        }

        float kelv_to_cels(float temp)
        {
            return temp + ABS_ZERO;
        }

        float cels_to_kelv(float temp)
        {
            return temp - ABS_ZERO;
        }

        float kelv_to_fahr(float temp)
        {
            return cels_to_fahr(kelv_to_cels(temp));
        }

        float fahr_to_kelv(float temp)
        {
            return cels_to_kelv(fahr_to_cels(temp));
        }
    public:
        float temp;
        char unit;

        Temperature() {} // Default constructor
        Temperature(string tempstr) {
            temp = atof(tempstr.c_str());
            unit = tempstr[tempstr.length() - 1];
        } // Overloaded constructor for string input, e.g. "17.3C"

        Temperature(float init_temp, char init_unit) {
            temp = init_temp;
            unit = init_unit;
        } // Overloaded constructor for float, char input, e.g. 17.3, 'C'

        Temperature to_cels() {
            if (unit == FAHRENHEIT) {
                return Temperature(fahr_to_cels(temp), CELSIUS);
            } else if (unit == KELVIN) {
                return Temperature(kelv_to_cels(temp), CELSIUS);
            } else {
                return Temperature(temp, CELSIUS);
            }
        }

        Temperature to_fahr() {
            if (unit == CELSIUS) {
                return Temperature(cels_to_fahr(temp), FAHRENHEIT);
            } else if (unit == KELVIN) {
                return Temperature(kelv_to_fahr(temp), FAHRENHEIT);
            } else {
                return Temperature(temp, FAHRENHEIT);
            }
        }

        Temperature to_kelv() {
            if (unit == CELSIUS) {
                return Temperature(cels_to_kelv(temp), KELVIN);
            } else if (unit == FAHRENHEIT) {
                return Temperature(fahr_to_kelv(temp), KELVIN);
            } else {
                return Temperature(temp, KELVIN);
            }
        }

        string to_str() {
            ostringstream tempstream;
            tempstream << temp << unit;
            return tempstream.str();
        }
};
