#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <algorithm>

using std::vector;
using namespace std;

bool mySortFunc(string x, string y)
{
	stringstream ss(x);
	double tmp, tmpx[3], tmpy[3];
	int i = 0;
	while (ss >> tmp) {
		tmpx[i] = tmp;
		i += 1;
	}
	i = 0;
	stringstream ssy(y);
	while (ssy >> tmp) {
		tmpy[i] = tmp;
		i += 1;
	}

	if (tmpx[0] > tmpy[0])
		return true;
	else
		return false;
}

double get_optimal_value(double capacity, vector<double> weights, vector<double> values) {
	double value = 0.0;
	int i;
	double tmp;
	vector<string> ratios(weights.size());
	for (i = 0; i < weights.size(); i++) {
		tmp = values[i] / weights[i];
		std::string x = to_string(tmp) + " " + to_string(weights[i]) + " " + to_string(values[i]);
		ratios[i] = x;
	}
	std::sort(ratios.begin(), ratios.end(), mySortFunc);

	i = 0;
	while (capacity > 0 && i < ratios.size()) {
		stringstream ss(ratios[i]);
		double tmp, x[3];
		int j = 0;
		while (ss >> tmp) {
			x[j] = tmp;
			j++;
		}
		if (x[1] <= capacity) {
			value += x[2];
			capacity -= x[1];
		} else {
			value += ((capacity * x[2]) / x[1]);
			capacity = 0;
		}
		i++;
	}
	return value;
}

int main() {
	int n;
	double capacity;
	std::cin >> n >> capacity;
	vector<double> values(n);
	vector<double> weights(n);
	for (int i = 0; i < n; i++) {
		std::cin >> values[i] >> weights[i];
	}

	double optimal_value = get_optimal_value(capacity, weights, values);

	std::cout.precision(9);
	std::cout << optimal_value << std::endl;
	return 0;
}
