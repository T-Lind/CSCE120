
#include <stdexcept>

const long double INTE_MAX = 2147483647;
const long double INTE_MIN = -2147483648;

int Largest(int a, int b, int c) {
    if (a >= b && a >= c) {
        return a;
    }
    if (b >= a && b >= c) {
        return b;
    }
    if (c >= a && c >= b) {
        return c;
    }
    return a;
}

bool SumIsEven(int a, int b) {
    return (a + b) % 2 == 0;
}

int BoxesNeeded(int apples) {
    if (apples <= 0)
        return 0;
    if (apples % 20 == 0)
        return apples / 20;
    return apples / 20 + 1;
}

bool SmarterSection(int A_correct, int A_total, int B_correct, int B_total) {
    if (A_total == 0 || B_total == 0) {
        throw std::invalid_argument("A_total and B_total must be greater than 0");
    }
    if (A_correct < 0 || A_total < 0 || B_correct < 0 || B_total < 0) {
        throw std::invalid_argument("A_correct, A_total, B_correct, and B_total must be greater than or equal to 0");
    }
    if (A_correct > A_total || B_correct > B_total) {
        throw std::invalid_argument("A_correct and B_correct must be less than or equal to A_total and B_total, respectively");
    }
    return (static_cast<double>(A_correct) / A_total) > (static_cast<double>(B_correct) / B_total);
}

bool GoodDinner(int pizzas, bool is_weekend) {
    if (is_weekend)
        return pizzas >= 10;
    return (pizzas >= 10) && (pizzas <= 20);
}

int SumBetween(int low, int high) {
    if (low > high) {
        throw std::invalid_argument("low must be less than or equal to high");
    }

    if (low == INTE_MIN && high == INTE_MAX) {
        return static_cast<int>(INTE_MIN);
    }

    // Longs are supposedly not in the spirit of this problem, but this is the easiest way I found to check for overflowk
    long double cumulative = (static_cast<long double>(high) * (high + 1) - static_cast<long double>(low) * (low - 1)) / 2;

    if (cumulative > INTE_MAX || cumulative < INTE_MIN) {
        throw std::overflow_error("Sum exceeds limits");
    }

    int value = static_cast<int>(cumulative);

    return value;
}

int Product(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    // check for potential overflow
    if (a > 0 && b > 0 && a > INTE_MAX / b) {
        throw std::overflow_error("Product exceeds INTE_MAX");
    }
    if (a > 0 && b < 0 && b < INTE_MIN / a) {
        throw std::overflow_error("Product exceeds INTE_MIN");
    }
    if (a < 0 && b > 0 && a < INTE_MIN / b) {
        throw std::overflow_error("Product exceeds INTE_MIN");
    }
    if (a < 0 && b < 0 && a < INTE_MAX / b) {
        throw std::overflow_error("Product exceeds INTE_MAX");
    }
    return a * b;
}