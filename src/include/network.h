#pragma once
#include <iostream>

#include <vector>
#include <memory>
#include "../include/inputNeuron.h"
#include "../include/layerNeuron.h"

class network {
 public:
  network(int inputWidth, int hiddenWidth, int hiddenLayers, int outputWidth);
  void train(std::vector<double> trainInputs, std::vector<double> trainOutputs);
  void calculate(std::vector<double> input, std::vector<double> &outputVector, int fromLayer = 1);
  void info();
 private:
  std::vector<std::vector<std::shared_ptr<neuron>>> synapses;
  std::vector<std::shared_ptr<neuron>> tempLayer;
};