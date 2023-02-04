#include <iostream>
#include <string> 
#include <vector> 
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string output;
        vector<string>v(numRows, ""); 
        int sections=numRows*2-2;//making sections for zig-zag pattern
        int ct=0;//counter for 
        bool bIncrement=true;
        if(numRows>1){
            for (int i = 0; i < s.length(); i++) {
                //This condition determines where the counter should increase or decrease.
                if(i!=0 && i%(numRows-1)==0){
                    bIncrement=false;
                }
                if(i%sections==0){
                    bIncrement=true;
                }//
                v[ct]+=s.at(i);//appends char to vector of string
                //Increment or decrement part to make zigzag pattern.
                if(bIncrement==true){
                    ct++;
                }
                else{
                    ct--;
                }//
            }
        }
        else{//if numRows<=1 return input string directly.
            return s;
        } 
        //This part for making Vector to String.
        for(auto &it : v) output += it;
        return output;
    }
};

class AltSolution {//Alternative Solution to Memory Save
public:
    string convert(string s, int numRows) {
        string output;
        int sections=numRows*2-2;//making sections for zig-zag pattern
        int ct=0;//counter for search every characters for each row
        //For loop to search for each row
        for (int i = 0; i < numRows; i++) {
            //For loop to find characters in row
            for (int i = 0; i < s.length(); i++) {
                if(numRows > 1){
                    //this selects the row where all the characters should belong
                    if(i%sections==sections-ct || i%sections==ct){
                        output+=s.at(i);
                    }
                }
                else{
                    return s;
                }
            }ct++;
        }
        return output;
    }
};

int main(){
    Solution sol;
   
    cout << "Input:PAYPALISHIRING, numRows:3 Output: " << sol.convert("PAYPALISHIRING",3)<<"\n";
    cout << "Input:PAYPALISHIRING, numRows:4 Output: " << sol.convert("PAYPALISHIRING",4)<<"\n";
    cout << "Input:A, numRows:1 Output: " << sol.convert("A",1)<<"\n";
    cout << "Input:PAYPALISHIRING, numRows:6 Output: " << sol.convert("PAYPALISHIRING",6)<<"\n";
    
    /* ALTERNATIVE WAY
    AltSolution alternative;
    cout << "Input:PAYPALISHIRING, numRows:3 Output: " << alternative.convert("PAYPALISHIRING",3)<<"\n";
    cout << "Input:PAYPALISHIRING, numRows:4 Output: " << alternative.convert("PAYPALISHIRING",4)<<"\n";
    cout << "Input:A, numRows:1 Output: " << alternative.convert("A",1)<<"\n";
    cout << "Input:PAYPALISHIRING, numRows:6 Output: " << alternative.convert("PAYPALISHIRING",6)<<"\n";
    */
    return 0;
}