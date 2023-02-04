#include <string>
#include <vector>
using namespace std;



bool checkInclusion(string s1, string s2) {


    /* If string s1 has a length greater than s2, 
    then it is not possible for s2 to include s1 or it's permutation */
    if (s1.length() > s2.length()) 
        return false;
    
    //  Creating a window to check the substrings of s2 in linear time
    int window_length = s1.length();
    vector<int> count_s1(26, 0);  //  Counting the occurrence of each char in s1
    vector<int> count_window(26, 0);  //  Counting the occurrence of each char in window


    //  Counting the occurrences of string s1 and the initial substring window
    for (int i = 0; i < window_length; i++) {
        count_s1[s1[i] - 'a']++;
        count_window[s2[i] - 'a']++;
    }


    //  If the permutation is found at the beginning of string s2
    if (count_s1 == count_window)
        return true;


    //  Checking all the other substrings occurrence count by sliding the window 
    for (int i = window_length; i < s2.length(); i++) {
        char removed_char = s2[i - window_length];
        count_window[removed_char - 'a']--;  //  Removing the first char from the window
        count_window[s2[i] - 'a']++;  //  Adding the next char at the end of the window
        if (count_s1 == count_window)  // If current substring is a permutation or not
            return true;
    }

    //  Coming here means no permutation was found in s2
    return false;
}