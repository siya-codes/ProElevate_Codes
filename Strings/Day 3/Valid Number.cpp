class Solution {
public:
    bool isNumber(string s) {
        int n = s.length();
        int i = 0, j = n - 1;

        // Skip leading spaces
        while (i < n && s[i] == ' ') i++;

        // Skip trailing spaces
        while (j >= 0 && s[j] == ' ') j--;

        // If the trimmed section is empty, return false
        if (i > j) return false;

        bool numberSeen = false, eSeen = false, decimalSeen = false;

        for (int k = i; k <= j; ++k) {
            char c = s[k];

            switch (c) {
                case '.':
                    if (decimalSeen || eSeen) return false;
                    decimalSeen = true;
                    break;
                case 'e':
                case 'E':
                    if (eSeen || !numberSeen) return false;
                    eSeen = true;
                    numberSeen = false; // reset for checking number after 'e'
                    break;
                case '+':
                case '-':
                    // Sign is valid only at the start or just after 'e'
                    if (k != i && s[k-1] != 'e' && s[k-1] != 'E') return false;
                    numberSeen = false; // reset to ensure a number follows
                    break;
                default:
                    if (!isdigit(c)) return false;
                    numberSeen = true;
            }
        }

        return numberSeen;
    }
};
//TC= o(n)
//sc=o(1)
