#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"staticlib.h"
#include<unistd.h>
#include<getopt.h>

int expected_value;
int std_deviation;
int amount_of_values;
int i;
int option;

void help (void) {
	printf("Version 1.0\n");
	printf("Autoren: Clara Stute, Islam Ider\n");
	printf("\n");
	printf("Optionen:\n");
	printf("-h Help\n");
}

int main (int argc, char * argv[]) {
	while ((option = getopt (argc, argv, "h")) != -1) {
		switch (option) {
			case 'h':
				help();
				break;
		}
	}

	FILE * input_stream;
	input_stream = fopen ("output_stream.txt", "r");

	print_gaussian_Erw_Sta (amount_of_values, input_stream);

	fclose (input_stream);
}
