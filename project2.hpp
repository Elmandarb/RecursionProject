//
// Created by Erics on 2/11/2022.
//

#ifndef INC_315PROJECT2_PROJECT2_HPP
#define INC_315PROJECT2_PROJECT2_HPP
#include <vector>
#include <string>


    int count_inversions_iterative(const std::vector<int> &numbers);
    int count_inversions_recursive(const std::vector<int> &numbers, int n);
    void largest_left_iterative(const std::vector<int> &numbers, std::vector<int> &result);
    void largest_left_recursive(const std::vector<int> &numbers, std::vector<int> &result, int n);
    void larger_left_right_iterative(const std::vector<int> &numbers, std::vector<int> &result);
    void larger_left_right_recursive(const std::vector<int> &numbers, std::vector<int> &result, int n);
    static int increasing_sequences_iterative(std::vector<int> &numbers);
    int increasing_sequences_recursive(std::vector<int> &numbers, int startIdx);
    void read_numbers(std::string fileName, std::vector<int> &v);
    int leftHelper(const std::vector<int> &numbers, int n);
    int incSeqHelper(const std::vector<int> &numbers, int n);
    int recursiveLeftHelper(const std::vector<int> &numbers, int n, int place);
    int iterRightLeftHelper(const std::vector<int> &numbers, int place);
    int leftRightRecHelper(const std::vector<int> &numbers, int n, int marker);



#endif //INC_315PROJECT2_PROJECT2_HPP
