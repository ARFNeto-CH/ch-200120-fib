#include "stdio.h"
#include "stdlib.h"

void	usage();

int main(int argc, char** argv)
{
	unsigned long long int		non_fib_count = 0;
	unsigned long long int		fib_count = 0;
	unsigned long long int      target = 0;
	unsigned long long int		prev_prev_fib = 0;
	unsigned long long int		prev_fib = 1;
	unsigned long long int		next_fib = 0;
	unsigned long long int		next_non_fib = 0;

	// 8 bytes. Fim da linha para Fibonacci on long long int
	//unsigned long long int		limit = 233;
	unsigned long long int		limit = 0x7fffffffffffffff;

	if (argc < 2) usage(); // se nao veio o N mostra mensagem e encerra
	target = atoll(argv[1]);

	printf("short int: %d bytes\n", sizeof(short int));
	printf("int: %d bytes\n", sizeof(int));
	printf("long int: %d bytes\n", sizeof(long int));
	printf("long long int: %d bytes\n", sizeof(long long int));

	printf("limite da sequencia de Fibonacci para long long int: %lld\n", 0x7fffffffffffffff );
	printf("limite da sequencia de Fibonacci  para  esse  teste: %lld\n\n", limit);

	printf("Buscando por non_Fib(%lld)\n", target);

	unsigned long long int		i = 0;
	while (limit > prev_prev_fib)
	{	// segue em frente ate encontrar o N-esimo ou atingir 
		// o limite do teste
		if (i == next_fib)
		{
			next_fib = prev_fib + prev_prev_fib;
			prev_prev_fib = prev_fib;
			prev_fib = next_fib;
			fib_count += 1;
		}
		else
		{
			next_non_fib = i;
			non_fib_count += 1;
		};	// if()
		if (non_fib_count == target)
		{
			printf("non-Fibonacci(%lld) = %lld\n",
				target, next_non_fib);
			exit(0);
		};	// if()
		i = i + 1;
	};	// while()
	printf("\n\nAtingiu o limite para a busca...\n");
	printf("Ultimo nao-Fibonacci encontrado: %lld. Posicao na sequencia: %lld\n",
		next_non_fib, non_fib_count);
	printf("Ultimo Fibonacci: %lld\n", prev_prev_fib);

}	// end main()


	//
	// Uso: non_Fib_n N
	//
	//    que retorna o N-esimo inteiro non-Fibonacci a partir de zero
    //
	//    Fibonacci: 0 1 2 3 5 8 13 21 34 55 89 144 233 ...
	//    non-Fibonacci: 4 6 7 9 10 11 1 14 15 16 17 ...
	//
	// Ex: non_Fib_n 6 retorna entao 11
	//
void usage()
{
	printf("\n\n  Uso: non_Fib_n N\n\n");
	printf("        que retorna o N-esimo inteiro non-Fibonacci a partir de zero\n\n");
	printf("        Fibonacci: 0 1 2 3 5 8 13 21 34 55 89 144 233 ...\n");
	printf("        non-Fibonacci: 4 6 7 9 10 11 1 14 15 16 17 ...\n\n");
	printf("  Ex: non_Fib_n 6 retorna entao 11\n\n\n");
	exit(0);
}