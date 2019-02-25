#include <iostream>
#include "../include/network.h"
#include <vector>

int main() {
	network net{3, 4, 2, 3};
	std::string usrInput;
	double avgError;
	std::vector<double> trainIn;
	std::vector<double> trainOut;
	std::vector<double> results;

	std::cout.precision(17);

	for (int i=0; i < 3; i++) {
		trainIn.push_back(1);
	}

	trainOut.push_back(1);
	trainOut.push_back(0);
	trainOut.push_back(0);

	while(true) {
		std::cin >> usrInput;
		std::cout << std::endl;

		if (usrInput == "info") {
			net.info();
		} else if (usrInput == "exit") {
			return 0;
		} else if (usrInput == "train") {
			for (int i=0; i < 100; i++) {
				net.train(trainIn, trainOut);
				net.calculate(trainIn, results);
				// std::cout << std::fixed << results.size() << std::endl;
				avgError = 0;
				for (int i=0; i < results.size(); i++) {
					// avgError += abs(results[i] - trainOut[i]);
					std::cout << std::fixed << results[i] << std::endl;
				}
				avgError /= results.size();
				//std::cout << std::fixed << avgError << std::endl;
			}
			std::cout << "done" << std::endl;
		}
	}
	
}