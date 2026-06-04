#include <iostream>
#include <vector>
#include <cmath>


std::vector<int> sieve(size_t n);
void displayMenu();
std::string toString(std::vector<int> vec);

int main() {

    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        displayMenu();
        
        std::vector<int> primes;
        int N = -1;

        while (N <= 0) {
            std::cin >> N;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Invalid Input. Try again." << std::endl;
                continue;
            }
            if (N <= 0) std::cout <<"Enter a postive integer." << std::endl;
        }

        primes = sieve(static_cast<int>(N));
        std::string result = toString(primes);

        std::cout << result << std::endl;



        std::cout << "Would you like to choose another number? (Y/N):" << std::endl;
        std::cin >> choice;
    }



    return 0;
}


void displayMenu() {
    std::cout << "============================================" << std::endl;
    std::cout << "========== SIEVE OF ERASTHOSTENES ==========" << std::endl;
    std::cout << "============================================" << std::endl;

    std::cout << "Pick an integer N > 1 and we will generate all" << '\n' << "primes up to N: " << std::endl;

}

std::vector<int> sieve(size_t n) {
    if (n==1) return {};

    std::vector<bool> nums(n+1, true);
    std::vector<int> primes;

    for (size_t i = 2; i * i < n; i++) {
        if (nums[i]) {
            for (size_t j = i * i; j < n; j*=i) {
                nums[j] = false;
            }
        }
    }

    for (size_t i = 2; i < n+1; i++) {
        if (nums[i]) {
            primes.push_back(static_cast<int>(i));
        }
    }

    return primes;
}

std::string toString(std::vector<int> vec) {
    std::string str;
    bool first = true;

    for (int x : vec) {
        if (first) {
            first = false;
        } else{
            str += ", ";
        }
        str += std::to_string(x);
    }
    return str;
}
