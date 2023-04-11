#include <iostream>
#include <string>
using namespace std;
bool isValidRoman(string temp)
{
	int l = temp.length();
	int i = 0;
	bool status = true;
	if (l > 15)
	{
		status = false;
		return status;
	}
	else
	{
		status = true;
	}
	while (i < l)
	{
		if (temp[i] != 'I' && temp[i] != 'V' && temp[i] != 'X' && temp[i] != 'L' && temp[i] != 'C' && temp[i] != 'D' && temp[i] != 'M')
		{
			status = false;
			return status;
		}
		else
		{
			status = true;
		}
		i++;
	}
	return status;
}
int getValue(char a)
{
	if (a == 'I')
		return 1;
	else if (a == 'V')
		return 5;
	else if (a == 'X')
		return 10;
	else if (a == 'L')
		return 50;
	else if (a == 'C')
		return 100;
	else if (a == 'D')
		return 500;
	else
		return 1000;
}
int getCombination(string com, int sIndex)
{
		string a;
		a = com[sIndex];
		a = a + com[sIndex + 1];
		if (a == "IV")
			return 4;
		else if (a == "IX")
			return 9;
		else if (a == "XL")
			return 40;
		else if (a == "XC")
			return 90;
		else if (a == "CD")
			return 400;
		else if (a == "CM")
			return 900;
		else
			return -1;

}
int getInteger()
{
	string roman;
	cout << "Enter a roman number: ";
	cin >> roman;
	int l = roman.length();
	int sum = 0;
	if (!isValidRoman(roman))
	{
		cout << "Error: Not a valid roman number: ";
		exit(0);
	}
	else
	{
		for (int i = 0; i < l; i++)
		{
			if (getCombination(roman, i) == -1)
			{
				sum = sum + getValue(roman[i]);
			}
			else
			{
				sum = sum + getCombination(roman, i);
				i++;
			}
				
		}
	}
	return sum;
}
//string getRoman()
//{
//	
//}
int main()
{
	cout << getInteger() << endl;
	return 0;
}