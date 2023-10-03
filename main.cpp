#include "html.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Validator validator;

    string filename;
    cout << "Enter the path to the file: ";
    cin >> filename;

    if (validator.validate(filename))
    {
        cout << "File is valid" << endl;
    }
    else
    {
        cout << "Error with the validation " << endl;
    }

    return 0;
}
