#include <easy_problems.hpp>

int fibonacci (int n) {

    if (n == 1) {
        return 0;
    }
    if (n == 2 || n == 3) {
        return 1;
    }

    return fibonacci(n-1) + fibonacci(n-2);

}

int factorial (int n) {

    if (n == 0 || n == 1) {
        return 1;
    }

    return n * factorial(n-1);

}

int sum (int n) {

    if (n == 0) {
        return n;
    }

    return n + sum(n-1);

}
