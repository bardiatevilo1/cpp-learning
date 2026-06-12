#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

const int MAX_SIZE = 100;

void displayMenu();
double computeSum(double arr[], int count);
double computeMean(double arr[], int count);
double computeMedian(double arr[], int count);
std::vector<double> computeMode(double arr[], int count);
double computeVariance(double arr[], int count, double mean);
double computeStdDev(double variance);
double computeMin(double arr[], int count);
double computeMax(double arr[], int count);
void displayResults(double sum, double mean, double median,
					std::vector<double> modes, double variance, double stdDev,
					double min, double max);
void sortArray(double arr[], int count);

int main() {
	displayMenu();

	std::string input;
	std::getline(std::cin, input);

	double data[MAX_SIZE];
	int currentSize = 0;

	std::replace(input.begin(), input.end(), ',', ' ');
	std::stringstream ss(input);

	for (double i; ss >> i;) {
		data[currentSize] = i;
		currentSize++;
	}

	if (currentSize == 0) {
		std::cout << "No data entered." << std::endl;
		return 1;
	}

	double sortedData[MAX_SIZE];
	std::copy(data, data + currentSize, sortedData);

	double sum = computeSum(data, currentSize);
	double mean = computeMean(data, currentSize);
	double median = computeMedian(sortedData, currentSize);
	std::vector<double> mode = computeMode(sortedData, currentSize);
	double variance = computeVariance(data, currentSize, mean);
	double stdDev = computeStdDev(variance);
	double min = computeMin(sortedData, currentSize);
	double max = computeMax(sortedData, currentSize);

	displayResults(sum, mean, median, mode, variance, stdDev, min, max);

	return 0;
}

void displayMenu() {
	std::cout << "=========================================" << std::endl;
	std::cout << "============STAT CALCULATOR==============" << std::endl;
	std::cout << "=========================================" << std::endl;
	std::cout << "Enter your data below: (e.g. 1,2,3,4,5,...)." << std::endl;
	std::cout << "Up to " << MAX_SIZE << " Elements" << std::endl;
}

double computeSum(double arr[], int count) {
	return std::accumulate(arr, arr + count, 0.0);
}

double computeMean(double arr[], int count) {
	double sum = computeSum(arr, count);
	return sum / static_cast<double>(count);
}
double computeMedian(double arr[], int count) {
	sortArray(arr, count);

	if (count % 2 == 0) {
		return (arr[count / 2] + arr[count / 2 - 1]) / 2.0;
	}

	return arr[count / 2];
}

std::vector<double> computeMode(double arr[], int count) {
	std::unordered_map<double, int> freqs;
	int max_count = 0;

	for (int i = 0; i < count; i++) {
		freqs[arr[i]]++;
		if (freqs[arr[i]] > max_count)
			max_count = freqs[arr[i]];
	}

	std::vector<double> modes;
	if (max_count > 1) {
		for (auto &pair : freqs) {
			if (pair.second == max_count)
				modes.push_back(pair.first);
		}
	}
	return modes;
}

double computeVariance(double arr[], int count, double mean) {
	double sum = 0;
	for (int i = 0; i < count; i++) {
		sum += pow(arr[i] - mean, 2);
	}
	return sum / static_cast<double>(count);
}

double computeStdDev(double variance) { return sqrt(variance); }

double computeMin(double arr[], int count) {
	sortArray(arr, count);
	return arr[0];
}

double computeMax(double arr[], int count) {
	sortArray(arr, count);
	return arr[count - 1];
}

void displayResults(double sum, double mean, double median,
					std::vector<double> modes, double variance, double stdDev,
					double min, double max) {
	std::cout << "Sum: " << sum << std::endl;
	std::cout << "Mean: " << mean << std::endl;
	std::cout << "Median: " << median << std::endl;
	if (modes.empty()) {
		std::cout << "Mode: No Mode" << std::endl;
	} else {
		std::cout << "Mode:";
		for (double m : modes)
			std::cout << " " << m;
		std::cout << std::endl;
	}
	std::cout << "Variance: " << variance << std::endl;
	std::cout << "Std Dev: " << stdDev << std::endl;
	std::cout << "Range: " << max - min << std::endl;
}

void sortArray(double arr[], int count) {
	// max 100 elements so will just use bubble sort
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				double temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
