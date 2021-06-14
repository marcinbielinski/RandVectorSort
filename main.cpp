#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

class Printer {
public:
    static void printTenRandom(const std::vector<int>& my_vec) {
        std::cout << "Printing 10 randomly generated numbers: " << std::endl;
        printCounter();
        for (auto elem : my_vec)
        {
            printElem(elem);
        }
    }
    static void smallToBig(std::vector<int>& my_vec) {
        printCounter();
        std::cout << "Printing sorted from smallest to greatest: " << std::endl;
        std::sort(my_vec.begin(), my_vec.end(), [](auto& first, auto& last) { return first < last; });

        for (auto elem : my_vec)
        {
            printElem(elem);
        }
        printCounter();
    }
    static void bigToSmall(std::vector<int>& my_vec) {
        std::cout << "Printing sorted from greatest to smallest: " << std::endl;
        std::sort(my_vec.begin(), my_vec.end(), [](auto& first, auto& last) { return first > last; });

        for (auto elem : my_vec)
        {
            printElem(elem);
        }
        printCounter();
    }
private:
    // how many prints overall
    static void printCounter() {
        std::cout << "Counter is now: " << counter << std::endl;
    }
    static void printElem(int elem) {
        std::cout << elem << std::endl;
        counter++;
    }
    static int counter;
};

// counter definition initialized by zero initialization
int Printer::counter{0};


class MersenneEngine {
public:

    static std::vector<int> generate(std::vector<int>& my_vec) {
        // creating an instance of an random engine
        std::random_device device;

        // specification of the engine and its distribution
        std::mt19937 mersenne_engine {device()}; // generate random integers
        std::uniform_int_distribution<int> dist {1, 1000}; // in a range

        auto gen = [&dist, &mersenne_engine]() {
            return dist(mersenne_engine);
        };
        std::generate(my_vec.begin(), my_vec.end(), gen);

        return my_vec;
    }
};

int main() {
    std::vector<int> vec(10);
    MersenneEngine::generate(vec);
//    std::generate(my_vec.begin(), my_vec.end(), std::rand); // seemingly random output
    Printer::printTenRandom(vec);
    Printer::smallToBig(vec);
    Printer::bigToSmall(vec);
    return 0;
}
