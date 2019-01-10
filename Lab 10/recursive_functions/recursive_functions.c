/* SYSC 2006 Winter 2018 Lab 10. */

#include <stdio.h>
#include <math.h>

/* Return x raised to the power n for n >= 0. */
double power(double x, int n)
{
	if (n == 0)
	{
		return 1;
	}
	double result = x * power(x, n-1);

    return result;
}

/* Return the number of digits in integer n, n >= 0. */
int num_digits(int n)
{
	if (n < 10)
	{
    	return 1;
	}
	int result =  1 + num_digits(n/10);
	return result;
}

/* Return the count of the number of times target occurs in the first 
 * n elements of array a.
 */   
int occurrences(int a[], int n, int target)
{
     if (n < 0)
	{
		 return 0; 
	}
   return occurrences(a + 1, n - 1, target) + ((a[0] == target));
}

/* Challenge exercise: return x raised to the power n for n >= 0. */
double power2(double x, int n)
{
     if (n <= 0)
	{
		return 1; 
	}
   	if (n % 2 == 0)
	{
      double temp2 = power2(x, n/2);
      return temp2*temp2;
	}
   return x * power2(x, n - 1);
}
