/*
 * @lc app=leetcode id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        if(n < 1)
            return result;

        for(int i = 1; i <= n; i++){
            string s = "";
            if(i % 3 != 0 && i % 5 != 0)
                result.push_back(to_string(i));
            else{
                if(i % 3 == 0)
                    s += "Fizz";
                if(i % 5 == 0)
                    s += "Buzz";

                result.push_back(s);
            }
        }

        return result;
    }
};

