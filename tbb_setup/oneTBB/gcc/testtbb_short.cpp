 #include <iostream>
 #include <vector>
 #include "oneapi/dpl/algorithm"
 #include "oneapi/dpl/execution"
 
int main() {
 
std::vector<int> vec = {1, 2, 3, 4, 5, 10, 20, 4 };

std::sort(std::execution::seq, vec.begin(), vec.end()); // sequential
std::sort(std::execution::par, vec.begin(), vec.end()); // parallel

std::cout << "Baris" << '\n';
 
}
