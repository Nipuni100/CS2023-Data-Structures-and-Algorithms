#include <algorithm>
#include <chrono>
#include <iostream>
#include<vector>

using namespace std;
using namespace std::chrono;

const int MAX_SIZE = 10;

// PUSH
void PUSH(int S[], int& top, int size, int x) {
    if (top >= size - 1) {
        std::cout << "Stack Overflow" << std::endl;
    } else {
        top++;
        S[top] = x;
    }
}

// POP
int POP(int S[], int& top) {
    if (top == -1) {
        std::cout << "Stack Underflow" << std::endl;
        return -1;
    } else {
        int x = S[top];
        top--;
        return x;
    }
}

// IS_EMPTY
bool IS_EMPTY(int top) {
    return top == -1;
}

// IS_FULL
bool IS_FULL(int top, int size) {
    return top == size - 1;
}

// StackTop
int StackTop(int S[], int top) {
    if (IS_EMPTY(top)) {
        std::cout << "Stack Underflow" << std::endl;
        return -1;
    } else {
        return S[top];
    }
}

// Display
void Display(int S[], int top) {
    std::cout << "Stack: ";
    for (int i = top; i >= 0; i--) {
        std::cout << S[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int S[MAX_SIZE];
    int top = -1;
    
    auto start1 = high_resolution_clock::now();

    //Do something
    PUSH(S, top, MAX_SIZE, 8);
    PUSH(S, top, MAX_SIZE, 10);
    PUSH(S, top, MAX_SIZE, 5);
    PUSH(S, top, MAX_SIZE, 11);
    PUSH(S, top, MAX_SIZE, 15);
    PUSH(S, top, MAX_SIZE, 23);
    PUSH(S, top, MAX_SIZE, 6);
    PUSH(S, top, MAX_SIZE, 18);
    PUSH(S, top, MAX_SIZE, 20);
    PUSH(S, top, MAX_SIZE, 17);
    
    Display(S, top);

    //std::cout << "Popping elements from the stack..." << std::endl;
    for(int i=0;i<5;i++){
        POP(S, top);
    }
    
   

    // Display stack
    Display(S, top);
    
    PUSH(S, top, MAX_SIZE, 4);
    PUSH(S, top, MAX_SIZE, 30);
    PUSH(S, top, MAX_SIZE, 3);
    PUSH(S, top, MAX_SIZE, 1);
    

    // Display stack
    Display(S, top);

    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    cout<<endl;

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    // Display empty stack
    //std::cout << "Empty stack:" << std::endl;
    //Display(S, top);


    // Test PUSH and POP operations
    //std::cout << "Pushing elements onto the stack..." << std::endl;
    

    return 0;
}
