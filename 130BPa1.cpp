#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	int minimum = 1000000;
	int minIndex = -1;
	int numWeights;
	float tolerance;
	cin >> tolerance >> numWeights;
	double weights [numWeights];
	for (int i = 0; i < numWeights; i++){
		cin >> weights[i];
		if (weights[i] <= minimum){
			minimum = weights[i];
			minIndex = i;
		}
	}

	int cuts [numWeights];
	for (int i = 0; i < numWeights; i++){
		cuts[i] = 0;
	}
	bool done = false;
	bool inc = false;
	while (!done){
		done = true;
		inc = false;
		for (int w = 0; w < numWeights; w++){
			if (w != minIndex){
				if ((minimum/(cuts[minIndex]+1))/(weights[w]/(cuts[w]+1)) < tolerance){
					cuts[w]++;
					if ((minimum/(cuts[minIndex]+1))/(weights[w]/(cuts[w]+1)) < tolerance){
						done = false;
					}
					else if ((minimum/(cuts[minIndex]+1))/(weights[w]/(cuts[w]+1)) > 2 - tolerance){
						done = false;
						inc = true;
					}
				}
			}
		}
		if (inc){
			cuts[minIndex]++;
		}
	}
	int total = 0;
	for (int i = 0; i < numWeights; i++){
		total += cuts[i];
	}
	cout << total << endl;
	return 0;
}

