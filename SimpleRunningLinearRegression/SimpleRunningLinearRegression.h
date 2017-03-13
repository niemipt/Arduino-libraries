#ifndef SIMPLERUNNINGLINEARREGRESSION_H
#define SIMPLERUNNINGLINEARREGRESSION_H

/*
   Class for counting simple linear regressions
   Ideas based on https://en.wikipedia.org/wiki/Simple_linear_regression
   You can add only Y-values and X-values are from 0 to size - 1 of running range
   Works for example when using measured data in fixed measure intervals
*/
class SimpleRunningLinearRegression {

  private:

    int p_n;
    int p_yValuesIndex;
    float p_oldYValue;
    float* p_yValues;
    float p_Sx;
    float p_Sy;
    float p_Sxx;
    float p_Syy;
    float p_Sxy;
    float p_yMin;
    float p_yMax;
    float p_yAverage;
    float p_correlation;
    float p_gradient;
    float p_yIntercept;
    float p_xIntercept;

  public:

    SimpleRunningLinearRegression(int);
    ~SimpleRunningLinearRegression();
    void reset(float);
    void addYValue(float);
    float getYMin() {
      return p_yMin;
    }
    float getYMax() {
      return p_yMax;
    }
    float getYAverage() {
      return p_yAverage;
    }
    float getCorrelation() {
      return p_correlation;
    }
    float getGradient() {
      return p_gradient;
    }
    float getYIntercept()  {
      return p_yIntercept;
    }
    float getXIntercept()  {
      return p_xIntercept;
    }

};

#endif
