/* SYSC 2006 Fall 2017 Lab 3. 

 * Incomplete implementations of the functions that will be coded during the lab.
 */

#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "exercises.h"

/* Exercise 1. */

/* Return the average magnitude of the n doubles in x[]. 
 * This function assumes that parameter n is >= 1.
 */
double avg_magnitude(double x[], double n)
{	
	int i;
	double sum = 0;
	double avg;

	for(i = 0 ; i < n ; ++i){
		if (x[i] < 0){
			x[i] = fabs(x[i]);
		}
		sum = sum + x[i];
	}
	avg = sum / n;

    return avg;
}

/* Exercise 2. */

/* Return the average power of the n doubles in x[].
 * This function assumes that parameter n is >= 1.
 */
double avg_power(double x[], double n)
{
	int i;
	double sum = 0;
	double avgPower;

	for(i = 0 ; i < n ; ++i){	
		sum = sum + pow(x[i],2);
	}
	avgPower = sum / n;

    return avgPower;
}

/* Exercise 3. */

/* Return the largest of the n doubles in arr[]. 
 * This function assumes that parameter n is >= 1.
 */
double max(double arr[], int n)
{
	int i;
	double max = arr[0];

	for(i = 1 ; i < n ; ++i){
		if(arr[i] > max){
			max = arr[i];
		}
	}
    return max;
}

/* Exercise 4. */

/* Return the smallest of the n doubles in arr[]. 
 * This function assumes that parameter n is >= 1.
 */
double min(double arr[], int n)
{
	int i;
	double min = arr[0];

	for(i = 1 ; i < n ; ++i){
		if(arr[i] < min){
			min = arr[i];
		}
	}
    return min;
}

/* Exercise 5. */

/* Normalize the n doubles in x[]. 
 * This function assumes that parameter n is >= 2, and that at least
 * two of the values in x[] are different.
 */
void normalize(double x[], int n)
{
	int i;
	double maxVal;
	double minVal;
	

	maxVal = max(x,n);
	minVal = min(x,n);
	
	for(i = 0 ; i < n ; ++i){
		x[i] = (x[i] - minVal)/(maxVal - minVal);
	}
	

}
