#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string>

using namespace std;

/*
 * Given a string S, find the longest palindromic substring in S.
 * 
 * Dynamic programming solution, O(N^2) time and O(N^2) space:
 * To improve over the brute force solution from a DP approach,
 * first think how we can avoid unnecessary re-computation in 
 * validating palindromes. Consider the case “ababa”. If we 
 * already knew that “bab” is a palindrome, it is obvious 
 * that “ababa” must be a palindrome since the two left and 
 * right end letters are the same.
 * 
 * Stated more formally below:
 * Define P[ i, j ] ← true iff the substring Si … Sj is a palindrome, otherwise false.
 * 
 * Therefore,
 * P[ i, j ] ← ( P[ i+1, j-1 ] and Si = Sj )
 * 
 * The base cases are:
 * P[ i, i ] ← true
 * P[ i, i+1 ] ← ( Si = Si+1 )
 * 
 * This yields a straight forward DP solution, which we first
 * initialize the one and two letters palindromes, and work 
 * our way up finding all three letters palindromes, and so on… 
 * */

//DP Solution
string longestPalindromeDP(string s)
{
	int n = s.length();
	
	if(0 == n)
		return "";
	
	int nLongestBegin = 0;
	int maxLen = 1;
	
	//array store status
	bool table[2000][2000] = {false};
	
	//only one char, is palindrome
	for(int i = 0; i < n; ++i)
		table[i][i] = true;
		
	//if neighbor chars are same, the two char string is palindrome
	for(int i = 0; i < n-1; ++i)
	{
		if(s[i] == s[i+1])
		{
			table[i][i+1] = true;
			nLongestBegin = i;
			maxLen = 2;
		}
	}
	
	//based on the above, find the longest palindrome
	for(int len = 3; len <= n; ++len)
	{
		for(int i = 0; i < n-len+1; ++i)
		{
			int j = i+len-1;
			if(s[i] == s[j]
			&& table[i+1][j-1])
			{
				table[i][j] = true;
				nLongestBegin = i;
				maxLen = len;
			}
		}
	}
	
	return s.substr(nLongestBegin, maxLen);
}


/*
 * A simpler approach, O(N^2) time and O(1) space:
 * In fact, we could solve it in O(N^2) time without any extra space.
 * We observe that a palindrome mirrors around its center. Therefore,
 * a palindrome can be expanded from its center, and there are only 
 * 2N-1 such centers.
 * 
 * You might be asking why there are 2N-1 but not N centers? The
 * reason is the center of a palindrome can be in between two letters.
 * Such palindromes have even number of letters (such as “abba”) and 
 * its center are between the two ‘b’s.
 * 
 * Since expanding a palindrome around its center could take O(N) time,
 * the overall complexity is O(N^2).
 * */
 
 string findAroundCenter(string s, int c1, int c2)
 {
	 int nl = c1, nr = c2;
	 int nLen = s.length();
	 while(nl >= 0 && nr < nLen && s[nl] == s[nr])
	 {
		 nl--;
		 nr++;
	 }
	 
	 return s.substr(nl+1, nr-nl-1);
 }
 
 string longestPalindromeSimple(string s)
 {
	 int nLen = s.length();
	 if(0 == nLen)
		 return "";
		 
	 string strLongest = s.substr(0, 1);
	 
	 for(int i = 0; i < nLen-1; ++i)
	 {
		 string str1 = findAroundCenter(s, i, i);
		 if(str1.length() > strLongest.length())
			 strLongest = str1;
			 
	     string str2 = findAroundCenter(s, i, i+1);
		 if(str2.length() > strLongest.length())
			 strLongest = str2;
	 }
	 
	 return strLongest;
 }


int main()
{
	string strSrc = "Fourscoreandsevenyearsagoourfaathersbroughtforthonthisconta\
inentanewnationconceivedinzLibertyanddedicatedtotheproposit\
ionthatallmenarecreatedequalNowweareengagedinagreahtcivilwa\
rtestingwhetherthatnaptionoranynartionsoconceivedandsodedic\
atedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWeh\
avecometodedicpateaportionofthatfieldasafinalrestingplacefo\
rthosewhoheregavetheirlivesthatthatnationmightliveItisaltog\
etherfangandproperthatweshoulddothisButinalargersensewecann\
otdedicatewecannotconsecratewecannothallowthisgroundThebrav\
elmenlivinganddeadwhostruggledherehaveconsecrateditfarabove\
ourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorl\
ongrememberwhatwesayherebutitcanneverforgetwhattheydidhereI\
tisforusthelivingrathertobededicatedheretotheulnfinishedwor\
kwhichtheywhofoughtherehavethusfarsonoblyadvancedItisrather\
forustobeherededicatedtothegreattdafskremainingbeforeusthat\
fromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwh\
ichtheygavethelastpfullmeasureofdevotionthatweherehighlyres\
olvethatthesedeadshallnothavediedinvainthatthisnationunsder\
Godshallhaveanewbirthoffreedomandthatgovernmentofthepeopleb\
ythepeopleforthepeopleshallnotperishfromtheearth";
	printf("The original string is %s\n", strSrc.c_str());
	
	//string strLongestPalindrome = longestPalindromeDP(strSrc);
	string strLongestPalindrome = longestPalindromeSimple(strSrc);
	
	if(strLongestPalindrome.empty())
		printf("The string have not palindrome substring!\n");
	else
		printf("The longest palindrome substring is: %s\n", strLongestPalindrome.c_str());
	
	return 0;
}