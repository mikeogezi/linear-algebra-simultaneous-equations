/*
	Determinant method
	
	Michael Ogezi
	03/08/2016
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
// #include <future>

#include "Eigen/Core"
#include "Eigen/Dense"
#include "Eigen/Eigen"
#include "Eigen/LU"

std::vector<double> lineSplit(std::string str, char delimiter);
Eigen::MatrixXd switchColumn(Eigen::MatrixXd orginalMatrix, Eigen::VectorXd vectorToSwitch, int columnToSwitch, int len);

int main (int argc, char ** argv) {
	const char delimiter = ',';
	
	int i = 0;
	int j = 0;
	
	std::string fileName;
	std::fstream fileIn;
	std::string line;
	std::vector<double> row;
	
	// std::vector< std::future<Eigen::MatrixXd> > futures;

	if (argc == 2) {
		fileName = *(argv + 1);
	}
	else {
		fileName = "random_eqn_matrix.dat";
	}
	
	fileIn.open(fileName.c_str(), std::ios::in);
	
	if (fileIn.is_open()) {
		while (std::getline(fileIn, line)) {
			row = lineSplit(line, delimiter);
			
			i = row.size();
			j++;
		}
		
		if (i != j + 1) {
			std::cerr << "ERROR: The matrix is not a n+1 by n matrix" << std::endl;
			
			return EXIT_FAILURE;
		}
	}
	else {
		std::cerr << "ERROR: The file could not be opened" << std::endl;
		
		return EXIT_FAILURE;
	}
	
	const int rows = i;
	const int columns = j;
	
	Eigen::MatrixXd A(columns, columns);
	Eigen::VectorXd b(columns);
	Eigen::VectorXd x(columns);
	
	i = 0;
	j = 0;
	
	fileIn.clear();
	fileIn.seekg(0, std::ios::beg);
	
	if (fileIn.is_open()) {
		while (std::getline(fileIn, line)) {
			row = lineSplit(line, delimiter);
			
			for (i = 0; i < row.size() - 1; i++) {
				A(j, i) = row.at(i);
				
				if (i == row.size() - 2) {
					b(j) = row.at(i + 1);
				}
			}
			
			j++;
		}
	}
	else {
		std::cerr << "ERROR: The file could not be opened" << std::endl;
		
		return EXIT_FAILURE;
	}
	
	double determinant;
	std::vector <double> determinants;
	
	determinant = A.determinant();

	std::cout << "THE DETERMINANT IS " << determinant << std::endl;
	
	for (i = 0; i < columns; i++) {
		Eigen::MatrixXd augmentedMatrix(columns, columns);
		// futures.push_back(std::async(std::launch::async, switchColumn, A, b, i, columns));
		augmentedMatrix = switchColumn(A, b, i, columns);
		
		determinants.push_back(augmentedMatrix.determinant());
	}
	
	for (i = 0; i < columns; i++) {
		// x(i) = futures.at(i).get().determinant() / determinant;
		x(i) = determinants.at(i) / determinant;
	}
	
	std::cout << "A" << std::endl;
	std::cout << std::fixed << std::setprecision(2) << A;
	std::cout << std::endl;
	
	std::cout << "b" << std::endl;
	std::cout << std::fixed << std::setprecision(2) << b;
	std::cout << std::endl;
	
	std::cout << "x" << std::endl;
	std::cout << std::fixed << std::setprecision(2) << x;
	std::cout << std::endl;
	
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

Eigen::MatrixXd switchColumn(Eigen::MatrixXd orginalMatrix, Eigen::VectorXd vectorToSwitch, int columnToSwitch, const int len) {
	Eigen::MatrixXd matrix(len, len);
	matrix = orginalMatrix;
	
	int i;
	
	for (i = 0; i < len; i++) {
		matrix(i, columnToSwitch) = vectorToSwitch(i);
	}
	
	return matrix;
}
