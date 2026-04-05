#pragma once
#ifndef FUNC_H
#define FUNC_H

class FuncInterface {
public:
    virtual ~FuncInterface() = default;
    virtual int add(int, int) = 0;
};

class Func : public FuncInterface {
public:
    int add(int a, int b);
};

#endif





