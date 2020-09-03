#include <string>
#include <iostream>
#include <sstream>
#include "Palindromes.h"

using namespace ds_course;
using namespace std;

Palindromes::Palindromes() {

}

bool Palindromes::isPalindrome(int number)
{
    int *digits = new int[20];
    int count = 0;
    for (int i = 0;; i++) {
        digits[i] = number % 10;
        number = number / 10; 
        if (number == 0) {
            break;
        }
        count++;
    }
    //cout << "  count in isPalindrome(" << number << ") = " << count << endl;
    for (int j = 0; j < count; j++) {
        if (digits[j] != digits[count-j]) {
            return false;
        }
    }
    return true;
}


bool Palindromes::isPalindrome(std::string word) {
    int count = word.length();
    if (count == 0) {
        return true;
    }
    for (int j = 0; j < count; j++) {
        if (word.at(j) != word.at((count-1)-j)) {
            return false;
        }
    }
    return true;
}


