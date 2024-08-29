class Solution {
public:
    int calculate(string s) {
        int total = 0;        
        int num_curr = 0;   
        int num_last = 0;      
        char operation = '+'; 

        for (int i = 0; i < s.length(); i++) {
            char char_curr = s[i];
            // agar curr char number hai toh use num me add karte hai 
            if (isdigit(char_curr)) {
                num_curr = (num_curr * 10) + (char_curr - '0');
            }
            // agar curr chat operator hai ya last character hai toh operation
            // perform karo
            if (!isdigit(char_curr) && !isspace(char_curr) ||
                i == s.length() - 1) {
                if (operation == '+' || operation == '-') {
                    total += num_last;
                    num_last = (operation == '+') ? num_curr : -num_curr;
                } else if (operation == '*') {
                    num_last = num_last * num_curr;
                } else if (operation == '/') {
                    num_last = num_last / num_curr;
                }
                operation = char_curr;
                num_curr = 0;
            }
        }
        total += num_last;
        return total;
    }
};
/* Time Complexity (TC)
The algorithm processes each character in the string exactly once, using a single pass through the string.
The operations within the loop (checking if a character is a digit, updating variables, etc.) are constant time operations, i.e., 
O(1).
Hence, the overall time complexity is O(n), where 
n is the length of the string.
Space Complexity (SC)
The space used by the algorithm is primarily for a few integer variables (total, num_curr, num_last, operation). These do not depend on the size of the input string.
Therefore, the space complexity is O(1), as it requires a constant amount of space regardless of the input size.*/

