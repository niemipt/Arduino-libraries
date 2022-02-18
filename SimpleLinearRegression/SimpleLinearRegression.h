#ifndef SIMPLELINEARREGRESSION_H
#define SIMPLELINEARREGRESSION_H

 /*
  * Class for counting simple linear regressions
  * Ideas based on https://en.wikipedia.org/wiki/Simple_linear_regression
  */
class SimpleLinearRegression {
  
private:

    float p_correlation;
    float p_gradient;
    float p_yIntercept;
    float p_xIntercept;
 
public:

    SimpleLinearRegression(int n, float* xValues, float* yValues);
    float getCorrelation() { return p_correlation; }
    float getGradient() { return p_gradient; }
    float getYIntercept()  { return p_yIntercept; }
    float getXIntercept()  { return p_xIntercept; }
    
};
 
#endif
