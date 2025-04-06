// 6

#include <iostream>
#include <cmath>

int factorial(int n)
{
    if (n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}

double powerX(double x)
{
    return -x * x;
}

double eulerExpFnc(double (*f)(double), double x, int acc)
{
    double epsilon = pow(10, -acc);
    int step = 0;
    double value = 0;
    double term = 1;

    do
    {
        value += term;
        step++;
        term = term * f(x) / step;

        if (fabs(term) < epsilon)
        {
            break;
        }
    } while (true);

    return value;
}

double intergrator(int n, double boarderA, double borderB, double (*f)(double (*f)(double), double, int), int acc)
{
    double step = (borderB - boarderA) / n;
    double integral = 0;
    for (int i = 0; i < n; i++)
    {
        double x1 = boarderA + i * step;
        double x2 = boarderA + (i + 1) * step;
        integral += (x2 - x1) / 6.0 * (f(powerX, x1, acc) + 4.0 * f(powerX, 0.5 * (x1 + x2), acc) + f(powerX, x2, acc));
    }
    return integral;
}

int main()
{
    std::cout << intergrator(10, 0, 1, eulerExpFnc, 7);
    return 0;
}

// пруфъ https://imgur.com/RyW8gKD верности