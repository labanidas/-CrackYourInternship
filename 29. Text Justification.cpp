class Solution {
public:
    int umaxWidth;

    string getFinalLine(int i, int j, int eachWordSpace, int extraSpace,
                        vector<string>& words) {
        string s;

        for (int k = i; k < j; k++) {
            s += words[k];
            if (k == j - 1)
                continue;

            for (int space = 1; space <= eachWordSpace; space++)
                s += " ";
            if (extraSpace > 0) {
                s += " ";
                extraSpace--;
            }
        }

        while (s.length() < umaxWidth) {
            s += " ";
        }
        return s;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        umaxWidth = maxWidth;

        int i = 0;
        while (i < n) {
            int lettersCount = words[i].length();
            int j = i + 1;
            int spaceCount = 0;

            while (j < n && words[j].length() + 1 + lettersCount + spaceCount <=
                                umaxWidth) {
                lettersCount += words[j].length();
                spaceCount += 1;
                j++;
            }

            int remainingSlots = umaxWidth - lettersCount;

            int eachWordSpace =
                spaceCount == 0 ? 0 : remainingSlots / spaceCount;
            int extraSpace = spaceCount == 0 ? 0 : remainingSlots % spaceCount;

            if (j == n) {
                eachWordSpace = 1;
                extraSpace = 0;
            }
            result.push_back(
                getFinalLine(i, j, eachWordSpace, extraSpace, words));
            i = j;
        }
        return result;
    }
};
