#include <math.h>
#include "SimpleLinearRegression.h"

SimpleLinearRegression::SimpleLinearRegression(int n, float* xValues, float* yValues) {

  float Sx = 0;
  float Sy = 0;
  float Sxx = 0;
  float Syy = 0;
  float Sxy = 0;

  for (int p_n = 0; p_n < n; p_n++) {
    Sx += xValues[p_n];
    Sy += yValues[p_n];
    Sxx += pow(xValues[p_n], 2);
    Syy += pow(yValues[p_n], 2);
    Sxy += xValues[p_n] * yValues[p_n];
  }

  p_correlation = (n * Sxy - Sx * Sy) / sqrt((n * Sxx - pow(Sx, 2)) * (n * Syy - pow(Sy, 2)));
  p_gradient = (n * Sxy - Sx * Sy) / (n * Sxx - pow(Sx, 2));
  p_yIntercept = (Sy / n) - (p_gradient * Sx / n);
  p_xIntercept = (-p_yIntercept/p_gradient);

}

