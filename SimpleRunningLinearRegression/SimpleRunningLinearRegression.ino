#include "SimpleRunningLinearRegression.h"

void setup() {

  Serial.begin(9600);
  delay(1000);

  SimpleRunningLinearRegression* srlr = new SimpleRunningLinearRegression(5);

  for (int i = 0; i < 10; i++) {
    float yValue1 = i + 1;
    Serial.println("SimpleRunningLinearRegression::addYValue(" + String(yValue1) + ")");
    srlr->addYValue(yValue1);
    Serial.println("Y Average: " + String(srlr->getYAverage()));
    Serial.println("Correlation: " + String(srlr->getCorrelation()));
    Serial.println("Gradient: " + String(srlr->getGradient()));
    Serial.println("Y intercept: " + String(srlr->getYIntercept()));
    Serial.println("X intercept: " + String(srlr->getXIntercept()));
    Serial.println();
  }

  delete srlr;

}

void loop() {
  delay(100000);
}
