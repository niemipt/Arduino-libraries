#include "SimpleLinearRegression.h"

void setup() {
  
  Serial.begin(9600);
  delay(1000);

  float fiveUp[5] = {1, 2, 3, 4, 5};
  float fiveDown[5] = {5, 4, 3, 2, 1};

  float xValues[15] = {1.47, 1.50, 1.52, 1.55, 1.57, 1.60, 1.63, 1.65, 1.68, 1.70, 1.73, 1.75, 1.78, 1.80, 1.83};
  float yValues[15] = {52.21, 53.12, 54.48, 55.84, 57.20, 58.57, 59.93, 61.29, 63.11, 64.47, 66.28, 68.10, 69.92, 72.19, 74.46};

  SimpleLinearRegression slr1 = SimpleLinearRegression(5, fiveUp, fiveUp);
  SimpleLinearRegression slr2 = SimpleLinearRegression(5, fiveUp, fiveDown);
  SimpleLinearRegression slr3 = SimpleLinearRegression(15, xValues, yValues);

  Serial.println("SimpleLinearRegression 1");
  Serial.println("Correlation: " + String(slr1.getCorrelation()));
  Serial.println("Gradient: " + String(slr1.getGradient()));
  Serial.println("Y intercept: " + String(slr1.getYIntercept()));
  Serial.println("X intercept: " + String(slr1.getXIntercept()));
  Serial.println();

  Serial.println("SimpleLinearRegression 2");
  Serial.println("Correlation: " + String(slr2.getCorrelation()));
  Serial.println("Gradient: " + String(slr2.getGradient()));
  Serial.println("Y intercept: " + String(slr2.getYIntercept()));
  Serial.println("X intercept: " + String(slr2.getXIntercept()));
  Serial.println();

  Serial.println("SimpleLinearRegression 3");
  Serial.println("Correlation: " + String(slr3.getCorrelation()));
  Serial.println("Gradient: " + String(slr3.getGradient()));
  Serial.println("Y intercept: " + String(slr3.getYIntercept()));
  Serial.println("X intercept: " + String(slr3.getXIntercept()));
  Serial.println();

}

void loop() {
  delay(100000);
}
