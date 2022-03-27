#include <iostream>
#include "project2.hpp"
#include <vector>
#include <string>

//write iterative first then plug in iterative helper
// Eric Fleming CS 315

    int main(int argc, char *argv[]) {
        if( argc != 2 ) {
            std::cout << "usage:" << argv[0] << " nameOfInputFile\n";
            exit(2);
        }
        std::vector<int> numbers, result, result2;
        read_numbers(std::string(argv[1]), numbers);
        //int iterVal = increasing_sequences_iterative(numbers);
        //int recVal = increasing_sequences_recursive(numbers, 0);
        //std::cout << iterVal << '\n' << recVal <<'\n';
        larger_left_right_iterative(numbers,result);
        larger_left_right_recursive(numbers,result2,numbers.size());
        //largest_left_iterative(numbers,result2);
        //largest_left_recursive(numbers, result, numbers.size());
        //std::cout << numbers.size();
        //int value = count_inversions_recursive(numbers, numbers.size());
         //int value2 = count_inversions_iterative(numbers);
        //std::cout << value << '\n';
         //std::cout << value2 << '\n';
       /* int k = 0;
        for(int v: result ) {
            std::cout << (v == result2.at(k)) << "  ";
            std::cout << k << std::endl;
            k++;
        } */

        return 0;
}
