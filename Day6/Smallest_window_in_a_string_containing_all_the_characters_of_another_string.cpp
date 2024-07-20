class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    bool containsAllCharacters(string& substr, string& pattern)
{
    int count[256] = { 0 };

    // Count the frequency of each character in the pattern
    for (char ch : pattern)
        count[ch]++;

    // For each character in the substring, decrement its
    // count
    for (char ch : substr) {
        if (count[ch] > 0)
            count[ch]--;
    }

    // If all counts in the count array are zero, the
    // substring contains all characters of the pattern
    for (int i = 0; i < 256; i++) {
        if (count[i] > 0)
            return false;
    }

    return true;
}

// Function to find the smallest substring containing all
// characters of the pattern
string findSmallestSubstring(string str, string pattern)
{
    int len_str = str.length();
    int len_pattern = pattern.length();
    string smallestSubstring = "";

    int minLength = INT_MAX;

    // Generate all substrings of the given string
    for (int i = 0; i < len_str; i++) {
        for (int j = i; j < len_str; j++) {
            string substr = str.substr(i, j - i + 1);

            // Check if the substring contains all
            // characters of the pattern
            if (containsAllCharacters(substr, pattern)) {
                int currentLength = substr.length();
              
                // Update the smallestSubstring if the
                // current substring is smaller
                if (currentLength < minLength) {
                    minLength = currentLength;
                    smallestSubstring = substr;
                }
            }
        }
    }

    return smallestSubstring;
}
};