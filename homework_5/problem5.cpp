#include <iostream>

//prototypes
bool max_heap(int [], int, int, int);
//end prototypes


int main(){
    //initialize arrays 
    int A[10] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    int B[9]  = {10, 3, 9, 7, 2, 11, 5, 1, 6};
    
    //run max_heap on arr A
    std::cout << "Result for running max_heap on A: " << std::endl;
    if(max_heap(A, 1, 2, 10)){
        std::cout << "YES, heap" << std::endl;
    }
    else{
        std::cout << "Not a heap" << std::endl;
    }

    //run max_heap on arr B
    std::cout << "Result for running max_heap on A: " << std::endl;
    if(max_heap(B, 1, 2, 9)){
        std::cout << "YES, heap" << std::endl;
    }

    return 0;
}


//max_heap takes arr, parent, and child index for the recursion,
//and the size of the arryay as parameters
//runs max_heap algorithm to see if array is a max_heap or not
bool max_heap(int arr[], int parent, int child, int n){
    //an assumption is made for this algorithm where the child
    //is always the left child of a node or 2*parent_index

    if(child >= n )

    //base case if you've reached the end 
    if(parent == n - 1){
        return true;
    }

    //return false if the parent is less than both children
    if((arr[parent-1] < arr[child-1]) || (arr[parent-1] < arr[child])){
        return false;
    }
    //traverse the tree recursively and see if it remains true for all children
    //including left and right children 2*child for left child
    //2*i + 1 for right child
    else{
        if(max_heap(arr, child, 2*child, n) && max_heap(arr, child, 2*child +1, n)){
            return true;
        }
        else{
            return false;
        }

    }
}
