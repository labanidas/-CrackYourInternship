class Solution
{
    public:
    vector<int> search(string pattern, string text) {
        vector<int> result;
        int n = text.length();
        int m = pattern.length();
        int d = 256;  // Number of characters in the input alphabet
        int q = 101;  // A prime number
        int h = 1;    // The value of d^(m-1)
        int p = 0;    // Hash value for pattern
        int t = 0;    // Hash value for text

        // Calculate the value of h
        for (int i = 0; i < m-1; i++)
            h = (h * d) % q;

        // Calculate the hash value of pattern and first window of text
        for (int i = 0; i < m; i++) {
            p = (d * p + pattern[i]) % q;
            t = (d * t + text[i]) % q;
        }

        // Slide the pattern over text one by one
        for (int i = 0; i <= n - m; i++) {
            // If the hash values match, then only check for characters one by one
            if (p == t) {
                bool flag = true;
                for (int j = 0; j < m; j++) {
                    if (text[i + j] != pattern[j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    result.push_back(i + 1);  // Store the 1-based index
            }

            // Calculate hash value for the next window of text
            if (i < n - m) {
                t = (d * (t - text[i] * h) + text[i + m]) % q;

                // We might get a negative value of t, converting it to positive
                if (t < 0)
                    t = (t + q);
            }
        }

        return result;
    }
     
};
