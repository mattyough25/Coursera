// Palindrome
// Matthew Yough
// 25 January 2022



template<typename Bidirectional>
bool isPalindrome(Bidirectional first, Bidirectional last)
{
	while(true) //infinite loop
	{
		last--;
		if(first == last)
		{
			break;
		}
		if(*first != *last)
		{
			return false;
		}
		first++
		if(first == last)
		{
			break
		}
	}
	return true;
}