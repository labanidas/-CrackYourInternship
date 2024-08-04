class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        stringstream ss(path);
        string token;

        // step 1 -- eliminate '..' using stack
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".")
                continue;

            else if (token == "..") {
                if (!st.empty())
                    st.pop_back();
            } else
                st.push_back(token);
        }

        // step 2 -- simple  
        string result = "/";
        for (int i = 0; i < st.size(); i++) {
            result += st[i];
            if(i < st.size()-1)  result += "/";
        }
       

        return result;
    }
};
