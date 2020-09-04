#include <iostream>
#include <string>
#include <sstream>
#include "Periodic.h"

using namespace std;
using namespace ds_course;


int main()
{
    Periodic periodic;
    string mode;
    cin >> mode;
    string inputString;
    int inputDec;
    int inputHex;
    string inputLine;

    mode = "str";

    cin.ignore(10000,'\n');

//    string inputLine;
    while (getline(cin, inputLine)) {

        cout << inputLine << endl;

        stringstream sstr(inputLine);

        if (sstr.peek() == '#') {
            continue;

        // main procedure
        } else {

            // decimal (integer)
            if (mode == "dec") {
                sstr >> inputDec;
                int res = periodic.findPeriod(inputDec);
                cout << inputDec << " " << res << endl;

            // string
            } else if (mode == "str") {
                sstr >> inputString;
                int res = periodic.findPeriod(inputString);
                cout << inputString << " " << res << endl;

            // hexadecimal
            } else if (mode == "hex") {
                sstr >> inputHex;
                int res = periodic.findPeriodHex(inputHex);
                cout << inputHex << " " << res << endl;

            // invalid mode
            } else {
                cout << "Invalid mode." << endl;
            }
        }
    }
}



