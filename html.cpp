#include "html.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Validator::Validator() {}

bool Validator::validate(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Error with opening file: " << filename << endl;
        return false;
    }

    string line;
    int line_num = 0;
    int count = 0;

    while (getline(file, line))
    {
        line_num++;

        string::size_type pos = 0;
        while ((pos = line.find('<', pos)) != string::npos)
        {
            string::size_type pos_end = line.find('>', pos);
            if (pos_end == string::npos)
            {
                cout << "Error with validation in line" << line_num << endl;
                return false;
            }

            string tag = line.substr(pos, pos_end - pos + 1);
            if (tag.size() > 2 && tag[1] == '/')
            {
                count--;
                if (count < 0)
                {
                    cout << "Error with validation in line " << line_num << ": Incorrect closing tag" << tag << endl;
                    return false;
                }
            }
            else
            {
                count++;
            }

            pos = pos_end + 1;
        }
    }

    if (count > 0)
    {
        cout << "Error with validation" << endl;
        return false;
    }

    cout << "File" << filename << " is valid" << endl;
    return true;
}
