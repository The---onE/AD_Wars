#include "Global.h"

void setSize(Node* s, float size)
{
	s->setScale(DATUM*size / s->getContentSize().height);
}

int randNum(int size, int probability[])
{
	int sum = 0;
	for (int i = 0; i < size; ++i)
	{
		sum += probability[i];
	}
	float r = rand_0_1()*sum;

	sum = 0;
	for (int i = 0; i < size; ++i)
	{
		sum += probability[i];
		if (r < sum)
		{
			return i;
		}
	}
	return -1;
}

int pow10(int x)
{
	int t = 1;
	for (int i = 0; i < x; ++i)
		t *= 10;
	return t;
}

int stdStoI(string s)
{
	if (s.empty())
		return ERROR_STRING;

	if (s[0] == '-')
		return -stdStoI(string(s.begin() + 1, s.end()));

	int num = 0, temp = s.length() - 1;

	for (string::iterator i = s.begin(); i < s.end(); ++i, --temp)
	{
		if (*i<'0' || *i>'9')
		{
			return ERROR_STRING;
		}
		else
		{
			int x = *i - '0';
			num += x * pow10(temp);
		}
	}

	return num;
}

string stdItoS(int x)
{
	if (x < 0)
		return "-" + stdItoS(-x);
	else if (x == 0)
		return "0";
	string temp, str;
	while (x != 0)
	{
		temp += x % 10 + '0';
		x /= 10;
	}
	for (string::iterator i = temp.end() - 1; i >= temp.begin(); --i)
		str += *i;
	return str;
}