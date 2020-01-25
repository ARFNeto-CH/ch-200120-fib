#include "stdio.h"
#include "stdlib.h"

#define _LIMITE_ (15)
unsigned long long int non_fib_n(unsigned long long int);

int main(int argc, char** argv)
{
	unsigned long long int v;
	for (unsigned long long int target = 0; target <= _LIMITE_; target += 1)
	{
		printf("Buscando por non_Fib(%llu): ", target);
		v = non_fib_n(target);
		printf("%llu\n", v);
	};	// for()

};	// end main()

//
// retorna 0 se passou dos limites, ou o N-esimo inteiro
// nap-Fibonacci
//
unsigned long long int non_fib_n(unsigned long long int target)
{
	unsigned long long int		non_fib_count = 0, fib_count = 0;
	unsigned long long int		prev_prev_fib = 0, prev_fib = 1, next_fib = 0;
	unsigned long long int		next_non_fib = 0;
	unsigned long long int		limit = 0x7fffffffffffffff; // para 8 bytes
	unsigned long long int		i = 0;
	while (limit > prev_prev_fib)
	{	// segue em frente ate atingir o limite do teste
		if (i == next_fib)
		{	next_fib = prev_fib + prev_prev_fib;
			prev_prev_fib = prev_fib;
			prev_fib = next_fib;
			fib_count += 1;
		}
		else
		{	next_non_fib = i;
			non_fib_count += 1;
		};	// if()
		if (non_fib_count == target) return next_non_fib; // achou!
		i = i + 1;
	};	// while()
	return 0;
};	// non_fib_n()
