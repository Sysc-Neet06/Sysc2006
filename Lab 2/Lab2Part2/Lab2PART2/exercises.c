/* SYSC 2006 Winter 2018 Lab 2, Part 2.
 *
 * Complete implementations of the functions that will be coded during the lab. 
 */

#include <stdlib.h>
#include <math.h>

#include "exercises.h"

/* Returns n! for n >= 0. (0! is defined to be 1.)
   Note that the return type is int, and n! grows rapidly as n increases,
   so this function should only be used for fairly small values of n; 
   i.e., if ints are implemented as 32-bit values, n must be <= 15.
*/
int factorial(int n)
{
	int i; //This is the count
	int	f=1; //This is the variable where value of factorial is stored

	i=1;
	while (i<=n)
	{
		f = f * i;
		i = i + 1;
	}

    return f;
}

/* Returns the number of different ordered subsets of k objects picked
   from a set of n objects, for n > 0, k > 0, n >= k.
 */
int ordered_subsets(int n, int k)
{
   int s; //it is the variable where value of number of subsets is stored

	//calling the factorial function to find the number of subsets
	s = factorial(n)/factorial(n-k); 

    return s;
}

/* Returns the binomial coefficient (n k); that is, the number of 
   combinations of k objects that can be chosen from a set of n objects, 
   for n > 0, k > 0, n >= k.
 */
int binomial(int n, int k)
{
    int b; //it is the variable where value of the binomial coefficient is stored

	//calling the factoral and ordered subsets function to find the binomial coefficient
	b = ordered_subsets(n,k)/factorial(k);

    return b;
}

/* Returns the cosine of x (measured in radians) by calculating
 * the first n terms of the infinite series expansion of cosine.
 */
double cosine(double x, int n)
{
    return -2.0;
}

