#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "neuron.h"

class layerNeuron : public neuron {
 public:
	layerNeuron(std::vector<std::shared_ptr<neuron>> inputNeurons);
	virtual void calcValue();
	virtual double getValue();
	virtual void setValue(double setValue);
	virtual std::vector<double> getWeights();
	virtual void setWeight(int index, double value);

 private:
	std::vector<std::shared_ptr<neuron>> inputs;
	std::vector<double> weights;
	double value;
	double step;
};