#include <iostream>

//macros
#define OUTPUTFILE cost_pb_out.txt
#define r 1
#define c 10
//end macros

//prototypes
int min(int x, int y){return x<y?x:y;}
int optimal_value(int weight[], int opt_vals[], int j);
//endprototypes


int main(){
    int val= 0;

    //weight per week for algorithm
    int s[10] = {11,9,9,12,12,12,12,9,9,11};
    //optimal values to be calculated
    int opt_vals[10] = {0,0,0,0,0,0,0,0,0,0};
    //bottom up manner so it starts at index 9
    val = optimal_value(s, opt_vals, 9);
    
    std::cout << "The optimal value of the algorithm is: " << val << std::endl;
    for (int i=0; i < 10; i++){
        std::cout << "Optimal value at index [" << i << "]: " << opt_vals[i] << std::endl;
    }

}

//integer j refers to the index of recursion
int optimal_value(int weight[], int opt_vals[], int j){

    //base case
    if(j == 0){
        opt_vals[j] = r*weight[j];
        return opt_vals[j];
    }
    //case where there are <= 4 elements left
    if(j < 4){
        //if there are 4 elements left company B can still be chosen
        if(j == 3){
            opt_vals[j] = min((optimal_value(weight, opt_vals, j-1) + r*weight[j]), (4*c));
            return opt_vals[j];
        }
        //there are <4 elements so company B cannot be chosen
        opt_vals[j] = optimal_value(weight, opt_vals, j-1) + r * weight[j];
        return opt_vals[j];
    }
    //recursive case with no restricts, acts normally to recursive formula
    opt_vals[j] = min((optimal_value(weight, opt_vals, j-1) + r*weight[j]), 
               (optimal_value(weight, opt_vals, j-4) + 4*c));
    return opt_vals[j];    

}