#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

#include "Eigen/Core"
#include "Eigen/Dense"
#include "Eigen/Eigen"
#include "Eigen/LU"

std::vector<double> lineSplit(std::string str, char delimiter);
Eigen::MatrixXf Identity(const int rows, const int columns);

int main (int argc, char * * argv) {
	const char delimiter = ',';
	
	int i = 0;
	int j = 0;
	
	std::string fileName;
	std::fstream fileIn;
	std::string line;
	std::vector<double> row;

	if (argc == 2) {
		fileName = *(argv + 1);
	}
	else {
		fileName = "random_square_matrix.dat";
	}
	
	fileIn.open(fileName.c_str(), std::ios::in);
	
	if (fileIn.is_open()) {
		while (std::getline(fileIn, line)) {
			row = lineSplit(line, delimiter);
			
			i = row.size();
			j++;
		}
		
		if (i != j) {
			std::cerr << "ERROR: The matrix is not a square matrix" << std::endl;
			
			return EXIT_FAILURE;
		}
	}
	else {
		std::cerr << "ERROR: The file could not be opened" << std::endl;
		
		return EXIT_FAILURE;
	}
	
	const int rows = i;
	const int columns = j;
	
	Eigen::MatrixXd A(rows, columns);
	
	i = 0;
	j = 0;
	
	fileIn.clear();
	fileIn.seekg(0, std::ios::beg);
	
	if (fileIn.is_open()) {
		while (std::getline(fileIn, line)) {
			row = lineSplit(line, delimiter);
			
			for (i = 0; i < row.size(); i++) {
				A(j, i) = row.at(i);
			}
			
			j++;
		}
	}
	else {
		std::cerr << "ERROR: The file could not be opened" << std::endl;
		
		return EXIT_FAILURE;
	}
	
	
	Eigen::FullPivLU<Eigen::MatrixXd> LU(A);

	std::cout << "A" << std::endl;
	std::cout << std::fixed << std::setprecision(2) << A << std::endl;
	
	Eigen::MatrixXf L(rows, columns);
	L = Identity(rows, columns);
	L.triangularView<Eigen::StrictlyLower>() = LU.matrixLU();
	
	std::cout << "L" << std::endl;
	std::cout << std::fixed << std::setprecision(2) << L << std::endl;
	
	Eigen::MatrixXf U(rows, columns);
	U = Identity(rows, columns);
	U.triangularView<Eigen::Upper>() = LU.matrixLU();
	
	std::cout << "U" << std::endl;
	std::cout << std::fixed << std::setprecision(2) << U << std::endl;
	
	return EXIT_SUCCESS;
}

std::vector<double> lineSplit(std::string str, char delimiter) {
	std::vector<double> internal;
	std::stringstream ss(str);
	std::string tok;
	
	while (std::getline(ss, tok, delimiter)) {
		internal.push_back(atof(tok.c_str()));
	}
	
	return internal;
}

Eigen::MatrixXf Identity(const int rows, const int columns) {
	Eigen::MatrixXf matrix(rows, columns);
	
	for (int i = 0; i < rows; i++) {
		matrix(i, i) = 1;
	}
	
	return matrix;
}
