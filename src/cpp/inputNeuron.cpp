#include <iostream>

#include "../include/inputNeuron.h"

inputNeuron::inputNeuron(double inputValue) {
  input = inputValue;
}

void inputNeuron::setValue(double setValue) {
  input = setValue;
}

double inputNeuron::getValue() {
  return input;
}

void inputNeuron::calcValue() {}

std::vector<double> inputNeuron::getWeights() {
  std::vector<double> weights;
  weights.push_back(1.0);
  return weights;
}

void inputNeuron::setWeight(int index, double value) {}