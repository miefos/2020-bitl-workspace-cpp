#ifndef INC_2020_BITL_WORKSPACE_CPP_RATIO_H
#define INC_2020_BITL_WORKSPACE_CPP_RATIO_H

#include <iostream>

namespace ds_course {
    class Ratio {
    private:
        int num;
        int den;
        int gcd(int a, int b);
    public:
        Ratio(int nn = 0, int dd = 1); // default 0/1 = 0
        Ratio operator+(Ratio rhs);
        Ratio operator-(Ratio rhs);
        Ratio operator*(Ratio rhs);
        Ratio operator/(Ratio rhs);
        bool operator<(Ratio rhs);
        bool operator>(Ratio rhs);
        bool operator==(Ratio rhs);

        friend std::ostream& operator<< (std::ostream& oStream, const Ratio rat) {
            oStream << "[" << rat.num << "/" << rat.den << "]";
            return oStream;
        }

        friend std::istream &operator>>(std::istream &input, ds_course::Ratio &rat)
        {
            input >> rat.num;
            input.ignore(256, '/'); // ignore slash
            input >> rat.den;

            // simplify fraction
            int g = rat.gcd(rat.num, rat.den);
            rat.num = rat.num/g;
            rat.den = rat.den/g;
            if (rat.den < 0) {
                rat.num = -rat.num;
                rat.den = -rat.den;
            }

            return input;
        }

    };
}

ds_course::Ratio::Ratio(int nn, int dd): num(nn), den(dd) {
    int g = gcd(nn, dd);
    num = num/g;
    den = den/g;
    if (den < 0) {
        num = -num;
        den = -den;
    }
}

int ds_course::Ratio::gcd(int a, int b) {
    if (a == 0)
        return b;
    return ds_course::Ratio::gcd(b % a, a);
}

// result of r1 + r2
ds_course::Ratio ds_course::Ratio::operator+(const ds_course::Ratio rhs) {
    int upside = num * rhs.den + den * rhs.num;
    int downside = den * rhs.den;
    ds_course::Ratio result(upside, downside);
    return result;
}

bool ds_course::Ratio::operator==(ds_course::Ratio rhs) {
    if (num == rhs.num && den == rhs.den)
        return true;

    return false;
}

bool ds_course::Ratio::operator>(ds_course::Ratio rhs) {
    return false;
}

bool ds_course::Ratio::operator<(ds_course::Ratio rhs) {
    return false;
}

ds_course::Ratio ds_course::Ratio::operator/(ds_course::Ratio rhs) {
    return ds_course::Ratio();
}

ds_course::Ratio ds_course::Ratio::operator*(ds_course::Ratio rhs) {
    return ds_course::Ratio();
}

ds_course::Ratio ds_course::Ratio::operator-(ds_course::Ratio rhs) {
    return ds_course::Ratio();
}

#endif //INC_2020_BITL_WORKSPACE_CPP_RATIO_H
