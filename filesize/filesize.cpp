#include <iostream> // For `<<`
#include <fstream> // For `ifstream`
#include <cstdlib> // For `exit`
using namespace std;

void print_usage();

int main(int argc, char **argv)
{
    if (!argv[1]) {
        print_usage();
        exit(2);
    }

    ifstream file;
    string contents;
    string line;

    file.open(argv[1]);

    if (file.is_open()) {
        while(getline(file, line)) {
            contents += line;
            contents.push_back('\n');
        }
        file.close();
    } else {
        cout << "Error: Could not open file." << endl;
        print_usage();
        exit(1);
    }

    cout << "Size of file: " << contents.size() << " bytes" << endl;

    return 0;
}

void print_usage()
{
    cout << "Usage: filesize FILE" << endl;
}
