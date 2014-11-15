#include <iostream> // For `<<`
#include <fstream> // For `ifstream`
#include <cstdlib> // For `exit`
using namespace std;

int main(int argc, char **argv)
{
    if (!argv[1]) {
        cout << "Error: Please input a filename." << endl;
        exit(1);
    }

    ifstream file;
    string line;
    int c = 0;

    file.open(argv[1]);

    if (file.is_open()) {
        while (getline(file, line)) {
            c++;
        }
        file.close();
    } else {
        cout << "Error: Could not open file." << endl;
        exit(2);
    }

    cout << "Number of lines: " << c << endl;

    return 0;
}
