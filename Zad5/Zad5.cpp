//--------------------------------------------------------------------------------
// Code generated by jFuzzyLogic
// jFuzzyLogic Version : JFuzzyLogic 3.3 (build 2015-04-09), by Pablo Cingolani 
// jFuzzyLogic creted by Pablo Cingolani
//--------------------------------------------------------------------------------


#include <stdio.h>

#include <stdlib.h>
double ruleAccumulationMethod_max(double defuzzifierValue, double valueToAggregate)	{ return ( defuzzifierValue > valueToAggregate ? defuzzifierValue : valueToAggregate ); }

double ruleActivationMethod_min(double degreeOfSupport, double membership)	{ return (degreeOfSupport < membership ? degreeOfSupport : membership); }

double ruleConnectionMethod_and(double antecedent1, double antecedent2)	{ return (antecedent1 < antecedent2 ? antecedent1 : antecedent2); }

class FunctionBlock_tipper {

	public: 
	// VAR_INPUT
	double odleglosc;

	// VAR_OUTPUT
	double predkosc;

	private: 
	// FUZZIFY odleglosc
	double odleglosc_duza;
	double odleglosc_mala;
	double odleglosc_srednia;


	// DEFUZZIFY predkosc
	double defuzzify_predkosc[1000];


	public:
	FunctionBlock_tipper();
	void calc();
	void print();

	private:
	void defuzzify();
	void fuzzify();
	void reset();
	double membership_odleglosc_duza(double x);
	double membership_odleglosc_mala(double x);
	double membership_odleglosc_srednia(double x);
	double membership_predkosc_duza(double x);
	double membership_predkosc_mala(double x);
	double membership_predkosc_srednia(double x);
	void calc_No1();

};

// Constructor
FunctionBlock_tipper::FunctionBlock_tipper() {
	predkosc = 0.0;
}

// Calculate function block
void FunctionBlock_tipper::calc() {
	reset();
	fuzzify();
	calc_No1();
	defuzzify();
}

// RULEBLOCK No1
void FunctionBlock_tipper::calc_No1() {
	// RULE 1 : IF odleglosc IS mala THEN predkosc IS mala;
	double degreeOfSupport_1 = 1.0 * ( odleglosc_mala );
	if( degreeOfSupport_1 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = 0.0 + i * 0.1;
			double membership = membership_predkosc_mala(x);
			double y = ruleActivationMethod_min( degreeOfSupport_1 , membership );
			defuzzify_predkosc[i] += ruleAccumulationMethod_max( defuzzify_predkosc[i], y );
		}
	}

	// RULE 2 : IF odleglosc IS srednia THEN predkosc IS srednia;
	double degreeOfSupport_2 = 1.0 * ( odleglosc_srednia );
	if( degreeOfSupport_2 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = 0.0 + i * 0.1;
			double membership = membership_predkosc_srednia(x);
			double y = ruleActivationMethod_min( degreeOfSupport_2 , membership );
			defuzzify_predkosc[i] += ruleAccumulationMethod_max( defuzzify_predkosc[i], y );
		}
	}

	// RULE 3 : IF odleglosc IS duza THEN predkosc IS duza;
	double degreeOfSupport_3 = 1.0 * ( odleglosc_duza );
	if( degreeOfSupport_3 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = 0.0 + i * 0.1;
			double membership = membership_predkosc_duza(x);
			double y = ruleActivationMethod_min( degreeOfSupport_3 , membership );
			defuzzify_predkosc[i] += ruleAccumulationMethod_max( defuzzify_predkosc[i], y );
		}
	}

}

// Defuzzify 
void FunctionBlock_tipper::defuzzify() {
	double sum_predkosc = 0.0;
	double wsum_predkosc = 0.0;
	for (int i = 0; i < 1000 ; i++ ) {
		double x = 0.0 + i * 0.1;
		sum_predkosc += defuzzify_predkosc[i];
		wsum_predkosc += x * defuzzify_predkosc[i];
	}
	predkosc = wsum_predkosc / sum_predkosc;
}

// Fuzzify all variables
void FunctionBlock_tipper::fuzzify() {
	odleglosc_duza = membership_odleglosc_duza(odleglosc);
	odleglosc_mala = membership_odleglosc_mala(odleglosc);
	odleglosc_srednia = membership_odleglosc_srednia(odleglosc);
}

// Membership functions 
double FunctionBlock_tipper::membership_odleglosc_duza(double x) {
	if ( x <= 600.0 )	return 0.0;
	if ( x > 1000.0 )	return 1.0;
	if ( x <= 800.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 600.0 ) / ( 800.0 - 600.0 ) );
	if ( x <= 1000.0 )	return 1.0 + ( 1.0 - 1.0 ) * ( ( x - 800.0 ) / ( 1000.0 - 800.0 ) );
}

double FunctionBlock_tipper::membership_odleglosc_mala(double x) {
	if ( x <= 0.0 )	return 1.0;
	if ( x > 400.0 )	return 0.0;
	if ( x <= 200.0 )	return 1.0 + ( 1.0 - 1.0 ) * ( ( x - 0.0 ) / ( 200.0 - 0.0 ) );
	if ( x <= 400.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 200.0 ) / ( 400.0 - 200.0 ) );
}

double FunctionBlock_tipper::membership_odleglosc_srednia(double x) {
	if ( x <= 200.0 )	return 0.0;
	if ( x > 800.0 )	return 0.0;
	if ( x <= 400.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 200.0 ) / ( 400.0 - 200.0 ) );
	if ( x <= 600.0 )	return 1.0 + ( 1.0 - 1.0 ) * ( ( x - 400.0 ) / ( 600.0 - 400.0 ) );
	if ( x <= 800.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 600.0 ) / ( 800.0 - 600.0 ) );
}

double FunctionBlock_tipper::membership_predkosc_duza(double x) {
	if ( x <= 60.0 )	return 0.0;
	if ( x > 100.0 )	return 1.0;
	if ( x <= 80.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 60.0 ) / ( 80.0 - 60.0 ) );
	if ( x <= 100.0 )	return 1.0 + ( 1.0 - 1.0 ) * ( ( x - 80.0 ) / ( 100.0 - 80.0 ) );
}

double FunctionBlock_tipper::membership_predkosc_mala(double x) {
	if ( x <= 0.0 )	return 1.0;
	if ( x > 40.0 )	return 0.0;
	if ( x <= 20.0 )	return 1.0 + ( 1.0 - 1.0 ) * ( ( x - 0.0 ) / ( 20.0 - 0.0 ) );
	if ( x <= 40.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 20.0 ) / ( 40.0 - 20.0 ) );
}

double FunctionBlock_tipper::membership_predkosc_srednia(double x) {
	if ( x <= 20.0 )	return 0.0;
	if ( x > 80.0 )	return 0.0;
	if ( x <= 40.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 20.0 ) / ( 40.0 - 20.0 ) );
	if ( x <= 60.0 )	return 1.0 + ( 1.0 - 1.0 ) * ( ( x - 40.0 ) / ( 60.0 - 40.0 ) );
	if ( x <= 80.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 60.0 ) / ( 80.0 - 60.0 ) );
}


// Print 
void FunctionBlock_tipper::print() {
	printf("Function block tipper:\n");
	printf("	Input  %20s : %f\n", "odleglosc" , odleglosc);
	printf("	       %20s : %f\n", "odleglosc_duza" , odleglosc_duza);
	printf("	       %20s : %f\n", "odleglosc_mala" , odleglosc_mala);
	printf("	       %20s : %f\n", "odleglosc_srednia" , odleglosc_srednia);
	printf("	Output %20s : %f\n", "predkosc" , predkosc);
}

// Reset output
void FunctionBlock_tipper::reset() {
	for( int i=0 ; i < 1000 ; i++ )	{ defuzzify_predkosc[i] = 0.0; }
}

int main(int argc, char *argv[]) {
	// Create function blocks
	FunctionBlock_tipper tipper;

	// Parse input
	if( argc > 1 ) { tipper.odleglosc = atof(argv[1]); }
	
	while (tipper.odleglosc >= 0)
	{
		tipper.calc();
		tipper.print();
		tipper.odleglosc = tipper.odleglosc - 10;
	};
}
