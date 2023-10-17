#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//----------------------------------------------------------------------
//Function to evaluate pi to a given accuracy using Monte Carlo method
//----------------------------------------------------------------------
//Copyright Shinnachot Jeerakan
//Input argument: Accuracy to reach estimated to be pi +/-
//Mothodology: Monte Carlo Method
//Return value: The estimate of pi
//-----------------------------------------------------------------------

double get_pi(double accuracy); // Declared this function to the program

//-----------------------------------------------------------------------
double get_pi(double accuracy) {
    double estimated = 0;

    int dartThrown = 0; //The value of every point on the area
    int dartInCircle = 0; //The value of every point that is in the circle

    //following code will be randomly generated in the do-while function below
    double x_axis = 0;
    double y_axis = 0;

    //The loop is going on until the number of dart thrown (every point) reach 100
    //Or the magnitude is more that the given accuracy

    do {
        //Both value x and y axis is random generated
        x_axis = -1+(2*(float)rand()) / RAND_MAX;
        y_axis = -1+(2*(float)rand()) / RAND_MAX;
        //the if is to add the number of the dart/point that is random in the circle
        if (pow(x_axis, 2) + pow(y_axis, 2) <= 1) {
            dartInCircle += 1;
        }
        dartThrown += 1; //Adds number of dart has been thrown

        estimated = 4.0 * (double)dartInCircle / (double)dartThrown;
    } while ((dartThrown < 100) || 4.0 / ((double)dartThrown + 1) > accuracy);

    //To return the estimated value
    return (estimated);
}

//-------------------------------------------------------------------------------------------------------------------------
//main program to use get_pi() function
//Copyright Shinnachot Jeerakan
//Required header files: stdio.h (for printf), time.h (for clock()), math.h (for pow() and sqrt()), stdlib.h (for RAND_MAX)
//-------------------------------------------------------------------------------------------------------------------------

int main() {
    double accuracy = 1;
    //creating loop to decrease the value of accuracy to get more precise value
    //These code recycled from Task A (Time to compute)
    for (accuracy = 1; accuracy >= 1e-10; accuracy /= 10) {
        clock_t begin = clock();
        float estimate = get_pi(accuracy);
        clock_t end = clock();
        double computeTime = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("\nThe estimate of pi: %4.12f when the accuracy demand: %4.10f Compute Time: %3.4f seconds", estimate, accuracy, computeTime);
    }
    return (0);
}
