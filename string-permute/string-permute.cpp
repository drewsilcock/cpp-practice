#include <iostream>
#include <cstdlib>
using namespace std;

int factorial(int);
string permute(int, string);
void swap(string&, int, int);

int main(int argc, char **argv)
{
    if (!argv[1]) {
        cout << "Error: Please input a string to permute." << endl;
        exit(1);
    }

    string str = argv[1];
    int num_chars = str.length();

    // Max length, ignoring repetitions, is simply length!
    int num_perms = factorial(num_chars);

    cout << num_perms << endl;

    const char* perms[num_perms][num_chars+1];

    for (int k = 0; k < num_perms; k++) {
        perms[k] = permute(k, str).c_str();
        cout << perms[k] << endl;
    }

    return 0;
}

int factorial(int num)
{
    if (num < 0) {
        return -1; // Undefined
    }

    if (num == 0) {
        return 1; // By definition
    }

    int fact = num * factorial(num - 1);
    // Standard recursive definition

    return fact;
}

string permute(int k, string str)
{
    for (int j = 1; j < str.size(); ++j) {
        swap(str, k % (j + 1), j);
        k = k / (j + 1);
    }

    return str;
}

void swap(string &str, int i, int j)
{
    char tempchar = str[i];

    str[i] = str[j];
    str[j] = tempchar;
}
