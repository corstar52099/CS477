#include <iostream>
#include <utility>

//prototypes
void precede(int[], int);
std::pair<int,int> getNegatives(int[], int);

//main function
int main(){
    int arr[12] = {4, 3, -2, 0, 2, 9, -1, 10, 0, 5, 23, -4};

    //place negatives preceding the positives
    precede(arr, 12);

}

void precede(int arr[], int n){
    std::pair<int,int> vals = getNegatives(arr, n);

    //arrays for the negative and positive values
    int* left = new int[vals.first];
    int* right = new int[vals.second];

    for(int i=0; i < n; i++){
        if ()
    }
}

//helper function to count negatives and positives
std::pair<int,int> getNegatives(int arr[], int n){
    int negatives = 0;
    int positives = 0;
    std::pair<int, int> returnVal;

    //loop incrementing for the values of the negatives and positives

    for(int i=0; i < n; i++){
        if(arr[i] < 0){
            negatives++;
        }
        else{
            positives++;
        }
    }
    returnVal.first = negatives;
    returnVal.second = positives;

    return returnVal;
}