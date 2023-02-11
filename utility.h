#include <iostream>
#include <vector>

void printList(std::vector<int>& list) {
    std::cout<<"[ ";
    for (int i: list) 
        std::cout<<i<<" ";
    std::cout<<"]\n";
}