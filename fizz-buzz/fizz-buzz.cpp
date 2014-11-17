#include <iostream> // For `<<`
#include <fstream> // For `fstream`
#include <cstdlib> // For `exit`
#include <vector> // For `vector`
using namespace std;

#define FIZZ 'F'
#define BUZZ 'B'
#define FIZZBUZZ "FB"

vector<int> parse(string);

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
    nums = parse(file_contents);

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

vector<int> parse(string contents)
{
    char delim = ' ';
    int delim_locs[2] = {0, 0}; // Should only be 2 spaces
    vector<int> nums(3);
    int k = 0;

    for (int i = 0; i < contents.length(); i++) {
        if (contents[i] == delim) {
            delim_locs[k] = i;
            k++;
        }
    }

    nums[0] = stoi(contents.substr(0, delim_locs[0]));
    nums[1] = stoi(contents.substr(delim_locs[0] + 1,
                                   delim_locs[1] - delim_locs[0]));
    nums[2] = stoi(contents.substr(delim_locs[1] + 1,
                                   delim_locs[2] - delim_locs[1]));

    return nums;
}
