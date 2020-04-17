/*Zeckendorf’s theorem states that every positive integer can be written uniquely as a sum of distinct non-neighbouring Fibonacci numbers. Two Fibonacci numbers are neighbours if they one come after other in Fibonacci Sequence (0, 1, 1, 2, 3, 5, ..). For example, 3 and 5 are neighbours, but 2 and 5 are not.

Given a number, find a representation of number as sum of non-consecutive Fibonacci numbers.

Examples:



Input:  n = 10
Output: 8 2
8 and 2 are two non-consecutive Fibonacci Numbers
and sum of them is 10.

Input:  n = 30
Output: 21 8 1
21, 8 and 1 are non-consecutive Fibonacci Numbers
and sum of them is 30.*/


class Solution
{
    public:

    int fibsum(int N)
    {
        vector<int> Fib;
        Fib.push_back(1);
        Fib.push_back(1);
        for(int i = 2; Fib[i - 1] < N; ++i) {
            int data = Fib[i - 1] + Fib[i - 2];
            Fib.push_back(data);
        }
        
        int ans = 0;
        int index = Fib.size() - 1;
        while (N > 0) {
            // find the largest fibonacci less than N.
            while (Fib[index] > N) index--;
            N -= Fib[index];
            ans++;
        }
        return ans;
    }
};

