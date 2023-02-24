#include <iostream>
#include <string> 

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(x==INT_MIN){//If input is -2^31 exactly, then return 0
            return 0;
        };
        bool negative=x<0;//Given number is negative or not
        x=(negative)?-1*x:x;//If given number negative, then do positive it.
        string s = "";//this string for concatenate reversed numbers.
		//Division iteration
        while(x/10>0){
            s+=to_string(x%10);//remainders
            x/=10;
        };
        s=s+to_string(x);
        if(negative){
            s="-"+s;
        }//
        if(stol(s)>INT_MAX || stol(s)<INT_MIN){//if result (reverse number) is bigger than int_max or smaller than int_min then return 0.
            return 0;
        };
        return stol(s);
    }
};

int main(){
    Solution sol;
   
    cout << "Input:4321, Output: " << sol.reverse(4321)<<"\n";
    cout << "Input:123, Output: " << sol.reverse(123)<<"\n";
    cout << "Input:-123, Output: " << sol.reverse(-123)<<"\n";
    cout << "Input:-2147483648, Output: " << sol.reverse(-2147483648)<<"\n";
    
    return 0;
}