#include <iostream>
#include <string> 
using namespace std;

class Solution {
public:
    string breakPalindrome(string palindrome) {
    int length = palindrome.length();
    //it is for checking if the length of input is in the range between 1 and 1000
    if (1 < length && length <= 1000) { 
        //For loop to check is there any 'a' char in half of string.
        //If there isn't, replaces the first non-a element of the string.(It breaks a Palindrome)
        for (int i = 0; i < (length / 2); i++) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        //this is for spesific cases like 'aaaa','aba','aca' etc.
        //it puts an 'b'^at the end of the string.And it breaks a palindrome.
        palindrome[length-1] = 'b';
        return palindrome;
        }
        return "";
    }
};

int main(){
    Solution sol;
    cout << "Input:abcba , Output: " << sol.breakPalindrome("abccba")<<"\n";
    cout << "Input:a , Output: " << sol.breakPalindrome("a")<<"\n";
    cout << "Input:bcaacb , Output: " << sol.breakPalindrome("bcaacb")<<"\n";
    cout << "Input:aca , Output: " << sol.breakPalindrome("aca")<<"\n";
    cout << "Input:cbc , Output: " << sol.breakPalindrome("cbc")<<"\n";
    cout << "Input:aaa , Output: " << sol.breakPalindrome("aaa")<<"\n";
    

    return 0;
}