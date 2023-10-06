#include "recursion.h"

int reversed {0};

int fibo(int n) {
    // Base condition
    if (n < 2)
    {
        return n;
    }

    // Recursive call
    return fibo(n-1) + fibo(n-2);
}

int search(vector<int> vec, int target, int start, int end)
{
    if (start > end){
        return -1;
    }
    int middle = start + (end - start) / 2;
    if (vec[middle] == target){
        return middle;
    }
    if (vec[middle] > target){
        return search(vec, target, start, middle - 1);
    }
    return search(vec, target, middle + 1, end);

}

void n_to_1(int n) {
    if (n == 0) {
        return;
    }

    cout << n << endl;
    n_to_1(n-1);
}

void one_to_n(int n) {
    if (n == 0) {
        return;
    }
    one_to_n(n-1);
    cout << n << endl;
}

void n_to_one_to_n(int n) {
    if (n == 0) {
        return;
    }
    cout << n << endl;
    n_to_one_to_n(n-1);
    cout << n << endl;
}

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n-1);
}

int sum_of_n_to_one(int n) {
    if (n <= 1) {
        return 1;
    }
    return n + sum_of_n_to_one(n-1);
}

int sum_of_digits(int n) {
    int remainder = n % 10;
    int quotient = n / 10;
    if (quotient == 0) {
        return n;
    }
    return remainder + sum_of_digits(quotient);
}

int product_of_digits(int n) {
    if (n % 10 == n) {
        return n;
    }
    return n%10 * product_of_digits(n/10);
}


void reverse_number_with_static_variable(int n) {
    if (n == 0) {
        return;
    }
    int remainder = n%10;
    reversed = (reversed*10) + remainder;
    reverse_number_with_static_variable(n/10);
}

int reverse_number(int n) {
    if (n%10 == n) {
        return n;
    }
    int digits = (int) log10(n);
    int p = (int) pow(10, digits);
    return ((n%10) * p) + reverse_number(n/10);
}

int reverse_number_with_helper_function(int n) {
    int digits = (int) log10(n);
    return helper_reverse(n, digits);
}

int helper_reverse(int n, int digits) {
    if (n%10 == n) {
        return n;
    }
    return (n%10) * (int) pow(10, digits) + helper_reverse(n/10, digits - 1);
}

bool palindrome_with_reverse(int n) {
    return n == reverse_number_with_helper_function(n);
}

bool palindrome_with_helper(int n) {
    int start = getFirstDigit(n);
    int end = n%10;
    int digits = (int)log10(n) + 1;    

    return helper_palindrome(n, start, end, digits);
}

int getFirstDigit(int n) {
    n = abs(n);

    while(n >= 10) {
        n /= 10;
    }

    return n;
}

bool helper_palindrome(int n, int start, int end, int digits) {
    if (start != end) {
        return false;
    }
    if (digits == 2) {
        return start == end;
    }
    if (digits == 1) {
        return true;
    }

    n /= 10;
    n -= start*pow(10, digits-2);
    end = n%10;
    start = getFirstDigit(n);
    
    return helper_palindrome(n, start, end, digits-2);
}

int count_zeros(int n) {
    int count = 0;
    return helper_count_zeros(n, count);
}

int helper_count_zeros(int n, int count){
    if (n == 0) {
        return count;
    }

    int last_digit = n%10;
    if (last_digit == 0) {
        return helper_count_zeros(n/10, ++count);
    }
    return helper_count_zeros(n/10, count);
}

int count_steps(int n) {
    int steps = 0;
    return helper_count_steps(n, steps);
}

int helper_count_steps(int n, int steps) {
    if (n == 0) {
        return steps;
    }
    if (n%2 == 0) {
        return helper_count_steps(n/2, ++steps);
    }
    return helper_count_steps(n-1, ++steps);
}

// Check if (x,y) is a valid matrix coordinate
bool isSafe(int x, int y, int m, int n) {
    return (x >= 0 && x < m) && (y >= 0 && y < n);
}

double findProbability(int x, int y, int m, int n, int steps) {
    // Base conditions - Boundaries crossed
    if (!isSafe(x, y, m, n)) {
        return 0.0;
    }

    // Number of steps reached
    if (steps == 0) {
        return 1.0;
    }

    // Initialize result
    double probability {0.0};

    // Move up
    probability += findProbability(x, y+1, m, n, steps-1) * 0.25;

    // Move left 
    probability += findProbability(x-1, y, m, n, steps-1) * 0.25;

    // Move down
    probability += findProbability(x, y-1, m, n, steps-1) * 0.25;

    // Move right
    probability += findProbability(x+1, y, m, n, steps-1) * 0.25;

    return probability;
}