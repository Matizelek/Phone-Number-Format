#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>


using namespace std;

void initMenuBox()
{
	cout << "Choose task: \n";
	cout << "1. Enter a number \n";
	cout << "2. See egsamples \n";
	cout << "3. Exit \n";
}

bool isRight(string error_msg)
{
	if (cin.rdstate())
	{
		cin.clear();
		cin.rdstate();
		cin.ignore(1024, '\n');

		system("cls");
		initMenuBox();
		cout << error_msg;
		return false;
	}
	return true;
}

bool isRight()
{
	if (cin.rdstate())
	{
		cin.clear();
		cin.rdstate();
		cin.ignore(1024, '\n');

		system("cls");
		initMenuBox();
		return false;
	}
	return true;
}

string formatNumber(string S) {

	int size = S.size();
	string N[100], solution, str;
	int k = 0;


	S.erase(remove(S.begin(), S.end(), ' '), S.end());

	cout << "Without Spaces :" << S << "\n";
	
	size = S.size(); //becouse size changed after remove;

	for (int i = 0; i < size; i++) //shearching for digits
	{
		if (isdigit(S[i]))
		{
			N[k] = S[i];
			k++;
		}
	}

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
	cout << "\n" << solution << "\n\n\n";
	return solution;
}



void menuDecision(int decision)
{
	system("cls");
	initMenuBox();
	string number;

	switch (decision)
	{
	case 1:
		cout << "Type the number You want to format: " << "\n";
		do (cin >> number); while (!isRight("Something wrong ! \nTry again: \n"));
		formatNumber(number);
		break;
	case 2:
		cout << "EGSAMPLES: " << "\n";
		cout << "EG. 1: " << "\n \t" << "11-55  67 9494 2039" <<"\n";
		number = "11-55  67 9494 2039";
		formatNumber(number);

		cout << "EG. 2: " << "\n \t" << "1 - 74 2109--263" << "\n";
		number = "1 - 74 2109--263";
		formatNumber(number);

		cout << "EG. 3: " << "\n \t" << "92384290" << "\n";
		number = "923842920";
		formatNumber(number);
		break;
	case 3:
		system("exit");
		break;
	default:
		cout << "This shouldn't happend \n";
	}
}



int main()
{	
	int chosen;
	do
	{
		system("cls");
		initMenuBox();

		while (!(cin >> chosen))
		{ 
		cin.clear();
		cin.ignore(1024, '\n');

		system("cls");
		initMenuBox();
		cout << "Somethings wrong!" << "\n";
		}
		menuDecision(chosen);
		system("pause");
	

	} while (chosen != 3);

	return 0;
}