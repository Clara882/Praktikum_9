#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void print_gaussian_Erw_Sta (int amount_of_values, FILE * input_stream) {

	double Summe, Erwartungswert, Varianz = 0, Standartabweichung = 0, Zwischensumme = 0, Varianz_vorher = 0;
	int Länge = 15;
	char Zwischenspeicher [Länge];
	char * Stopp;

	while (fgets (Zwischenspeicher, Länge, input_stream)) {
		Zwischensumme = (strtod (Zwischenspeicher, &Stopp)) + Zwischensumme;
	
	}

	Summe = Zwischensumme;
	printf ("Die Summe aller Werte ist: %f\n", Summe);

	Erwartungswert = Summe / amount_of_values;
	printf ("Der Erwartungswert ist: %f\n", Erwartungswert);
	
	while (fgets (Zwischenspeicher, Länge, input_stream)) {
		Varianz_vorher = (strtod (Zwischenspeicher, &Stopp)) + Varianz_vorher;
	//	Varianz_vorher = (pow((strtod (Zwischenspeicher, &Stopp) - Erwartungswert), 2.0)) + Varianz_vorher;
	}

	Varianz = Varianz_vorher / amount_of_values;
	printf ("Die Varianz ist: %f\n", Varianz);

	Standartabweichung = sqrt (Varianz);
	printf ("Die Standartabweichung ist: %f\n", Standartabweichung);


}
