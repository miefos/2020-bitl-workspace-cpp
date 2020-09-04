//
// Created by Admin on 04.09.2020.
//

#ifndef BITL_WORKSPACE_CPP_PERIODIC_H
#define BITL_WORKSPACE_CPP_PERIODIC_H


namespace ds_course
{
    class Periodic
    {
    public:
        Periodic(); // empty constructor
        int findPeriod(std::string str);
        int findPeriod(int n);
        int findPeriodHex(int n); // treat argument as a Hex number
    };
}


#endif //BITL_WORKSPACE_CPP_PERIODIC_H
