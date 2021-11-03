//This program is the same as cost_bp.cpp although there is some added
//functionality


#include <iostream>
#include <fstream>

//macros
#define OUTPUTFILE "cost_pd_out.txt"
#define r 1
#define c 10
//end macros

//prototypes
int min(int x, int y){return x<y?x:y;}
int optimal_value(int[], int[], int, char[]);
//end prototypes


int main(){

    int val= 0;
    std::ofstream myfile;
    myfile.open(OUTPUTFILE);

    //weight per week for algorithm
    int s[10] = {11,9,9,12,12,12,12,9,9,11};

    //optimal values to be calculated
    int opt_vals[10] = {0};

    //will hold specific path chosen
    char choice[10] = {0};

    //bottom up manner so it starts at index 9
    val = optimal_value(s, opt_vals, 9, choice);

    //output to a file
    myfile << "Week number        Optimal Value        Company" << std::endl;
    for (int i=0; i < 10; i++){
        myfile << i << "                  " << opt_vals[i] << "                   "<< choice[i] << std::endl;
    }
    myfile << "The optimal value of the algorithm is: " << val << std::endl << "Path: ";;
    for(int i =0; i < 10; i++){
        myfile << choice[i];
        if(i != 9){
            myfile << "->";
        }
    }
    myfile.close();
}

//integer j refers to the index of recursion
int optimal_value(int weight[], int opt_vals[], int j, char choice[]){
    int a = 0;
    int b =0;
    //base case
    if(j == 0){
        opt_vals[j] = r*weight[j];
        choice[j] = 'A';
        return opt_vals[j];
    }
    //case where there are <= 4 elements left
    if(j < 4){
        //if there are 4 elements left company B can still be chosen
        if(j == 3){
            a = (optimal_value(weight, opt_vals, j-1, choice) + r*weight[j]);
            b = (4*c);
            choice[j] = a < b? 'A':'B';
            opt_vals[j] = min(a, b);
            return opt_vals[j];
        }
        //there are <4 elements so company B cannot be chosen
        opt_vals[j] = optimal_value(weight, opt_vals, j-1, choice) + r * weight[j];
        choice[j] = 'A';
        return opt_vals[j];
    }
    //recursive case with no restricts, acts normally to recursive formula
    a = (optimal_value(weight, opt_vals, j-1, choice) + r*weight[j]);
    b = (optimal_value(weight, opt_vals, j-4, choice) + 4*c);
    choice[j] = a < b? 'A':'B';
    opt_vals[j] = min(a, b);
    return opt_vals[j];    

}