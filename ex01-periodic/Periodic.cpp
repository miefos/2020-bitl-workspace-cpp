//
// Created by Admin on 04.09.2020.
//
#include <string>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
#include "Periodic.h"

using namespace ds_course;
using namespace std;

Periodic::Periodic() {} // empty constructor

// function to find and replace all substr occurrence in a string
void findAndReplaceAll(std::string& data, std::string toSearch, std::string replaceStr)
{
    size_t pos = data.find(toSearch);
    while( pos != std::string::npos) {
        data.replace(pos, toSearch.size(), replaceStr);
        pos =data.find(toSearch, pos + replaceStr.size());
    }
}

int findRepeating(string str) {
    string str_in_lower;
    int i=0;
    char c;
    while (str[i])
    {
        c=str[i];
        str_in_lower += tolower(c);
        i++;
    }

    str = str_in_lower;

    // String less than 2 symbols
    if (str.size() < 2) {
        return 0;
    }

    // main algorithm
    string period;
    for (int i = 0; i < str.size() / 2; i++) {
        period += str[i];

        string str_without_substr = str;
        findAndReplaceAll(str_without_substr, period, "");


        if (str_without_substr.empty()) {
            return period.size();
        }
    }

    return 0;
}

// string
int Periodic::findPeriod(std::string str) {
    return findRepeating(std::move(str)); // Should work.
}

// decimal (integer)
int Periodic::findPeriod(int n) {
    return findRepeating(to_string(n)); // Should work.
}


// hexadecimal
int Periodic::findPeriodHex(int n) { // treat argument as a Hex number
//    return findRepeating(to_string(n));
    return 0; // NOT WORKING!
}
