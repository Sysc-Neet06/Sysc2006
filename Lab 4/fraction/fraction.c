/* fraction.c - SYSC 2006 Winter 2018 Lab 4 */

#include <stdlib.h>  // abs(x)
#include <stdio.h>   // printf

#include "fraction.h"

/* Print fraction f in the form a/b. */
void print_fraction(fraction_t f)
{
	printf("%d/%d", f.num, f.den);
}

/* Return the greatest common divisor of integers a and b; 
   i.e., return the largest positive integer that evenly divides 
   both values.
*/
int gcd(int a, int b)
{
	/* Euclid's algorithm, using iteration and calculation of remainders. */

	int temp;
	temp = abs(a);
	a = abs(b);
	b = temp % a;

	while (b != 0)
	{
		temp = a;
		a = b;
		b = temp % a;}

	return a;
}


/* Return the reduced form of fraction f.

   This means that:
   (1) if the numerator is equal to 0 the denominator is always 1.
   (2) if the numerator is not equal to 0 the denominator is always
       positive, and the numerator and denominator have no common
       divisors other than 1.

   In other words,
   (1) if the numerator is 0 the denominator is always changed to 1.
   (2) if the numerator and denominator are both negative, both values
       are made positive, or if the numerator is positive and the 
       denominator is negative, the numerator is made negative and the 
       denominator is made positive.
   (3) the numerator and denominator are both divided by their greatest
       common divisor. 
*/
fraction_t reduce(fraction_t f)
{ 
	
	if(f.num==0)
	{
		f.den=1;
	}
	if(f.den==0)
	{
		f.num=1;
	}
	if(f.num<0 && f.den<0)
		{
			f.num=abs(f.num);
			f.den=abs(f.den);
		}
	if(f.den>0 && f.num<0)
	{
		f.den=-1*f.den;
		f.num=-1*f.num;
	}
	if(f.den<0 && f.num>0)
	{
		f.den=-1*f.den;
		f.num=-1*f.num;
	}
	int w;
	w=gcd(f.num,f.den);
	f.num=f.num/w;
	f.den=f.den/w;
    return f;
}

/* Return a fraction with numerator a and denominator b.
   Print an error message and terminate the calling program via exit()
   if the denominator is 0.
   The fraction returned by this function is always in reduced form
   (see documentation for reduce).
*/
fraction_t make_fraction(int a, int b)
{
	fraction_t f;
    f.num = 0;
    f.den = 0;
	 if(b==0)
	{
		exit(0);
	}
	else
	{
		f.num=a;
		f.den=b;
	}

	return reduce (f);
}

/* Return the sum of fractions f1 and f2.
   The fraction returned by this function is always in reduced form
   (see documentation for reduce).
 */
fraction_t add_fractions(fraction_t f1, fraction_t f2)
{
	fraction_t f;
	f.den = (f1.den * f2.den);
	f.num   = (f1.num * f2.den) + (f2.num * f1.den);
	return reduce(f);
}

/* Return the product of fractions f1 and f2.
   The fraction returned by this function is always in reduced form
   (see documentation for reduce).
 */
fraction_t multiply_fractions(fraction_t f1, fraction_t f2)
{
	fraction_t f;
	f.num = (f1.num * f2.num);
	f.den = (f1.den * f2.den); 	
	return reduce(f);
}

