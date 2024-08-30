class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> word_map;
        vector<vector<int>> result;
        int n = words.size();

        for (int i = 0; i < n; i++) {
            string reversed_str = words[i];
            reverse(reversed_str.begin(), reversed_str.end());
            word_map[reversed_str] = i;
        }

        for (int i = 0; i < n; i++) {
            string word = words[i];
            for (int j = 0; j <= word.size(); j++) {

                string prefix = word.substr(0, j);
                string suffix = word.substr(j);

                if (isPalindrome(prefix) &&
                    word_map.find(suffix) != word_map.end() &&
                    word_map[suffix] != i) {
                    result.push_back({word_map[suffix], i});
                }
                if (j != word.size() && isPalindrome(suffix) &&
                    word_map.find(prefix) != word_map.end() &&
                    word_map[prefix] != i) {
                    result.push_back({i, word_map[prefix]});
                }
            }
        }
        return result;
    }

    bool isPalindrome(const string& str) {
        int left = 0, right = str.size() - 1;
        while (left < right) {
            if (str[left] != str[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

/**
Let's walk through the code using dry runs with examples. This will help you
understand how the algorithm finds all palindrome pairs in the given list of
words.

### Example 1:
**Input:** `words = ["abcd", "dcba", "lls", "s", "sssll"]`

**Expected Output:** `[[0,1],[1,0],[3,2],[2,4]]`

### Step-by-Step Dry Run:

#### Initialization:
- We initialize an unordered map `word_map` to store the reverse of each word
along with its index.
- We initialize an empty vector `result` to store the pairs of indices that form
palindromes.

#### Step 1: Populate the `word_map` with reversed words.

1. For `i = 0`, word = "abcd"
   - Reverse of "abcd" is "dcba".
   - Store `word_map["dcba"] = 0`.

2. For `i = 1`, word = "dcba"
   - Reverse of "dcba" is "abcd".
   - Store `word_map["abcd"] = 1`.

3. For `i = 2`, word = "lls"
   - Reverse of "lls" is "sll".
   - Store `word_map["sll"] = 2`.

4. For `i = 3`, word = "s"
   - Reverse of "s" is "s".
   - Store `word_map["s"] = 3`.

5. For `i = 4`, word = "sssll"
   - Reverse of "sssll" is "llsss".
   - Store `word_map["llsss"] = 4`.

At this point, `word_map` looks like this:
```
{
  "dcba": 0,
  "abcd": 1,
  "sll": 2,
  "s": 3,
  "llsss": 4
}
```

#### Step 2: Find palindrome pairs by checking prefixes and suffixes.

**Iteration 1: Check word "abcd" (index 0):**
- Split the word into prefix and suffix:
  1. Prefix: "", Suffix: "abcd"
     - Check if `isPalindrome("")`: True (an empty string is a palindrome).
     - Check if `suffix "abcd"` exists in `word_map`: Yes (`word_map["abcd"] =
1`).
     - Add the pair `[1, 0]` to the result (because `abcd` + `dcba` = `abcddcba`
which is a palindrome).

  2. Prefix: "a", Suffix: "bcd"
     - Check if `isPalindrome("a")`: True.
     - Check if `suffix "bcd"` exists in `word_map`: No.

  3. Prefix: "ab", Suffix: "cd"
     - Check if `isPalindrome("ab")`: No.

  4. Prefix: "abc", Suffix: "d"
     - Check if `isPalindrome("abc")`: No.

  5. Prefix: "abcd", Suffix: ""
     - Check if `isPalindrome("abcd")`: No.

**Iteration 2: Check word "dcba" (index 1):**
- Split the word into prefix and suffix:
  1. Prefix: "", Suffix: "dcba"
     - Check if `isPalindrome("")`: True.
     - Check if `suffix "dcba"` exists in `word_map`: Yes (`word_map["dcba"] =
0`).
     - Add the pair `[0, 1]` to the result (because `dcba` + `abcd` = `dcbaabcd`
which is a palindrome).

  2. Prefix: "d", Suffix: "cba"
     - Check if `isPalindrome("d")`: True.
     - Check if `suffix "cba"` exists in `word_map`: No.

  3. Prefix: "dc", Suffix: "ba"
     - Check if `isPalindrome("dc")`: No.

  4. Prefix: "dcb", Suffix: "a"
     - Check if `isPalindrome("dcb")`: No.

  5. Prefix: "dcba", Suffix: ""
     - Check if `isPalindrome("dcba")`: No.

**Iteration 3: Check word "lls" (index 2):**
- Split the word into prefix and suffix:
  1. Prefix: "", Suffix: "lls"
     - Check if `isPalindrome("")`: True.
     - Check if `suffix "lls"` exists in `word_map`: No.

  2. Prefix: "l", Suffix: "ls"
     - Check if `isPalindrome("l")`: True.
     - Check if `suffix "ls"` exists in `word_map`: No.

  3. Prefix: "ll", Suffix: "s"
     - Check if `isPalindrome("ll")`: True.
     - Check if `suffix "s"` exists in `word_map`: Yes (`word_map["s"] = 3`).
     - Add the pair `[3, 2]` to the result (because `s` + `lls` = `slls` which
is a palindrome).

**Iteration 4: Check word "s" (index 3):**
- Split the word into prefix and suffix:
  1. Prefix: "", Suffix: "s"
     - Check if `isPalindrome("")`: True.
     - Check if `suffix "s"` exists in `word_map`: Yes (`word_map["s"] = 3` but
it's the same index).

  2. Prefix: "s", Suffix: ""
     - Check if `isPalindrome("s")`: True.
     - Check if `prefix ""` exists in `word_map`: No.

**Iteration 5: Check word "sssll" (index 4):**
- Split the word into prefix and suffix:
  1. Prefix: "", Suffix: "sssll"
     - Check if `isPalindrome("")`: True.
     - Check if `suffix "sssll"` exists in `word_map`: No.

  2. Prefix: "s", Suffix: "ssll"
     - Check if `isPalindrome("s")`: True.
     - Check if `suffix "ssll"` exists in `word_map`: No.

  3. Prefix: "ss", Suffix: "sll"
     - Check if `isPalindrome("ss")`: True.
     - Check if `suffix "sll"` exists in `word_map`: Yes (`word_map["sll"] =
2`).
     - Add the pair `[2, 4]` to the result (because `lls` + `sssll` = `llssssll`
which is a palindrome).

  4. Prefix: "sss", Suffix: "ll"
     - Check if `isPalindrome("sss")`: True.
     - Check if `suffix "ll"` exists in `word_map`: No.

  5. Prefix: "sssl", Suffix: "l"
     - Check if `isPalindrome("sssl")`: No.

#### Final Output:
The pairs found are:
```
[[1, 0], [0, 1], [3, 2], [2, 4]]
```
This matches the expected output.

### Example 2:
**Input:** `words = ["bat", "tab", "cat"]`

**Expected Output:** `[[0,1],[1,0]]`

#### Dry Run:

1. Populate `word_map`:
   - "bat" reversed is "tab" → `word_map["tab"] = 0`.
   - "tab" reversed is "bat" → `word_map["bat"] = 1`.
   - "cat" reversed is "tac" → `word_map["tac"] = 2`.

2. Iterate over the words:
   - For "bat":
     - Prefix: "", Suffix: "bat" → `word_map["bat"] = 1` → Add `[1, 0]`.
   - For "tab":
     - Prefix: "", Suffix: "tab" → `word_map["tab"] = 0` → Add `[0, 1]`.

3. Output:
```
[[1, 0], [0, 1]]
```

### Summary:
- The algorithm checks each word by splitting it into possible prefixes and
suffixes, and uses the hash map to efficiently find matching reversed strings
that form palindromes.
- The palindrome pairs are returned as a list of index pairs.

I hope this dry run clarifies how the algorithm works!

**/
