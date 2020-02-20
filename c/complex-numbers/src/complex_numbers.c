#include "complex_numbers.h"

complex_t c_add(complex_t a, complex_t b)
{
    complex_t to_return = { a.real + b.real, a.imag + b.imag };
    return to_return;
}

complex_t c_sub(complex_t a, complex_t b)
{
    complex_t to_return = { a.real - b.real, a.imag - b.imag };
    return to_return;
}

complex_t c_mul(complex_t a, complex_t b)
{
    complex_t to_return;

    to_return.real = (a.real * b.real) - (a.imag * b.imag);
    to_return.imag = (a.real * b.imag) + (a.imag * b.real);

    return to_return;
}

complex_t c_div(complex_t a, complex_t b)
{
    complex_t conjugate, numerator, denominator, to_return;

    conjugate = c_conjugate(b);
    numerator = c_mul(a, conjugate);
    denominator = c_mul(b, conjugate);
    to_return.real = numerator.real / denominator.real;
    to_return.imag = numerator.imag / denominator.real;
    return to_return;
}

double c_abs(complex_t x)
{
    return sqrt((x.real * x.real) + (x.imag * x.imag));
}

complex_t c_conjugate(complex_t x)
{
    complex_t to_return;
    to_return.real = x.real;
    to_return.imag = x.imag * -1.0;
    return to_return;
}

double c_real(complex_t x)
{
    return x.real;
}

double c_imag(complex_t x)
{
    return x.imag;
}

complex_t c_exp(complex_t x)
{
    complex_t a = { exp(x.real), 0 };
    complex_t b = { cos(x.imag), sin(x.imag) };
    return c_mul(a, b);
}
