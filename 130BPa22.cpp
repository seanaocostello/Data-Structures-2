#include <stdio.h>
#include <iostream>
#include <stdlib.h> 
#include <time.h>

using namespace std;

int train [2000][2000][3];

int dpAlg(int cars [], int numCars){
    for (int i = 0; i < numCars; i++){
        train[i][i][0] = 1;
        train[i][i][1] = cars[i];
        train[i][i][2] = cars[i];
    }
    for (int i = 1; i < numCars; i++){
        for (int j = 0; j < (numCars-i); j++){
            if (train[i+j-1][j][0]+1 < train[i+j][j+1][0]){
                train[i+j][j][0] = train[i+j][j+1][0];
                train[i+j][j][1] = train[i+j][j+1][1];
                train[i+j][j][2] = train[i+j][j+1][2];
            }
            else if (train[i+j-1][j][1] > cars[i+j]){
                train[i+j][j][0] = train[i+j-1][j][0]+1;
                train[i+j][j][1] = cars[i+j];
                train[i+j][j][2] = train[i+j-1][j][2];
            }
            else if (train[i+j-1][j][2] < cars[i+j]){
                train[i+j][j][0] = train[i+j-1][j][0]+1;
                train[i+j][j][1] = train[i+j-1][j][1];
                train[i+j][j][2] = cars[i+j];
            }
            else if (train[i+j-1][j][0] >= train[i+j][j+1][0]){
                if (car[i+j-1] == train[i+j-1][j][1]){
                    train[i+j][j][0] = train[i+j-1][j][0];
                    train[i+j][j][1] = car[i+j];
                    train[i+j][j][2] = train[i+j-1][j][2];
                }
                else if (car[i+j-1] == train[i+j-1][j][2]){
                    train[i+j][j][0] = train[i+j-1][j][0];
                    train[i+j][j][1] = train[i+j-1][j][1];
                    train[i+j][j][2] = car[i+j];
                }
            }
            else {
                train[i+j][j][0] = train[i+j][j+1][0];
                train[i+j][j][1] = train[i+j][j+1][1];
                train[i+j][j][2] = train[i+j][j+1][2];
            }
            cout << train[i+j][j][0] << endl;
            cout << train[i+j][j][1] << endl;
            cout << train[i+j][j][2] << endl;
            for (int i = 0; i < numCars; i++){
                cout << cars[i] << ": ";
                for (int j = 0; j < numCars; j++){
                    cout << train[i][j][0] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
        
    }
    //cout << train[numCars-1][0][0] << endl;
    return train[numCars-1][0][0];
}

int slowAlg(int cars [], int numCars){
    int trains [numCars][3];
    trains[0][0] = 1;
    trains[0][1] = cars[0];
    trains[0][2] = cars[0];
    int max = 0;
    for (int k = 0; k < numCars-1; k++){
        for (int i = k+1; i < numCars; i++){
            trains[i][0] = 1;
            trains[i][1] = cars[i];
            trains[i][2] = cars[i];
            for (int j = k; j < i; j++){
                if (cars[i] > trains[j][2] && trains[j][0] + 1 > trains[i][0]){
                    trains[i][0] = trains[j][0]+1;
                    trains[i][1] = trains[j][1];
                    trains[i][2] = cars[i];
                }
                else if (cars[i] < trains[j][1] && trains[j][0] + 1 > trains[i][0]){
                    trains[i][0] = trains[j][0]+1;
                    trains[i][1] = cars[i];
                    trains[i][2] = trains[j][2];
                }
            }
        }
        for (int i = 0; i < numCars; i++){
            if (trains[i][0] > max){
                max = trains[i][0];
            }
            trains[i][0] = 1;
            trains[i][1] = cars[i];
            trains[i][2] = cars[i];
        }
    }
    return max;
}

int main(){
    srand(time(NULL));
    int a = 0;
    int b = 0;
    int c = 0;
    while (a == b && c < 100){
        int numCars = rand() % 5 + 3;
        int cars [numCars];
        for (int i = 0; i < numCars; i++){cars[i] = 0;}
        for (int i = 0; i < numCars; i++){
            int d = rand() % numCars;
            if (cars[d] == 0){
                cars[d] = i+1;
            }
            else{
                a += rand() % numCars;
                i--;
            }
        }
        a = dpAlg(cars, numCars);
        b = slowAlg(cars, numCars);
        cout << a << " " << b << endl;
        c++;
        if (a != b){
            for (int i = 0; i < numCars; i++){
                cout << cars[i] << " ";
            }
        }
        cout << endl;
        for (int i = 0; i < numCars; i++){
            for (int j = 0; j < numCars; j++){
                train[i][j][0] = 0;
                train[i][j][1] = 0;
                train[i][j][2] = 0;
            }
        }
    }
    
    //cout << a << " " << b << endl;
    return 0;
}


