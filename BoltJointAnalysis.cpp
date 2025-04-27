#include <stdio.h>
#include <math.h>
#include "BoltJointAnalysis.h"

int main()
{
	int boltsize;		//Boltsize in metric Mxx
	float At;		//Bolt cross section		[mm2]
	int Fi;			//Bolt preload			[N]
	int Sp;			//Proof strength		[MPa]
	int Sy;			//Yield strength		[MPa]

	int P;			//External load			[N]
	int Kb;			//Bolt stiffness
	int Km;			//Member stiffness
	
	float preload;	//75% of proof load
	int Pb;
	int evaluation_stress;
	float factor_of_safety = 0.0;


	printf("Bolt size M");
	scanf_s("%d", &boltsize);

	At = bolt_At(boltsize);

	if (At != 0) {

		printf("Cross section of bolt is: %.1f\n", At);

		Sp = 600;
		Sy = 640;
		preload = 0.75;

		Fi = calcboltpreload(preload, Sp, At);

		printf("Preload for M%d is %d N\n", boltsize, Fi);

		printf("Force applied [N]:");
		scanf_s("%d", &P);

		Pb = jointstiffness(P, Fi);

		printf("Total bolt load is: %d N\n", Pb);

		evaluation_stress = checkboltstress(Pb, At);
		//Evaluation of proof strength
		if (evaluation_stress < Sp) {
			printf("Proof strength %d < %d OK\n", evaluation_stress, Sp);
		}
		else {
			printf("Proof strength %d > %d NOK\n", evaluation_stress, Sp);
		}

		//Evaluation of yield strength
		if (evaluation_stress < Sp) {
			printf("Yield strength %d < %d OK\n", evaluation_stress, Sy);
		}
		else {
			printf("Yield strength %d > %d NOK\n", evaluation_stress, Sy);
		}

		factor_of_safety = factor_safety(Sy, evaluation_stress);
		printf("Factor safety is: %.1f\n", factor_of_safety);

		//Export results in a .txt file
		FILE* result_txt;

		// Create a file
		errno_t err = fopen_s(&result_txt, "BoltJointAnalysisResult.txt", "w");
		if (err != 0) {
			printf("Failed to create the file.\n");
			return 1; // Exit the program with an error code
		}

		// Write some text to the file
		fprintf(result_txt, "INPUT DATA:\n");
		fprintf(result_txt, "-----------\n");
		fprintf(result_txt, "Boltsize M%d\n", boltsize);
		fprintf(result_txt, "Applied total load %d [N]\n", P);
		fprintf(result_txt, "\nRESULTS:\n");
		fprintf(result_txt, "-----------\n");
		fprintf(result_txt, "Stress area %.1f [mm2]\n", At);
		fprintf(result_txt, "Preload %d [N]\n", Fi);
		fprintf(result_txt, "Total bolt load %d [N]\n", Pb);
		fprintf(result_txt, "\nEVALUATION:\n");
		fprintf(result_txt, "-----------\n");
		fprintf(result_txt, "Proof stress %d [MPa]\n", Sp);
		fprintf(result_txt, "Yield stress %d [MPa]\n", Sy);
		fprintf(result_txt, "Stress on bold %d [MPa]\n", evaluation_stress);
		fprintf(result_txt, "Factor of safety %.1f\n", factor_of_safety);

		// Close the file
		fclose(result_txt);


	}
	else {
		printf("End Of Program\n");



	}
	return 0;
}
