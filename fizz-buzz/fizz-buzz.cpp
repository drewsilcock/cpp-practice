#include <iostream> // For `<<`
#include <fstream> // For `fstream`
#include <cstdlib> // For `exit`
#include <vector> // For `vector`
using namespace std;

#define FIZZ "F"
#define BUZZ "B"
#define FIZZBUZZ "FB"

vector<string> split(string, char);

int main(int argc, char** argv)
{
    if (!argv[1]) {
        cout << "Error: Please input a filename." << endl;
        exit(1);
    }

    ifstream inputfile;
    string file_contents;

    inputfile.open(argv[1]);

    if (inputfile.is_open()) {
        getline(inputfile, file_contents); // Only has one line
    } else {
        cout << "Error: Could not open file." << endl;
    }

    vector<int> nums(3);
    vector<string> num_strings;

    num_strings = split(file_contents, ' ');

    for (int i = 0; i < 3; i++) {
        nums[i] = atoi(num_strings[i].c_str());
    }

    int fizz_num = nums[0];
    int buzz_num = nums[1];
    int upper_limit = nums[2];

    for (int i = 1; i <= upper_limit; i++) {
        if (!(i % fizz_num) and !(i % buzz_num)) {
            cout << FIZZBUZZ << ' ';
        } else if (!(i % fizz_num)) {
            cout << FIZZ << ' ';
        } else if (!(i % buzz_num)) {
            cout << BUZZ << ' ';
        } else {
            cout << i << ' ';
        }
    }

    cout << endl;

    return 0;
}

vector<string> split(string contents, char delim)
{
    int num_delims = 0;
    for (int i = 0; i < contents.length(); i++) {
        if (contents[i] == delim) {
            num_delims++;
        }
    }

    vector<string> tokens(num_delims + 1);

    int j = 0;
    int pos = 0;
    for (int i = 0; i < contents.length(); i++) {
        if (contents[i] == delim) {
            tokens[j] = contents.substr(pos, i - pos);
            j++;
            pos = i + 1;
        }
    }

    tokens[j] = contents.substr(pos, contents.length() - pos);

    return tokens;
}
