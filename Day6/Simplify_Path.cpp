class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dir,ans_vec;
        /*
        The following split metod was taken from https://www.javatpoint.com/how-to-split-strings-in-cpp
        Program3.cpp Please refer this for more details.
        */
        string T; // temp string to hold split value.
        stringstream x(path);
        while(getline(x, T, '/')){
            dir.push_back(T);
        }
        string ans = "";
        for(int i=0;i<dir.size();i++){
            if(dir[i]==".."){
                if(ans_vec.size()>0) // this is a fail check if we are on root directory then we can't move to previous dir.
                    ans_vec.pop_back();
            }else if(dir[i]=="."){
                // stay on the current directory
            }else{
                if(dir[i]!="") // in case we have "//" where split method will return ""(emptyString) in this case we won't be putting it in our ans_vec.
                    ans_vec.push_back(dir[i]);
            }
        }
        for(int i=0;i<ans_vec.size();i++){
            // join all the remaining dir with '/'.
            ans += "/"+ans_vec[i];
        }
        // incase we don't have anything present in ans_dir then we'll simply return root directory.
        if(ans=="") ans = "/";
        return ans;
    }
};