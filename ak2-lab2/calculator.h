#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator
{
    public:
        int Add (double, double);
        int Sub (double, double);
        int Mul (double, double);

        template<typename T>
        T Increment(T&& data);
};

#endif//CALCULATOR_H
