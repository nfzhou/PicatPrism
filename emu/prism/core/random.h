#ifndef RANDOM_H
#define RANDOM_H

#include <stddef.h>

/*--------------------------------------------------------------------*/

int    random_int(int);
double random_float(void);
double random_gaussian(double, double);

/*--------------------------------------------------------------------*/

double sample_gamma(double, double);
void   sample_dirichlet(double *, int, double *);

#endif /* RANDOM_H */
