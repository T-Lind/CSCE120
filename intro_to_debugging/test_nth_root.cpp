#include <iostream>
#include <cmath>
#include "./nth_root.h"

int main() {
    {   // MINIMUM REQUIREMENT (for this lab)

        for (int i = -10; i <= 10; i++) {
            double j = -10;
            while (j <= 10) {
                try {
                    nth_root(i, j);
                } catch (std::exception &ex) {
                }
                j += 0.25;

            }
        }
    }

    {   // TRY HARD
        // report the value
        try {
            double actual = nth_root(2, 1);
            std::cout << "nth_root(2, 1) = " << actual << std::endl;
        } catch (std::exception &ex) {

        }
    }

    {   // TRY HARDER
        // compare the actual value to the expected value
        double actual = nth_root(2, 1);
        double expected = 1;
        if (std::fabs(actual - expected) > 0.00005) {
            std::cout << "[FAIL] (n=2, x=1)" << std::endl;
            std::cout << "  expected nth_root(2, 1) to be " << expected << std::endl;
            std::cout << "  got " << actual << std::endl;
        } else {
            std::cout << "[PASS] (n=2, x=1)" << std::endl;
        }
    }
}
