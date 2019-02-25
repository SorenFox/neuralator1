#include <memory>
#include <math.h>
#include "../include/layerNeuron.h"

layerNeuron::layerNeuron(std::vector<std::shared_ptr<neuron>> inputNeurons) {
  inputs = std::move(inputNeurons);

  for (int i=0; i < inputs.size(); i++) {
    weights.push_back(0.5);
  }
}

void layerNeuron::calcValue() {
  
  value = 0;

  for (int i=0; i < inputs.size(); i++) {
    value += inputs[i]->getValue() * weights[i];
  }

  value = value / (2 * (1+fabs(value))) + 0.5; //sigmoid approximation
}

double layerNeuron::getValue() {
  return value;
}

void layerNeuron::setValue(double setValue) {}

std::vector<double> layerNeuron::getWeights() {
  return weights;
}

void layerNeuron::setWeight(int index, double value) {
  weights[index] = value;
}