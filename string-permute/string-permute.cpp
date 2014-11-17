#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;

int factorial(int);
string permute(int, string);
void swap(string&, int, int);
void print_usage();
void remove_duplicates(vector<string>&);

int main(int argc, char **argv)
{
    if (!argv[1]) {
        cout << "Error: Please input a string to permute." << endl;
        print_usage();
        exit(1);
    }

    bool no_dup_flag = false;
    if (argv[2]) {
        if (!strcmp(argv[2], "--no-duplicates") or !strcmp(argv[2], "-n")) {
                no_dup_flag = true;
        }
    }

    string str = argv[1];
    int num_chars = str.length();

    // Max length, ignoring repetitions, is simply length!
    int num_perms = factorial(num_chars);

    vector<string> perms(num_perms);

    for (int k = 0; k < num_perms; k++) {
        perms[k] = permute(k, str);
    }

    if (no_dup_flag) {
        remove_duplicates(perms);
    }

    cout << "Possible permutations:" << endl;
    for (int i=0; i < perms.size(); i++) {
        cout << perms[i] << endl;
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

void remove_duplicates(vector<string> &string_vec)
{
    // Removes all duplicate strings within vector `string_vec`.

    for (int j = 0; j < string_vec.size(); j++) {
        for (int k = 0; k < string_vec.size(); k++) {
            if (string_vec[j] == string_vec[k] and j != k) {
                string_vec.erase(string_vec.begin() + j);
            }
        }
    }
}

void print_usage()
{
    string usage = "Usage: string-permute STRING [OPTIONS]"
        "\nOptions:\n"
        "\t--no-duplicates/-n\tRemove duplicate permutations."
        "\nExamples:"
        "\n\tstring-permute hee\n"
        "\t> Possible permutations:\n"
        "\t> ehe\n"
        "\t> eeh\n"
        "\t> eeh\n"
        "\t> hee\n"
        "\t> ehe\n"
        "\t> hee\n"
        "\n\tstring-permute hee --no-duplicates\n"
        "\t> Possible permutations:\n"
        "\t> eeh\n"
        "\t> ehe\n"
        "\t> hee";

    cout << usage << endl;
}
