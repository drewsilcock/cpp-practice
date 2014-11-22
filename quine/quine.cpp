#include <iostream> // <<
using namespace std;

int main(int argc, char **argv)
{
    char quote = 34; // Ascii code for double quote
    string code[] = { // Array containing the code minus itself
        "    ",
        "#include <iostream> // <<",
        "using namespace std;",
        "",
        "int main(int argc, char **argv)",
        "{",
        "    char quote = 34; // Ascii code for double quote",
        "    string code[] = { // Array containing the code minus itself",
        "    };",
        "    ",
        "    string tab = code[0] // For printing indentation",
        "    ",
        "    for (int i = 1; i <= 7; i++) {",
        "        cout << code[i] << endl;",
        "        // Print out until the code string",
        "    }",
        "    ",
        "    for (int i = 0; i <= 25; i++) {",
        "        cout << tab + quote + code[i] + quote + ',' << endl;",
        "        // Print out the code string itself",
        "    }",
        "    ",
        "    for (int i = 8; i <= 25; i++) {",
        "        cout << code[i] << endl;",
        "        // Print out the remaining lines of code",
        "    }",
        "    ",
        "    return 0;",
        "}"
    };

    string tab = code[0]; // For printing indentation

    for (int i = 1; i <= 7; i++) {
        cout << code[i] << endl;
        // Print out until the code string
    }

    for (int i = 0; i <= 28; i++) {
        cout << tab + quote + code[i] + quote + ',' << endl;
        // Print out the code string itself
    }

    for (int i = 8; i <= 28; i++) {
        cout << code[i] << endl;
        // Print out the remaining lines of code
    }

    return 0;
}
