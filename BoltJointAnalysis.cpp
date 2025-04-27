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
	
	float preload;		//75% of proof load
	int Pb;
	int force;
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
		scanf_s("%d", &force);

		Pb = jointstiffness(force, Fi);

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
	}	
	

	else {
		printf("End Of Program\n");
	}
	return 0;
}
