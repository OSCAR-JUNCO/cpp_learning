#ifndef RECURSION_H
#define RECURSION_H

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

extern int reversed;

int fibo(int n);
int search(vector<int> vec, int target, int start, int end);
void n_to_1(int n);
void one_to_n(int n);
void n_to_one_to_n(int n);
int factorial(int n);
int sum_of_n_to_one(int n);
int sum_of_digits(int n);
int product_of_digits(int n);

void reverse_number_with_static_variable(int n);
int reverse_number(int n);
int reverse_number_with_helper_function(int n);
int helper_reverse(int n, int digits);
bool palindrome_with_reverse(int n);
bool palindrome_with_helper(int n);
int getFirstDigit(int n);
bool helper_palindrome(int n, int start, int end, int digits);
int count_zeros(int n);
int helper_count_zeros(int n, int count);
int count_steps(int n);
int helper_count_steps(int n, int steps);

#endif // RECURSION_H