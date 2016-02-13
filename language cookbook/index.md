---
layout: page 
title: Lanaguage cookbook
text: Quick reference for implementations in different programming languages
---


## Compute the nth root (Newton's method) 

~~~ cpp
#include <cmath>
double nth_root(double A, int nth) {
	double x = A, dx = 10;
	while (fabs(dx) > 0.01) {
		dx = (A/pow(x, nth-1) - x)/nth;
		x = x + dx;
	}
	return x;
}

int nth_root_to_closest_integer(double A, int nth) {
	return (nth_root(A, nth)+0.5+10E-6);
}
~~~

~~~ python
def nth_root(A, n):
    x = A;
    while True:
        dx = (1/n) * (A/(x ** (n-1)) - x);
        if abs(dx) < 0.01:
            break;
        x = x + dx;
    return x;

for i in range(1, 100):
    nth = 3;
    print('nth_root(', i, ',', nth, ') = ', nth_root(i, nth));
~~~

#### Reference
* [nth root algorithm](https://en.wikipedia.org/wiki/Nth_root_algorithm)

## Fill multi-dimensional array with constants

~~~ cpp
#include <algorithm>

int computed[100][100];

std::fill(&computed[0][0], &computed[0][0]+sizeof(computed)/sizeof(computed[0][0]), -1);
~~~ 
