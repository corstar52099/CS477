
#include <iostream>
#include <utility>

//prototypes
const int get_length(int* arr);
std::pair<int, int> divide(int array[], int, int);
std::pair<int, int> decidevals(std::pair<int, int> pass1, std::pair<int, int> pass2);

int main() {

	std::cout << "program is working" << std::endl;
	int arr[15] = {1,4,9,3,4,9,5,6,9,3,7, 13, 2, 1, 8};
	std::pair<int, int> answer = divide(arr, 0, 15);
	std::cout << "Smallest value: " << answer.first << std::endl;
	std::cout << "Largest Value: " << answer.second << std::endl;
	return 0;
}

std::pair<int, int> divide(int array[], int lower_bound, int upper_bound) {
	std::cout << "gets here" << std::endl;
	int size = upper_bound + 1;
	std::pair<int, int> vals;
	vals.second = array[upper_bound];
	vals.first = array[lower_bound];
	if (upper_bound == lower_bound) {
		return vals;
	}
	if ((upper_bound - lower_bound) == 1) {
		std::cout << "base case is reached";
		if (array[lower_bound] < array[upper_bound]) {
			vals.first = array[lower_bound];
			vals.second = array[upper_bound];
		}
		else {
			vals.first = array[upper_bound];
			vals.second = array[lower_bound];
		}
		return vals;
	}
		std:: pair<int, int> first = divide(array, 0, ((upper_bound + lower_bound) / 2));
		std:: pair<int, int> second = divide(array, ((upper_bound + lower_bound) / 2) + 1, upper_bound);
		return decidevals(first, second);
}

std::pair<int, int> decidevals(std::pair<int,int> pass1, std::pair<int, int> pass2){
	std::pair<int, int> returnval;
	//find smallest value
	if (pass1.first  <= pass2.first) {
		returnval.first = pass1.first;
	}
	else if (pass2.first <= pass1.first) {
		returnval.first = pass2.first;
	}
	if (pass1.second >= pass2.second) {
		returnval.second = pass1.second;
	}
	else if (pass2.second >= pass1.second){
		returnval.second = pass2.second;
	}
	return returnval;
}

const int get_length(int* arr) {
	int* temp = arr;
	int i = 0;
	for (i = 0; temp != NULL; temp++,i++) {
	}
	temp = NULL;
	return i;
}



/*struct maxmin
{
		int max;
		int min;
};*/