#include <memory>
#include <math.h>
#include "../include/network.h"

network::network(int inputWidth, int hiddenWidth, int hiddenLayers, int outputWidth) {
  
  synapses.resize(hiddenLayers + 2);

  for (int i=0; i < inputWidth; i++) {
    synapses[0].emplace_back(new inputNeuron(1.0));
  }

  for (int i=1; i < hiddenLayers + 1; i++) {
    for (int j=0; j < hiddenWidth; j++) {
      synapses[i].emplace_back(new layerNeuron(synapses[i-1]));
    }
  }

  for (int i=0; i < outputWidth; i++) {
    synapses[hiddenLayers + 1].emplace_back(new layerNeuron(synapses[hiddenLayers]));
  }
}

void network::train(std::vector<double> trainInputs, std::vector<double> trainOutputs) {
  
  std::vector<double> calcResults;
  double avgError1;
  double avgError2;
  double avgError3;

  for (int i=1; i < synapses.size(); i++) { //iterate through layers
    for (int j=0; j < synapses[i].size(); j++) { //iterate through neurons in layer
      for (int k=0; k < synapses[i][j]->getWeights().size(); k++) { //iterate through weights of a neuron
        
        avgError1 = 0;
        avgError2 = 0;
        avgError3 = 0;

        calculate(trainInputs, calcResults, i);
        for (int l=0; l < calcResults.size(); l++) {
          avgError1 += (calcResults[l] - trainOutputs[l]) * (calcResults[l] - trainOutputs[l]);
        }
        //We have a baseline error to the training data

        synapses[i][j]->setWeight(k, synapses[i][j]->getWeights()[k] + 0.01); //increment selected weight

        calculate(trainInputs, calcResults, i);
        for (int l=0; l < calcResults.size(); l++) {
          avgError2 += (calcResults[l] - trainOutputs[l]) * (calcResults[l] - trainOutputs[l]);
        }
        //Now we have a possible error if the weight is higher

        synapses[i][j]->setWeight(k, synapses[i][j]->getWeights()[k] - 0.02); //decrease selected weight

        calculate(trainInputs, calcResults, i);
        for (int l=0; l < calcResults.size(); l++) {
          avgError3 += (calcResults[l] - trainOutputs[l]) * (calcResults[l] - trainOutputs[l]);
        }
        //Now we have the possible error for a lower weight

        if (avgError1 <= avgError2 && avgError1 <= avgError3) {
          synapses[i][j]->setWeight(k, synapses[i][j]->getWeights()[k] + 0.01); //set to original value
        } else if (avgError2 <= avgError1 && avgError2 <= avgError3) {
          synapses[i][j]->setWeight(k, synapses[i][j]->getWeights()[k] + 0.02); //set to higher value
        } //else do nothing as weight has already been modified

      }
    }
  }
}

void network::calculate(std::vector<double> input, std::vector<double> &outputVector, int fromLayer) {
  
  if (fromLayer = 1) {
    for (int i=0; i < synapses[0].size(); i++) { //set all input neurons to calculation input
      synapses[0][i]->setValue(input[i]);
    }
  }

  for (int i=fromLayer; i < synapses.size(); i++) { //iterate through the layers from the selected layer
    for (int j=0; j < synapses[i].size(); j++) { //iterate through the full selected layer
      synapses[i][j]->calcValue();
    }
  }

  outputVector.clear();
  for (int i=0; i < synapses[synapses.size() - 1].size(); i++) { //set return vector to last layer values
    outputVector.push_back(synapses[synapses.size() - 1][i]->getValue());    
  }
}

void network::info() {
  std::cout << std::endl;
  std::cout << synapses.size() << std::endl;
  for (int i=0; i < synapses.size(); i++) {
    std::cout << synapses[i].size() << std::endl;
  }
}