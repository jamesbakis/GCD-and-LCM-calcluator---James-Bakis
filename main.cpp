#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "factor.h"

std::vector<Factor> getFactors(int num, std::vector<Factor> factors);

int main(int argc, char **argv) {

    if (argc > 1) {
        
        std::string input(argv[1]);
        
        if (input == "gcd" || input == "GCD") {
            std::cout << "Enter two numbers to calculate the GCD" << std::endl;
        } else {
            std::cout << "Enter two numbers to calculate the LCM" << std::endl;
        }
        int num1 = 0;
        int num2 = 0;
        
        

        std::cin >> num1;
        std::cin >> num2;
        
        if (!std::cin.good()) {
            std::cout << "Incorrect input, run the program again" << std::endl;
            return 0;
        }

        if (num1 == 0 || num2 == 0) {
            std::cout << "Neither of the values can be zero, run the program again" << std::endl;
            return 0;
        }

        std::cout << "The numbers are " << num1 << " and " << num2 << std::endl;
        
        int numVal = 0;
        if (num1 >= num2) {
            numVal = num1;
        } else {
            numVal = num2;
        }

        std::vector<Factor> factors = {};
        for (int i = 2; i <= numVal; ++i) {
            Factor factor(i);
            factors.push_back(factor);
        }
        std::vector<Factor> first = getFactors(num1, factors);
        std::vector<Factor> second = getFactors(num2, factors);
        
        if(input == "gcd" || input == "GCD") {
            int gcd = 1;
            for (size_t i = 0; i < first.size(); ++i) {
                if (first[i].getOccurence() <= second[i].getOccurence()) {
                    gcd *= pow(first[i].getValue(), first[i].getOccurence());
                } else {
                    gcd *= pow(second[i].getValue(), second[i].getOccurence());
                }
            }

            std::cout << "Greatest common denominator is " << gcd << std::endl;

        } else if (input == "lcm" || input == "LCM") {
            int lcm = 1;

            for (size_t i = 0; i < first.size(); ++i) {
                if (first[i].getOccurence() >= second[i].getOccurence()) {
                    lcm *= pow(first[i].getValue(), first[i].getOccurence());
                } else {
                    lcm *= pow(second[i].getValue(), second[i].getOccurence());
                }
                
            }

            std::cout << "Lowest common multiple is " << lcm << std::endl;  
        }
    }
    
    return 0;
}

std::vector<Factor> getFactors(int num, std::vector<Factor> factors) {
    int divisor = 2;
    while (num != 1) {
        if (num % divisor == 0) {
            factors[divisor - 2].incrementOccurence();
            num /= divisor;
            
            divisor = 2;
        } else {
            divisor += 1;
        }
        
    }
    return factors;
}