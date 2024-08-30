class Solution {
public:
    vector<string> belowTen = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
    vector<string> belowTwenty = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
    vector<string> belowHundred = { "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
    
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        return numberToWordsHelper(num);
    }
    
private:
    string numberToWordsHelper(int num) {
        if (num < 10) {
            return belowTen[num];
        }
        if (num < 20) {
            return belowTwenty[num - 10];
        }
        if (num < 100) {
            return belowHundred[num / 10] + (num % 10 != 0 ? " " + belowTen[num % 10] : "");
        }
        if (num < 1000) {
            return belowTen[num / 100] + " Hundred" + (num % 100 != 0 ? " " + numberToWordsHelper(num % 100) : "");
        }
        if (num < 1000000) {
            return numberToWordsHelper(num / 1000) + " Thousand" + (num % 1000 != 0 ? " " + numberToWordsHelper(num % 1000) : "");
        }
        if (num < 1000000000) {
            return numberToWordsHelper(num / 1000000) + " Million" + (num % 1000000 != 0 ? " " + numberToWordsHelper(num % 1000000) : "");
        }
        return numberToWordsHelper(num / 1000000000) + " Billion" + (num % 1000000000 != 0 ? " " + numberToWordsHelper(num % 1000000000) : "");
    }
};
/* Time Complexity (TC):
The function numberToWords recursively breaks down the input number by reducing it by factors of 10, 100, 1,000, 1,000,000, and 1,000,000,000.
•	Base Cases: For numbers less than 10, 20, 100, or 1,000, the function directly maps the number to a corresponding string. This takes constant time, O(1)O(1)O(1).
•	Recursive Calls:
o	For numbers greater than or equal to 1,000 but less than 1,000,000, the function recursively calls itself for num/1000 and num%1000. In the worst case, this involves breaking down the number into thousands, hundreds, tens, and units. This continues for millions and billions in a similar manner.
•	Overall Time Complexity:
o	Each recursive call reduces the problem size by a factor of 1,000 (e.g., millions → thousands → hundreds).
o	This leads to a logarithmic number of calls with respect to 1,000,000,000 (the largest possible input value).
Thus, the time complexity is approximately O(log⁡1000(num))O(\log_{1000}(num))O(log1000(num)). Since num is at most 231−12^{31}-1231−1, the worst-case time complexity is O(log⁡1000(231))O(\log_{1000}(2^{31}))O(log1000(231)), which simplifies to O(1)O(1)O(1) due to the relatively small number of divisions.
Space Complexity (SC):
•	Call Stack: The function is recursive, so the space complexity is affected by the depth of recursion. Each recursive call adds a new frame to the stack.
o	In the worst case (a number just below 1 billion), the function might recurse for billions, millions, thousands, and finally hundreds. This adds up to a constant depth of recursion (at most around 4 levels).
•	Additional Space: The function uses a few arrays to store the string representations of numbers, but these are of constant size, O(1)O(1)O(1).
Thus, the space complexity is O(log⁡1000(num))O(\log_{1000}(num))O(log1000(num)), but this too is effectively O(1)O(1)O(1) because the recursion depth is bounded.
Conclusion:
•	Time Complexity (TC): O(1)
•	Space Complexity (SC): O(1)

*/
