#pragma once
#include <iostream>
#include <vector>

class neuron {
 public:
  virtual double getValue() =0;
  virtual void calcValue() =0;
  virtual void setValue(double setValue) =0;
  virtual std::vector<double> getWeights() =0;
  virtual void setWeight(int index, double value) =0;
};