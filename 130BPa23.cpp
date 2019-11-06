#include <stdio.h>
#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include <math.h>

using namespace std;

int main(){
	int numCases;
	cin >> numCases;
	int store [numCases][2];
	int sol [numCases];
	for (int i = 0; i < numCases; i++){
		cin >> store[i][0] >> store[i][1];
	}
	for (int i = 0; i < numCases; i++){
		double space = pow(2.0,store[i][0]);
		int string = store[i][1];
		int inc = 0;
		if (string == 0){
			inc++;
		}
		while (string){
			string /= 10;
			inc++;
		}
		double prop = pow(2.0,inc);
		sol[i] = (int)(space - space/prop) % 1000000007;
	}
	for (int i = 0; i < numCases; i++){
		cout << sol[i] << endl;
	}
}