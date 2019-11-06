#include <stdio.h>
#include <iostream>
#include <stdlib.h> 
#include <time.h>

using namespace std;


int main(){
	int numCars;
	cin >> numCars;
	if (numCars == 0){
		cout << 0 << endl;
		return 0;
	}
	int cars [numCars];
	int incr [numCars];
	int decr [numCars];
	for (int i = 0; i < numCars; i++){
		cin >> cars[i];
	}
	for (int i = 0; i < numCars; i++){
		incr[i] = 1;
		decr[i] = 1;
	}
	for (int i = numCars-1; i >= 0; i--){
		for (int j = i; j < numCars; j++){
			if (cars[i] > cars[j] && incr[i] < incr[j] + 1){
				incr[i] = incr[j] + 1;
			}
			if (cars[i] < cars[j] && decr[i] < decr[j] + 1){
				decr[i] = decr[j] + 1;
			}
		}
	}
	int max = 0;
	for (int i = 0; i < numCars; i++){
		//cout << incr[i] << " " << decr[i] << endl;
		if (incr[i] + decr[i] - 1 > max){
			max = incr[i] + decr[i] - 1;
		}
	}
	cout << max << endl;
	return 0;
}




