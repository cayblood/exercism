#include "complex_numbers.h"

complex_t c_add(complex_t a, complex_t b)
{
    complex_t to_return;
    return to_return;
}

complex_t c_sub(complex_t a, complex_t b)
{
    complex_t to_return;
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
    complex_t to_return;
    return to_return;
}

double c_abs(complex_t x)
{
    double to_return = 0.0;
    return to_return;
}

complex_t c_conjugate(complex_t x)
{
    complex_t to_return;
    return to_return;
}

double c_real(complex_t x)
{
    double to_return = 0.0;
    return to_return;
}

double c_imag(complex_t x)
{
    double to_return = 0.0;
    return to_return;
}

complex_t c_exp(complex_t x)
{
    complex_t to_return;
    return to_return;
}
