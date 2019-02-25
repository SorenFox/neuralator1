#pragma once
#include <iostream>

#include "neuron.h"

class inputNeuron : public neuron {
 public:
	inputNeuron(double inputValue);
  virtual void setValue(double setValue);
  virtual void calcValue();
  virtual double getValue();
  std::vector<double> getWeights();
  void setWeight(int index, double value);

 private:
  double input;
};