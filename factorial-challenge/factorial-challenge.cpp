#include <iostream> // <<
#include <cstdlib> // exit
#include <stdexcept> // std::out_of_range, std::invalid_argument
using namespace std;

int find_zeros(int);

int main(int argc, char **argv)
{
    if (argc != 2) {
        cerr << "Error: Invalid number of arguments. Please input integer "
            "as first argument only." << endl;
        exit(1);
    }

    int number;
    try {
        number = stoi(argv[1]);
    } catch (out_of_range) {
        cerr << "Error: Provided integer out of valid range." << endl;
        exit(2);
    } catch (invalid_argument) {
        cerr << "Error: Invalid integer." << endl;
        exit(2);
    }

    if (number < 0) {
        cerr << "Error: Please enter a positive definite (>= 0) integer."
             << endl;
        exit(2);
    }

    cout << "Your number is " << number << endl;
    cout << "The number of zeros in " << number << "! is "
         << find_zeros(number) << endl;

    return 0;
}

int find_zeros(int number)
{
    int num_zeros = 0;

    for (int five_fact = 5; five_fact <= number; five_fact *= 5) {
        num_zeros += number / five_fact;
    }

    return num_zeros;
}
