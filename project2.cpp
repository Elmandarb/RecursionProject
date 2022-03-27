//
// Created by Erics on 2/11/2022.
//
#include <iostream>
#include <fstream>
#include "project2.hpp"
int count_inversions_iterative(const std::vector<int> &numbers) {
    if(numbers.size() < 2) {
        return 0;
    }

    int firstPlace = 0;
    int secondPlace = 1;
    int count = 0;
    while(secondPlace<numbers.size()) {
        if(numbers.at(firstPlace) > numbers.at(secondPlace)) {
            count++;
        }
        firstPlace++;
        secondPlace++;
    }
    return count;
}
int count_inversions_recursive(const std::vector<int> &numbers, int n) {
    if(n < 2) {
        return 0;
    }
    int first = (numbers.at(n-2) > numbers.at(n-1));
    return first + count_inversions_recursive(numbers, n-1);
}
void largest_left_iterative(const std::vector<int> &numbers, std::vector<int> &result) {
    int counter = 0;
    while(counter < numbers.size()) {
        result.push_back(leftHelper(numbers, counter));
        counter++;
    }
}
int leftHelper(const std::vector<int> &numbers, int n) {
    int secondCount = n-1;
    while(secondCount >= 0) {
        if(numbers.at(n) < numbers.at(secondCount)){
            return numbers.at(secondCount);
        }
        secondCount--;
    }
    return 0;
}
void largest_left_recursive(const std::vector<int> &numbers, std::vector<int> &result, int n) {
    if(n == 0) {
        return;
    }
    else {
        largest_left_recursive(numbers, result, n - 1);
        result.push_back(recursiveLeftHelper(numbers, n-1, n-1));
    }
}
int recursiveLeftHelper(const std::vector<int> &numbers, int n, int place) {
    if(n == 0) {
        return 0;
    }
    if(numbers.at(n-1) > numbers.at(place)) {
        return numbers.at(n-1);
    }
    return recursiveLeftHelper(numbers, n-1, place);
}
void larger_left_right_iterative(const std::vector<int> &numbers, std::vector<int> &result) {
    int place = 0;
    while(place < numbers.size()) {
        result.push_back(iterRightLeftHelper(numbers, place));
        place++;
    }
}
int iterRightLeftHelper(const std::vector<int> &numbers, int place) {
    int compareValue = numbers.at(place);
    int leftVal, rightVal = 0;
    int awayCounter = 1;
    while(awayCounter < numbers.size()) {
        if (place - awayCounter >= 0) {
            leftVal = numbers.at(place - awayCounter);
        }
        if (place + awayCounter < numbers.size()) {
            rightVal = numbers.at(place + awayCounter);
        }
        if(compareValue < leftVal || compareValue < rightVal) {
            if(leftVal > rightVal) {
                return leftVal;
            }
            return rightVal;
        }
        leftVal = 0;
        rightVal = 0;
        awayCounter++;
    }
    return 0;
}
void larger_left_right_recursive(const std::vector<int> &numbers, std::vector<int> &result, int n) {
    if(n == 0) {
        return;
    }
    larger_left_right_recursive(numbers, result, n-1);
    int place = leftRightRecHelper(numbers, n-1, numbers.size()-1);
    if(place == n-1) {
        result.push_back(0);
    }
    else {
        result.push_back(numbers.at(place));
    }
}
int leftRightRecHelper(const std::vector<int> &numbers, int n, int marker) {
    if(marker == 0) {
        return n;
    }
    int allButOne = leftRightRecHelper(numbers, n, marker - 1);
    if (allButOne != n) {
        return allButOne;
    }
    int leftVal = 0;
    int rightVal = 0;
    if((n+marker) < numbers.size()) {
        rightVal = numbers.at(n+marker);
    }

    if((n-marker) >= 0) {
        leftVal = numbers.at(n-marker);
    }
    if(rightVal > numbers.at(n) || leftVal > numbers.at(n)) {
        if(rightVal > leftVal) {
            return n+marker;
        }
        return n-marker;
    }
    return n;
}

int increasing_sequences_iterative(std::vector<int> &numbers) {
    int i = 0;
    int current = 1;
    int max = 0;
    while(i < numbers.size()) {
        if(i+1 < numbers.size()) {
            if(numbers.at(i+1) >= numbers.at(i)) {
                current++;
                if(current > max) {
                    max = current;
                }
            }
            else {
                if(current > max) {
                    max = current;
                }
                current = 1;
            }
        }
        i++;
    }
    return max;
}
int increasing_sequences_recursive(std::vector<int> &numbers, int startIdx) {
    if(startIdx == numbers.size()-1) {
        return 1;
    }
    int allButOne = increasing_sequences_recursive(numbers, startIdx+1);
    int firstVal = incSeqHelper(numbers, startIdx);
    if(allButOne>firstVal) {
        return allButOne;
    }
    return firstVal;
}
int incSeqHelper(const std::vector<int> &numbers, int n) {
    if(n == numbers.size()-1) {
        return 1;
    }
    if(numbers.at(n+1) > numbers.at(n)) {
        return 1 + incSeqHelper(numbers,n+1);
    }
    return 1;
}
void read_numbers(std::string fileName, std::vector<int> &v) {
    std::fstream inputStream;
    inputStream.open(fileName, std::ios::in);
    if(!inputStream.is_open()) {
        std::cout << "unable to open file";
        exit(2);
    }
    int number;
    while(inputStream >> number) {
        v.push_back(number);
    }
    return;
}