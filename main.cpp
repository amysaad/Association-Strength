/*--------------------------------------------------------------
 Programmer: Amy Saad

 Summary: This program takes the input for three (x,y) coordinates from the user. It then
 calculates the strength of the association (strong, moderate, weak) and the correlation
 coefficient by using the correlation coefficient equation. 

 Date last modified:
 Sept 13, 2022 (as): began program
 Sept 15, 2022 (as): names variables and assigned them
 Sept 16, 2022 (as): calculations of declarations
 Sept 17, 2022 (as): calculations of declarations
 Sept 18, 2022 (as): print statements
 Sept 19, 2022 (as): association strength if statement
 Sept 20, 2022 (as): final adjustments

 //all comments describe the statement to its left

 ----------------------------------------------------------------*/

#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

#include "vitalSigns.h"
#include "vitalSigns.cpp"


int main()
{
                                                                            // DECLARE CONSTANTS
	const short						                                        // ----- CONSTANT declarations -----
    N = 3;                                                                  // number of (x,y) pairs
	
	const double
    STRONG = 0.75,                                                            // value to measure strength of association
    MODERATE = 0.50;
                                                                              // DECLARE VARIABLES
	double									                                  // ----- VARIABLE declarations -----
	x1 = getBodyTemperature_F(), y1 = getRespirationRate_BPM(),               // first  (x,y) pair
    x2 = getBodyTemperature_F(), y2 = getRespirationRate_BPM(),               // second (x,y) pair
    x3 = getBodyTemperature_F(), y3 = getRespirationRate_BPM();               // third  (x,y) pair
    //x1 = getRandomTemperature_F(), y1 = getRandom_BPM(),                    // first  random (x,y) pair
    //x2 = getRandomTemperature_F(), y2 = getRandom_BPM(),                    // second random (x,y) pair
    //x3 = getRandomTemperature_F(), y3 = getRandom_BPM();                    // third random (x,y) pair

    //Variable Declarations
    double
    SumOfX,                                                                 //sum of the 3 x values
    SumOfY,                                                                 //sum of the 3 y values
    SumOfSquareX,                                                           //sum of the 3 squared x values
    SumOfSquareY,                                                           //sum of the 3 squared y values
    SumOfXSquared,                                                          //sum of x values squared
    SumOfYSquared,                                                          //sum of y values squared
    SumXY,                                                                  //sum of the total of the x values and y values
    DenominatorB4Sqrt,                                                      //denominator calculated before square root
    Numerator,                                                              //numerator of correlation coefficient
    Denominator,                                                            //denominator of correlation coefficient
    CorrelationCoefficient,                                                 //correlation coefficient
    AssociationStrength;                                                    //strength of the association

                                                                            // Calculations of the Declarations
    SumOfX = (x1 + x2 + x3);
    SumOfY = (y1 + y2 + y3);
    SumOfSquareX = (SumOfX * SumOfX);
    SumOfSquareY = (SumOfY * SumOfY);
    SumOfXSquared = ((x1*x1) + (x2*x2) + (x3 * x3));
    SumOfYSquared = ((y1*y1) + (y2*y2) + (y3 * y3));
    SumXY = ((x1*y1) + (x2 * y2) + (x3 * y3));
    DenominatorB4Sqrt = (N*(SumOfXSquared) - (SumOfSquareX)) * (N*(SumOfYSquared) - (SumOfSquareY));
    Numerator = (N*(SumXY) - ((SumOfX*SumOfY)));
    Denominator = sqrt((N*(SumOfXSquared) - (SumOfSquareX)) * (N*(SumOfYSquared) - (SumOfSquareY)));
    CorrelationCoefficient = Numerator/Denominator;
    AssociationStrength = CorrelationCoefficient*CorrelationCoefficient;

    if (Denominator == 0){
        cout << "You can't have zero as the denominator" << endl;
        exit(EXIT_SUCCESS);
    }
    
                                                                            // Print statement for the three pairs
    cout << "                            Regression analysis on three pairs of " << endl;
    cout << "                            (BodyTemp, RespirationRate) values" << endl;
    cout << "                           -------------------------------------------" << endl;

    cout << "                           Your three (BodyTempF, RespirationRate) pairs are: " << endl;
    printf( "                           (x,y) pair 1: (%4.2f, %4.2f)\n",x1,y1);
    printf( "                           (x,y) pair 2: (%4.2f, %4.2f)\n",x2,y2);
    printf( "                           (x,y) pair 3: (%4.2f, %4.2f)\n",x3,y3);


                                                                            // Print statement for the Strength and Correlation

    cout << "                           -------------------------------------------" << endl;
    printf( "                           Strength of Association = %.2f\n", AssociationStrength);
    printf( "                           Correlation Coefficient = %.2f\n", CorrelationCoefficient);

                                                                            // If statement for the strength

    if (AssociationStrength >= STRONG)
        cout << endl <<"                     The relationship is strongly related.";
    else if (AssociationStrength >= MODERATE)
        cout << endl <<"                     The relationship is moderately related.";
    else
        cout << endl << "                    The relationship is weakly related.";
    return 0;

	
}                                                                           // end main()
