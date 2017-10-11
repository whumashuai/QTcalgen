#ifndef GLOBAL_H
#define GLOBAL_H
#include"QString"
#include"stdafx.h"
#include"fraction.h"
#include<list>
#include<deque>
#include<string>
using namespace std;

class global
{
public:
    global();
    static int globaldata;//global variable
    static QString qs;//global variable
};

#endif // GLOBAL_H
