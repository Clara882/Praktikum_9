
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"headerlib.h"
#include<getopt.h>
#include<unistd.h>

int expected_value = 8;
int std_deviation = 1;
int amount_of_values = 100;
int i;
int option;

void help(void) {
	printf("Version: \n");
	printf("Autoren: Clara Stute, Islam Ider\n");
	printf("Mit diesesm Programm, können eine belibige Anzahl an Werten nach der Normalverteilung nach Gauß generiert werden.\n");
	printf("Der Erwartungswert, die Standartabweichung und die Anzahl der Werte können beim Start des Programms übergeben werden.\n");
	printf("Sollten keine Variablen übergeben werden, findet eine automatische generierung mit den default Werten statt.\n");
	printf("Die Ausgabe der Werte erfolgt in die Konsole und in die Datei 'output_stream.txt'.\n");
	printf("Optionen:\n");
	printf("-e Erwartungswert (default = 8)\n");
	printf("-s Standartabweichung (default = 1)\n");
	printf("-a Anzahl der zu berechnenden Werte (default = 100)\n");
}

int main (int argc, char *argv[]) {
	while ((option = getopt(argc, argv, "h e: s: a: ")) != -1) {
		switch (option) {
			case 'h' :
				help();
				break;
			case 'e' :
				expected_value = atoi (optarg);
				printf ("Erwartungswert: %i\n", expected_value);
				break;
			case 's' :
				std_deviation = atoi (optarg);
				printf ("Standartabweichung: %i\n", std_deviation);
				break;
			case 'a' :
				amount_of_values = atoi (optarg);
				printf ("Anzahl der Werte: %i\n", amount_of_values);
				break;
		}
	}


	FILE * output_stream;
	output_stream = fopen ("output_stream.txt", "w+");

	if (output_stream == NULL) {
		printf ("Error! Datei nicht gefunden\n");
		exit (-1);
	}

	for (i = 0; i <= amount_of_values - 1; i++) {
		print_gaussian_dist (expected_value, std_deviation, amount_of_values, output_stream);
	}
	fclose (output_stream);
}
