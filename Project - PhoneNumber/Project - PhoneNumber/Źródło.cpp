#include <iostream>
#include <string>


using namespace std;

string number(string S) {
	// write your code in C++14 (g++ 6.2.0)

	int size = S.size();
	string N[100];
	int k = 0;

	for (int i = 0; i < size; i++)
	{
		if (isdigit(S[i]))
		{
			N[k] = S[i];
			k++;
		}
	}

	string solution;

	if (k % 3 == 0)
	{
		for (int i = 0; i <= k; i++)
		{
			if (i == k - 3)
			{
				solution = solution + N[i] + N[i + 1] + N[i + 2];
				i += 4;
			}
			else
			{
				solution = solution + N[i] + N[i + 1] + N[i + 2] + "-";
				i += 2;
			}
		}
	}
	if (k % 3 == 1)
	{
		for (int i = 0; i <= k; i++)
		{
			if (i == k - 4)
			{
				solution = solution + N[i] + N[i + 1] + "-" + N[i + 2] + N[i + 3];
				i += 4;
			}
			else
			{
				solution = solution + N[i] + N[i + 1] + N[i + 2] + "-";
				i += 2;
			}
		}
	}
	if (k % 3 == 2)
	{
		for (int i = 0; i <= k; i++)
		{
			if (i == k - 2)
			{
				solution = solution + N[i] + N[i + 1];
				i += 2;
			}
			else
			{
				solution = solution + N[i] + N[i + 1] + N[i + 2] + "-";
				i += 2;
			}
		}
	}

	cout << "\n" << solution << "\n";

	return solution;
}

int main()
{	
	number("555372654");
	system("PAUSE");
	return 0;
}