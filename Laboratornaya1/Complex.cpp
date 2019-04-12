
#include "Complex.h" 
#include <iostream>


using namespace std;


Complex::Complex()
{
	re = 0;
	im = 0;
}


Complex::~Complex()
{
}

Complex::Complex(float x, float y)
{
	re = x;
	im = y;
}


float Complex::Re()
{
	// TODO: Добавьте сюда код реализации.
	return 0.0f;
}

float Complex::Im()
{
	// TODO: Добавьте сюда код реализации.
	return 0.0f;
}

Complex Complex::operator+(Complex B)
{
	return Complex(re+B.re,im+B.im);
}



Complex Complex::operator*(Complex B)
{
	Complex Z;
	Z.re = (re*B.re) - (im*B.im);
	Z.im = (re*B.im) + (B.re*im);
	return Z;
}




int Complex::OutD()
{
	std::cout << re;
	if (im > 0) std::cout << "+";
	if (im!=0) std::cout << im << "i\n";
	return 0;
}

Complex Complex::operator-(Complex y)
{
	Complex z;
	z.re = re - y.re;
	z.im = im - y.im;
	return z;
}

Complex Complex::operator/(Complex y)//деление комплексного на комплексное
{
	Complex z;
	z.re = ((re*y.re) + (im*y.im)) / ((y.re*y.re) + (y.im*y.im));
	z.im = ((im*y.re) - (re*y.im)) / ((y.re*y.re) + (y.im*y.im));
	return z;
}

Complex Complex::operator/(double y)   //деление комплексного на вещественное
{
	Complex z;
	z.re = re / y;
	z.im = im / y;
	return z;
}

Complex Complex::operator*(float B) // умножение комплексного на float
{
	Complex Z;
	Z.re = re*B;
	Z.im = im*B;
	return Z;
}


