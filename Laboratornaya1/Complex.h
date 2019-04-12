#pragma once
class Complex
{
	float re;
	float im;
public:
	Complex();
	Complex(float x,float y);
	~Complex();
	Complex operator+(Complex B);
	Complex operator*(Complex B);
	Complex operator-(Complex B);
	Complex operator/(Complex B);
	Complex operator/(double B);
	Complex operator*(float B);
	float Re();
	float Re(float x) { re = x; };
	float Im();
	int OutD();
	
};

