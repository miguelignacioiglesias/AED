/*
 Enunciado:
  Una empresa desea calcular el sueldo de un empleado e imprimir su recibo detallando:
  Nombre y Apellido, Sueldo Básico, Premio, Comida, Viáticos, Ausentes, Obra social (3%),
  Ley 19032 (3%), y Jubilación (11%).
  Por los ausentes, se descuenta un monto fijo por día de ausencia. Los
  porcentajes se calculan sobre los montos remunerativos. Viáticos, premios y
  comida no se consideran remunerativos.
*/

#include <stdio.h>

const float Ley = 0.3;
const float Os = 0.3;
const float Jub = 0.11;
const int Laborables = 22;

int main(int argc, char **argv[])
{
	char nombre[25];
	float sbasico = 0;
	float premio = 0;
	int ausentes = 0;
	float viaticos = 0;
	float dia = 0;
	float sbruto = 0;
	float comida = 0;
	float sneto;
	float descuentos;

	printf("Nombre y apellido: ");
	fgets(nombre, 25, stdin);
	printf("Sueldo basico: ");
	scanf("%f", &sbasico);
	printf("Viaticos: ");
	scanf("%f", &viaticos);
        printf("Premios: ");
        scanf("%f", &premio);
	printf("Comida: ");
	scanf("%f", &comida);
	printf("Ausentes: ");
	scanf("%d", &ausentes);

	// Monto por dia trabajado.
	dia = sbasico / Laborables;

	// Descunto por ausentismo.
	sbruto = sbasico - (ausentes * dia);

	// Calculo de descuentos.
	descuentos = sbruto - (sbruto * (Ley + Os + Jub));

	// En caso de no haber ausentismo se asigna premio.
	if(ausentes == 0)
	{
		sbruto = descuentos + premio;
	}

	// Suma de comida y viaticos
	sneto = sbruto + comida + viaticos;

	// Impresión recibo detallado.
	printf("\t \t **Recibo de sueldo**\n");
	printf("Empleado: %s", nombre);
	printf("Sueldo basico $%.2f\n", sbasico);
        printf("Descuentos (Jub, Os, Ley19032) -$%.2f\n", descuentos);
	printf("Premio $%.2f\n", premio);
	printf("Sueldo neto: $%.2f\n", sneto);

	return 0;
}

