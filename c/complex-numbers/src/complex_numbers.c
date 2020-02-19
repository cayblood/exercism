#include "complex_numbers.h"

complex_t c_add(complex_t a, complex_t b)
{
    complex_t to_return;

    to_return.real = a.real + b.real;
    to_return.imag = a.imag + b.imag;

    return to_return;
}

complex_t c_sub(complex_t a, complex_t b)
{
    complex_t to_return;

    to_return.real = a.real - b.real;
    to_return.imag = a.imag - b.imag;

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
    complex_t conjugate, to_return;
    double iterms, isquared, denominator;

    conjugate = c_conjugate(b);
    to_return.real = a.real * conjugate.real;
    iterms = (a.real * conjugate.imag) + (a.imag * conjugate.real);
    isquared = a.imag * conjugate.imag * -1.0;
    to_return.real += isquared;

    denominator = (b.real * conjugate.real) + (b.imag * conjugate.imag * -1.0);
    to_return.real /= denominator;
    to_return.imag = iterms / denominator;

    return to_return;
}

double c_abs(complex_t x)
{
    double to_return = 0.0;
    if (x.real != 0.0 && x.imag == 0.0) {
        to_return = x.real < 0 ? x.real * -1.0 : x.real;
    }
    if (x.real == 0.0 && x.imag != 0.0) {
        to_return = x.imag < 0 ? x.imag * -1.0 : x.imag;
    }
    if (x.real != 0.0 && x.imag != 0.0) {
        to_return = sqrt((x.real * x.real) + (x.imag * x.imag));
    }
    return to_return;
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
    complex_t to_return;
    return to_return;
}
