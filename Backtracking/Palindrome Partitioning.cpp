class Solution {
public:
    void solve(string s,vector<string>temp, vector<vector<string>>& res)
    {
        if(s.size()==0)
            res.push_back(temp);
        
        for(int i=0;i<s.size();i++)
        {
            string str=s.substr(0,i+1);
            
            if(check(str))
            {
                temp.push_back(str);
                solve(s.substr(i+1),temp,res);
                temp.pop_back();
            }
        }
    }
    
    bool check(string s)
    {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=s[s.size()-1-i])
                return false;
        }
        
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>temp;
        
        solve(s,temp,res);
        return res;
    }
};