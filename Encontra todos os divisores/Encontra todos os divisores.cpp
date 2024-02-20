// Encontra todos os divisores.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <omp.h>
#include <conio.h>

int main()
{
    unsigned long long int num = 1000000010;
    unsigned long long int resto, somador = 0;
    double inicio, fim;
    inicio = omp_get_wtime();
    #pragma omp parallel num_threads(1)
    {
        #pragma omp for reduction (+: somador)
            for (signed int i = 1; i <= num; i++)
            {
                resto = num % i;
                if (resto == 0) somador += i;
            }
    }
    fim = omp_get_wtime();
    double tempo_total = fim - inicio;
    printf("%llu\n", somador);
    printf("Tempo: %.2lf\n", tempo_total);
    char op = _getch();
}
