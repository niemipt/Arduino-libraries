#include <math.h>
#include "Arduino.h"
#include "SimpleRunningLinearRegression.h"

SimpleRunningLinearRegression::SimpleRunningLinearRegression(int n) {
  Serial.println("SimpleRunningLinearRegression::SimpleRunningLinearRegression(" + String(n) + ")");

  //Create Array for y values
  p_n = n;
  p_yValues = new float[p_n];

  //Reset y value Array
  reset(0);

  //Reset counts
  p_Sx = 0;
  p_Sxx = 0;
  p_Sy = 0;
  p_Syy = 0;
  p_Sxy = 0;

  //X related parts that do not change
  for (int xValue = 0; xValue < p_n; xValue++) {
    p_Sx += xValue;
    p_Sxx += pow(xValue, 2);
  }

}

SimpleRunningLinearRegression::~SimpleRunningLinearRegression() {
  Serial.println("SimpleRunningLinearRegression::~SimpleRunningLinearRegression()");
  delete[] p_yValues;
}

void SimpleRunningLinearRegression::reset(float initValue) {
  Serial.println("SimpleRunningLinearRegression::reset()");
  p_yValuesIndex = 0;
  for (int i = 0; i < p_n; i++) {
    p_yValues[i] = initValue;
  }
}

void SimpleRunningLinearRegression::addYValue(float yValue) {

  p_oldYValue = p_yValues[p_yValuesIndex];
  p_yValues[p_yValuesIndex] = yValue;
  p_yValuesIndex = ++p_yValuesIndex % p_n;

  p_Sy = p_Sy - p_oldYValue + yValue;
  p_Syy = p_Syy - pow(p_oldYValue, 2) + pow(yValue, 2);
  p_Sxy = 0;

  p_yMin = p_yValues[0];
  p_yMax = p_yValues[0];

  for (int xValue = 0; xValue < p_n; xValue++) {
    p_Sxy += xValue * p_yValues[p_yValuesIndex];
    if (p_yValues[p_yValuesIndex] < p_yMin) {
      p_yMin = p_yValues[p_yValuesIndex];
    } else if (p_yMax < p_yValues[p_yValuesIndex]) {
      p_yMax = p_yValues[p_yValuesIndex];
    }
    p_yValuesIndex = ++p_yValuesIndex % p_n;
  }

  p_yAverage = p_Sy / p_n;
  p_correlation = (p_n * p_Sxy - p_Sx * p_Sy) / sqrt((p_n * p_Sxx - pow(p_Sx, 2)) * (p_n * p_Syy - pow(p_Sy, 2)));
  p_gradient = (p_n * p_Sxy - p_Sx * p_Sy) / (p_n * p_Sxx - pow(p_Sx, 2));
  p_yIntercept = (p_Sy / p_n) - (p_gradient * p_Sx / p_n);
  p_xIntercept = (-p_yIntercept / p_gradient);

}

