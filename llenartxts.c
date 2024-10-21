#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Usage(char *mess) {

    printf("\nUsage: %s n A B T\n", mess);
    printf("n = numero de txt's\n");
    printf("A = Tamaño inicial de A\n");
    printf("B = Tamaño inicial de B\n");
    printf("T = Tope de tamaño\n");
    printf("I = Incremento del tamaño x N \n\n");

}

int main(int argc, char **argv) {
    unsigned int tamanioA, tamanioB, i, j, n, tope, incremento, numero;
    char name[20];
    FILE *fptr;
    float E_cpu;
    long E_wall;
    time_t  ts, te;
    clock_t cs, ce;

    srand(time(NULL));

    if (argc == 6){
        sscanf(argv[1], "%d", &n); 
        sscanf(argv[2], "%d", &tamanioA); 
        sscanf(argv[3], "%d", &tamanioB);
        sscanf(argv[4], "%d", &tope);
        sscanf(argv[5], "%d", &incremento);
        
        for (i = 1; i <= n; i= i + 1)
        {
            sprintf(name, "datos%d.txt", i);
            ts = time(NULL);
            cs = clock();
            fptr = fopen(name, "w");
            if (fptr == NULL) {
                printf("Error al abrir el archivo.\n");
                return 1;
            }
            fprintf(fptr, "%d\n",tamanioA);
            fprintf(fptr, "%d\n",tamanioB);

            for (j = 0; j < tamanioA; j = j + 1) {
                numero = rand() % 10;
                fprintf(fptr, "%d\n", numero);
            }
            for (j = 0; j < tamanioB; j = j + 1) {
                numero = rand() % 10;
                fprintf(fptr, "%d\n", numero);
            
            }
            fclose(fptr);
            ce = clock();
            te = time(NULL);
            E_wall = (long) (te - ts);
            E_cpu = (float)(ce - cs) / CLOCKS_PER_SEC;
            printf("Archivo: %s, CPU Time: %f, Wall Time: %ld\n", name, E_cpu, E_wall)
            tamanioA = tamanioA + (100 * incremento );
            tamanioB = tamanioB + (100 * incremento );
            if (tamanioA > tope || tamanioB > tope){
                printf("Tamaño de tope superado\n");
                break;
            }
        }
        
        
    }else {
        Usage(argv[0]);
    }
    return 0;
}