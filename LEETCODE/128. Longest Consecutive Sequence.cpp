//link https://leetcode.com/problems/longest-consecutive-sequence/

//checking for each element longest sequence
class Solution {
public:
    int longestConsecutive(vector<int>& vector) {
        
    unordered_map<int, bool> map;
    int max=0, count=0, start=0;
    int n = vector.size();
    for (int i=0; i<n; i++){
        if(map.find(vector[i]) == map.end()){
            map[vector[i]] = false;
        }
    }

    for(auto it = map.begin(); it!=map.end(); it++){
        if((*it).second == false){
            bool b = true;
            int i= (*it).first;
            count =0;
            while(b){
                if(map.find(i) !=map.end()){
                    count++;
                    map[i] = true;
                    i++;
                }else{
                    b = false;
                }
            b=true;
            i = (*it).first -1;
            while(b){
                if(map.find(i) !=map.end()){
                    count++;
                    map[i] = true;
                    i--;
                }else{
                    b = false;
                }
            }

            if(count>max){
                max = count;
                start =(*it).first;
            }
        }
    }
}

        return  max;
    }
};