/*
  "Planteo con arreglo de registros"
  autor: Miguel Iglesias
  version: 0.1
  bugs conocidos:
    1. no permite ingresar espacios.
  nota: solo se probo en linux, para win2 seguro hay que agregar conio.h y tocar algo mas.

  compilar:
    $ gcc -o arreglo_registo arreglo_registo.c
  ejecutar:
    $ ./arreglo_registo
*/

#include <stdio.h>

#define N 7  // numero de sucursales (para hacer pruebas poner en 2 o 3).

typedef struct sucursal
{
    char nombre[30];
    int inauguracion;
    float ventas_mes[12];
    int stock_inicial;
    int stock_final;
    int codprovincia;
    float promedio_anual;
}sucursal;

int main(void)
{
    float prom_todas = 0; // promedio anual etre todas las sucursales
    float ventas;
    char meses[12][15] = {"enero","febrero","marzo","abril","mayo","junio","julio","agosto","septiembre","octubre","noviembre","diciembre"};
    char provincia[N][15];
    sucursal suc[N];   // aca se crea el arreglo de tipo registro sucursal.
    float max_mes[12];
    // inicializamos vector con los maximos de ingresos por mes en cero.
    for(int i=0;i<12;i++)
    {
        max_mes[i] = 0;
    }

    for (int i=0;i<N;i++)
    {
        printf("Ingrese el nombre de la provincia: ");
        scanf("%s", provincia[i]);
    }
    printf("\e[1;1H\e[2J"); // limpia la consola

    for (int i=0;i<N;i++)
    {
        ventas = 0;
        printf("Nombre sucursal: ");
        scanf("%s", suc[i].nombre);
        printf("Año apertura: ");
        scanf("%d", &suc[i].inauguracion);
        for (int j=0; j<12;j++)
        {
            printf("Ventas %s: ", meses[j]);
            scanf("%f", &suc[i].ventas_mes[j]);
            ventas = ventas + suc[i].ventas_mes[j];

            // Se actualiza el vector con las ventas maximas por mes (util para el punto b).
            if(suc[i].ventas_mes[j] > max_mes[j])
            {
                max_mes[j] = suc[i].ventas_mes[j];
            }
        }
        suc[i].promedio_anual = ventas / 12;
        printf("Stock inicial: ");
        scanf("%d", &suc[i].stock_inicial);
        printf("Stock final: ");
        scanf("%d", &suc[i].stock_final);
        printf("Codigo provincia [0-%d]:  ", N-1);  // muestra los codigos de provincia validos
        scanf("%d", &suc[i].codprovincia);

    printf("\e[1;1H\e[2J"); // limpia la consola
    }

    // Calculo del promedio anual de ventas entre todas las sucursales.
    for(int i=0;i<N;i++)
    {
        prom_todas = prom_todas + suc[i].promedio_anual;
    }
    prom_todas = prom_todas / N;


    // Resolucion del punto "a"
    for(int i=0;i<N;i++)
    {
        int meses_sin_ventas = 0;
        if(suc[i].promedio_anual > prom_todas)
        {

            printf("Promedio anual mayor en provincia: %s, sucursal %s\n", provincia[suc[i].codprovincia], suc[i].nombre);
            for(int k=0;k<12;k++)
            {
                if(suc[i].ventas_mes[k] == 0)
                {
                    meses_sin_ventas +=1;
                }
            }
            //printf("\Sucursal: %s\n", suc[i].nombre);
            printf("\tMeses sin ventas: %d\n", meses_sin_ventas);
        }

    }

    printf("\n");

    // Calculo del punto "b"
    for(int i=0;i<N;i++)
    {
        if((suc[i].stock_inicial - suc[i].stock_final) > (suc[i].stock_inicial * 0.4))
        {
            printf("La sucursal %s, fundada en %d vendio más del 40 porciento de su stock\n", suc[i].nombre, suc[i].inauguracion);
            for(int j=0;j<12;j++)
            {
                if( (max_mes[j] != 0) & (suc[i].ventas_mes[j] == max_mes[j]))
                {
                    printf("\t En %s registro ingresos record\n", meses[j]);
                }
            }
        }
        printf("\n");
    }

    return 0;
}



