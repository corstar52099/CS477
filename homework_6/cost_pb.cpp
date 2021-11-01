#include <iostream>

//macros
#define OUTPUTFILE cost_pb_out.txt
#define r 1
#define c 10
//end macros

//prototypes
int min(int x, int y){return x<y?x:y;}
//endprototypes


int main(){
    int val= 0;

    //weight per week for algorithm
    int s[10] = {11,9,9,12,12,12,12,9,9,11};
    //optimal values to be calculated
    int opt_vals[10] = {0,0,0,0,0,0,0,0,0,0};
    val = optimal_value(s, opt_vals, 9, 10);
    
    std::cout << "The optimal value of the algorithm is: " << val << std::endl;
    for (int i=0; i < 10; i++){
        std::cout << "Optimal value at index [" << i << "]: " << opt_vals[i] << std::endl;
    }

}

//integer j refers to the index of recursion and integer n is the size of the array
int optimal_value(int weight[], int opt_vals[], int j, int n){
    //base case
    if(j == 0){
        opt_vals[j] = r*weight[j];
        return 0;
    }
    if(j < 4){
        opt_vals[j] = optimal_value(weight, opt_vals, j-1, n-1) + r * weight[j];
        return opt_vals[j];
    }
    opt_vals[j] = min((optimal_value(weight, opt_vals, j-1, n-1) + r*weight[j]), 
               (optimal_value(weight, opt_vals, j-4, n-4) + 4*c));
    return opt_vals[j];    

}