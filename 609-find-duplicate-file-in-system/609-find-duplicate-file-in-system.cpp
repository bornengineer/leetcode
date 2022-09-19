class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> res;
        for(auto s : paths){
            int dir_idx = s.find(" ");
            
            string dir = s.substr(0, dir_idx);
            s = s.substr(dir_idx+1);
            
            int cont_start;
            int cont_end;
            while(!s.empty()){
                cont_start = s.find("(") + 1;
                cont_end = s.find(")");
                string content = s.substr(cont_start, cont_end-cont_start+1);
                
                m[content].push_back(dir + "/" + s.substr(0, cont_start-1));
                
                // cout<<m[content][0]<<endl;
                
                if(cont_end+2 < s.size())s = s.substr(cont_end+2);
                else s = "";
                // cout<<content<<" "<<s<<endl;
            }
            // cout<<dir<<s<<endl;
        }
        for(auto i : m){
            vector<string> temp;
            if(i.second.size() > 1){
                for(auto x : i.second)temp.push_back(x);
            }
            if(temp.size()>0)res.push_back(temp);
        }
        
        return res;
    }
};