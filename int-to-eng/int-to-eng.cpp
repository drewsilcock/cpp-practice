#include "int-to-eng.hpp"
using namespace std;

int main(int argc, char** argv)
{
    if (!argv[1]) {
        cerr << "Error: Please enter an integer." << endl;
        exit(1);
    }

    int number;
    try {
        number = stoi(argv[1]);
    } catch (out_of_range) {
        cerr << "Error: Provided integer out of valid range." << endl
             << "Please input an integer between -2 billion and 2 billion."
             << endl;
        exit(2);
    } catch (invalid_argument) {
        cerr << "Error: Invalid integer." << endl
             << "Please enter a valid integer." << endl;
        exit(2);
    }

    string english = int_to_eng(number);

    cout << english << endl;

    return 0;
}

string int_to_eng(int number)
{
    // Takes any valid integer and returns how to say it in English
    int billions = number / BILLION;
    int millions = (number / MILLION) % THOUSAND;
    int thousands = (number / THOUSAND) % THOUSAND;
    int remaining = (number % THOUSAND);

    string english;

    if (billions != 0) {
        english += word_for_ones(billions) + " billion";
    }

    if (millions != 0) {
        english += ", " + how_to_say_hundreds(millions) + "million";
    }

    if (thousands != 0) {
        english += ", " + how_to_say_hundreds(thousands) + "thousand";
    }

    if (remaining != 0) {
        english += ", " + how_to_say_hundreds(remaining);
    }

    return english;
}

string how_to_say_hundreds(int hundreds)
{
    // Takes number between 0 and 999 and outputs how you'd say it in English

    string eng;

    if (hundreds >= 100) {
        int hund_fact = hundreds / 100;
        int ten_fact = hundreds % 100;
        eng += word_for_ones(hund_fact) + " hundred ";

        if (ten_fact != 0) {
            return eng + "and " + how_to_say_tens(ten_fact);
        } else {
            return eng + how_to_say_tens(ten_fact);
        }
    } else {
        return how_to_say_tens(hundreds);
    }

    cerr << "Error: Error trying to say " << hundreds << endl;
}

string how_to_say_tens(int tens)
{
    // Takes number between 10 and 99 and outputs how you'd say it in English

    string eng;

    if (tens > 19) {
        // Can be pronounced as e.g. `sixty five`
        int ten_factor = tens / 10;
        int one_factor = tens % 10;

        eng += word_for_tens(ten_factor);

        if (one_factor == 0) {
            return eng;
        } else {
            return eng + " " + word_for_ones(one_factor);
        }
    } else if (tens > 10) {
        // It's a `teen`, so is pronounced uniquely, e.g. `seventeen`
        return word_for_teens(tens);
    } else if (tens == 10) {
        return "ten";
    } else {
        // Is less than 10, so can be pronounced as just a plain digit
        return word_for_ones(tens);
    }

    cerr << "Error: Error trying to say " << tens << endl;
}

string word_for_tens(int ten_factor)
{
    // Takes number between 2 and 9 and returns how to say it as factor of ten

    switch(ten_factor) {
        case 2: return "twenty"; break;
        case 3: return "thirty"; break;
        case 4: return "fourty"; break;
        case 5: return "fifty"; break;
        case 6: return "sixty"; break;
        case 7: return "seventy"; break;
        case 8: return "eighty"; break;
        case 9: return "ninety"; break;
    }

    cerr << "Error: Error trying to say " << ten_factor << endl;
}

string word_for_ones(int one_factor)
{
    // Takes number between 0 and 9 and return how to say it in English

    switch(one_factor) {
        case 0: return ""; break;
        case 1: return "one"; break;
        case 2: return "two"; break;
        case 3: return "three"; break;
        case 4: return "four"; break;
        case 5: return "five"; break;
        case 6: return "six"; break;
        case 7: return "seven"; break;
        case 8: return "eight"; break;
        case 9: return "nine"; break;
    }

    cerr << "Error: Error trying to say " << one_factor << endl;
}

string word_for_teens(int teens)
{
    // Takes 'teen' number between 11 and 19 inclusive and returns how to say it

    switch(teens) {
        case 11: return "eleven"; break;
        case 12: return "twelve"; break;
        case 13: return "thirteen"; break;
        case 14: return "fourteen"; break;
        case 15: return "fifteen"; break;
        case 16: return "sixteen"; break;
        case 17: return "seventeen"; break;
        case 18: return "eighteen"; break;
        case 19: return "nineteen"; break;
    }

    cerr << "Error: Error trying to say " << teens << endl;
}
