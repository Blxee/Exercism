#include "complex_numbers.h"

complex_t c_add(complex_t a, complex_t b)
{
	complex_t result;

	result.real = a.real + b.real;
	result.imag = a.imag + b.imag;
	return (result);
}

complex_t c_sub(complex_t a, complex_t b)
{
	complex_t result;

	result.real = a.real - b.real;
	result.imag = a.imag - b.imag;
	return (result);
}

complex_t c_mul(complex_t a, complex_t b)
{
	complex_t result;

	result.real = a.real * b.real - a.imag * b.imag;
	result.imag = a.real * b.imag + a.imag * b.real;
	return (result);
}

complex_t c_div(complex_t a, complex_t b)
{
	complex_t result;

	(void)a;
	(void)b;
	result.real = (a.real * b.real + a.imag * b.imag) / (pow(b.real, 2) + pow(b.imag, 2));
	result.imag = (a.imag * b.real - a.real * b.imag) / (pow(b.real, 2) + pow(b.imag, 2));
	return (result);
}

double c_abs(complex_t x)
{
	return (sqrt(pow(x.real, 2) + pow(x.imag, 2)));
}

complex_t c_conjugate(complex_t x)
{
	complex_t result = x;

	result.imag *= -1;
	return (result);
}

double c_real(complex_t x)
{
	return (x.real);
}

double c_imag(complex_t x)
{
	return (x.imag);
}

complex_t c_exp(complex_t x)
{
	complex_t result;

	result.real = exp(x.real) * cos(x.imag);
	result.imag = exp(x.real) * sin(x.imag);
	return (result);
}
