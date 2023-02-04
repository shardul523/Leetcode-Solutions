# How to approach this problem

- The first thing that comes to mind is to _check if string s2 contains all the characters of string s1_, i.e, the frequency / occurrence count of each character in s2 must be greater than or equal to the corresponding character count in s1. This seems to work for example 1.

- However this approach fails, as can be seen in example 2, because the characters of the permutation must be present together.

- So to deal with this additional constraint of the characters being together, instead of checking the entire string s2 at once, we instead _check each of the substring of s2 which has a length equal to s1_.

- Taking equal length substring ensures that characters being checked are all huddled together and we can then check if a given substring has occurrence count of characters equal to that of s1.

- We perform the same check for all the substrings of s2.

&nbsp;
&nbsp;

# Solution

## Brute Force :

The brute force approach checks for each of the substrings of length k (k = lenght of string s1) by taking the substrings starting from index 0 all the way to the substrings starting at index n - k - 1.
<br>
<br>
**Time Complexity** : _O(nk)_

**Space Complexity** : _O(1)_

&nbsp;

## Better Approach (Using sliding window)

Instead of checking for each of the substring again and again, we need to think of the reason we are taking the substrings in the first place - _to count the occurring frequency of each of characters in a given substring_.

\n
So first let's count the frequencies of the first k characters. This represents the frequency count of the substring starting from index 0.

\n
Check if the frequency count of the initial window is equal to the frequency count of s1. If found, then return true.

\n
If not then we slide the window forward by  decrementing the frequency of the character at the beginning of the window, essentially removing it, whilst we take the next character into the sliding window by incrementing it's frequency count.

\n
Check if this new frequency count is equal to that of string s1. If yes, return true, else repeat the above step all the way until we reach the last character of string s2.

\n
If no windows ( and hence the substrings ) have a frequency count equal to s1, no permutation of s1 exists in s2. Hence return false.
