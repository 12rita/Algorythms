#include "Differential.h"
#include "Header.h"
using namespace std;


Differential::~Differential()
{
}

Differential::Differential()
{
	input = "empty";
	output = "unknown";
	count = 0;
}

void Differential::sinput(string s)
{
	input = s;
	if ((input[0] == '-') && (input[1] == '-'))
	{
		input.erase(0, 2);
	}
}

string Differential::soutput()
{
	return output;
}

string Differential::mult(string s, string s1)
{
	

	if (s.find('x') == s.npos)
		if (s1.find('x') == s1.npos)
			return("0");
		else
			return (s + '*' + dif(s1));
	else
		if (s1.find('x') == s1.npos)
			return (dif(s) + '*' + s1);
		else
			
			return('('+dif(s) + ")*" + s1 + "+" + '(' + dif(s1) + ')' + "*" + s);
}

string Differential::div(string s, string s1)
{
	if (s.find('x') == s.npos)
		if (s1.find('x') == s1.npos)
			return ("0");
		else
			return ('-' + dif(s1) + '*' + s + '/' + s1 + "^2");
	else
		if (s1.find('x') == s1.npos)
			return (dif(s) + '/' + s1);
		else
			return ("(" + dif(s) + '*' + s1 + '-' + dif(s1) + '*' + s + ")/" + dif(s1) + "^2");
}

string Differential::pow(string s, string s1)
{
	if (s.find('x') == s.npos)
	{
		if (s1.find('x') == s1.npos)
		{
			return ("0");
		}
		else
		{
			if (s == "e")
			{
				return ('(' + s + '^' + s1 + ")*(" + dif(s1) + ')');
			}
			return ('(' + s + '^' + s1 + "*ln(" + s + "))" + "*(" + dif(s1) + ')');
		}

	}
	else
	{
		if (s1.find('x') == s1.npos)
		{
			
			return ('(' + s1 + '*' + s + "^(" + s1 + "-1))*" + '(' + dif(s) + ')');
		}
		else
		{
			string s2 = "ln(" + s + ')';
			return ("1/(" + mult(s1, s2) + ')');
		}
	}
}

string Differential::logariphm(string s, string s1)
{
	if (s == s1)
	{
		return ("0");
	}
	else
	{

		if (s.find('x') == s.npos)
		{
			if (s1.find('x') == s1.npos)
			{
				return ("0");
			}
			else
			{
				return ("1/(" + s1 + "*ln(" + s + ")*(" + dif(s1) + ')');
			}

		}
		else
		{
			if (s1.find('x') == s1.npos)
			{
				return ("-1/(log(" + s1 + ',' + s + "))^2*(" + logariphm(s1, s) + ')');
			}
			else
			{
				string s2 = "ln(" + s + ')';
				s = "ln(" + s1 + ')';
				return ("1/(" + div(s, s2) + ')');
			}
		}
	}
}

string Differential::flog(string s, int a)
{
	string s1 = "";
	string s2 = "";

	if (s[a + 1] == 'n')
	{
		s2 = s.substr(a + 3);
		s2.erase(s2.end() - 1);
		s1 = "1/(" + s2 + ")*(" + dif(s2) + ')';
		return s1;
	}
	else if (s[a + 1] == 'o')
	{
		if (s.find(',') == s.npos)
			throw exception("incorrect input");
		else
		{
			int k = 0;
			for (auto i = a; i < s.size(); i++)
			{
				if (s[i] == '(')
					k++;
				else if (s[i] == ')')
					k--;
				if ((k == 1) && (s[i] == ','))
				{
					s1 = s.substr(a + 4, i - 4 - a);
					s2 = s.substr(i + 1);
					s2.erase(s2.end() - 1);

					return logariphm(s1, s2);
				}
			}
		}
	}
	return "error";
}

string Differential::fcos(string s, int a)
{
	string s1 = s.substr(a + 4);
	s1.erase(s1.end() - 1);
	return ("-sin(" + s1 + ')' + "*(" + dif(s1) + ')');
}

string Differential::fsin(string s, int a)
{
	string s1 = s.substr(a + 4);
	s1.erase(s1.end() - 1);
	return ("cos(" + s1 + ')' + "*(" + dif(s1) + ')');
}

string Differential::ftg(string s, int a)
{
	string s1 = s.substr(a + 3);
	s1.erase(s1.end() - 1);
	return ("1/(cos(" + s1 + "))^2" + "*(" + dif(s1) + ')');
}

string Differential::fctg(string s, int a)
{
	string s1 = s.substr(a + 4);
	s1.erase(s1.end() - 1);
	return ("-1/(sin(" + s1 + "))^2" + "*(" + dif(s1) + ')');
}

string Differential::farccos(string s, int a)
{
	string s1 = s.substr(a + 7);
	s1.erase(s1.end() - 1);
	return ("-1/(1-(" + s1 + ")^2)^(1/2)" + "*(" + dif(s1) + ')');
}

string Differential::farcsin(string s, int a)
{
	string s1 = s.substr(a + 7);
	s1.erase(s1.end() - 1);
	return ("1/(1-(" + s1 + ")^2)^(1/2)" + "*(" + dif(s1) + ')');
}

string Differential::farctg(string s, int a)
{
	string s1 = s.substr(a + 6);
	s1.erase(s1.end() - 1);
	return ("1/(1+(" + s1 + ")^2)" + "*(" + dif(s1) + ')');
}

string Differential::farcctg(string s, int a)
{
	string s1 = s.substr(a + 7);
	s1.erase(s1.end() - 1);
	return ("-1/(1+(" + s1 + ")^2)" + "*(" + dif(s1) + ')');
}

string Differential::dif(string s)
{
	vector<int> pm;
	vector<int> mul;
	vector<int> di;
	vector<int> po;
	vector<int> lo;
	vector<int> cos;
	vector<int> sin;
	vector<int> tg;
	vector<int> ctg;
	vector<int> arcsin;
	vector<int> arccos;
	vector<int> arctg;
	vector<int> arcctg;
	count++;
	int k = 0;

	if (s == "x")
	{
		return ("1");
	}

	if (s.find('x') == s.npos)
	{
		return ("0");
	}

	for (auto i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
			k++;
		else if (s[i] == ')')
			k--;
		if (k == 0)
		{
			if ((s[i] == '+') || (s[i] == '-'))
				pm.push_back(i);

			else if (s[i] == '*')
				mul.push_back(i);

			else if (s[i] == '/')
				di.push_back(i);

			else if (s[i] == '^')
				po.push_back(i);

			else if ((s[i] == 'c') && (s[i + 1] == 'o') && (s[i + 2] == 's'))
				if ((i == 0) || (s[i - 1] != 'c'))
					cos.push_back(i);

			else if ((s[i] == 's') && (s[i + 1] == 'i') && (s[i + 2] == 'n'))
				if ((i == 0) || (s[i - 1] != 'c'))
					sin.push_back(i);

			else if ((s[i] == 't') && (s[i + 1] == 'g'))
				if ((i == 0) || (s[i - 1] != 'c'))
					tg.push_back(i);

			else if ((s[i] == 'c') && (s[i + 1] == 't') && (s[i + 2] == 'g'))
				if ((i == 0) || ((s[i - 1] != 'c') && (s[i - 1] != 'r')))
					ctg.push_back(i);

			else if (((s[i] == 'l') && (s[i + 1] == 'o') && (s[i + 2] == 'g')) || ((s[i] == 'l') && (s[i + 1] == 'n')))
				lo.push_back(i);

			else if ((s[i] == 'a') && (s[i + 1] == 'r') && (s[i + 2] == 'c') && (s[i + 3] == 'c') && (s[i + 4] == 'o') && (s[i + 5] == 's'))
				arccos.push_back(i);

			else if ((s[i] == 'a') && (s[i + 1] == 'r') && (s[i + 2] == 'c') && (s[i + 3] == 's') && (s[i + 4] == 'i') && (s[i + 5] == 'n'))
				arcsin.push_back(i);

			else if ((s[i] == 'a') && (s[i + 1] == 'r') && (s[i + 2] == 'c') && (s[i + 3] == 't') && (s[i + 4] == 'g'))
				arctg.push_back(i);

			else if ((s[i] == 'a') && (s[i + 1] == 'r') && (s[i + 2] == 'c') && (s[i + 3] == 'c') && (s[i + 4] == 't') && (s[i + 5] == 'g'))
				arcctg.push_back(i);
		}
	}
	//opredelytor

	if (k != 0)
	{
		throw exception("incorrect input");
	}

	{
		if (!pm.empty())
		{
			string s1 = "";
			if (pm[0] == 0)
			{
				pm.erase(pm.begin());
				s1 = s[0];
				return (s1 + dif(s.substr(1)));
			}

			s1 = dif(s.substr(0, pm[0]));
			for (auto i = 0; i < pm.size() - 1; i++)
			{
				s1 = s1 + s[pm[i]] + dif(s.substr(pm[i] + 1, pm[i + 1] - pm[i] - 1));
			}
			s1 = s1 + s[pm[pm.size() - 1]] + dif(s.substr(pm[pm.size() - 1] + 1));
			return (s1);
		}

		else if (!mul.empty())
			return mult(s.substr(0, mul[0]), s.substr(mul[0] + 1));

		else if (!di.empty())
			return div(s.substr(0, di[0]), s.substr(di[0] + 1));

		else if (!po.empty())
			return pow(s.substr(0, po[0]), s.substr(po[0] + 1));

		else if (!lo.empty())
			return flog(s, lo[0]);

		else if (!cos.empty())
			return fcos(s, cos[0]);

		else if (!sin.empty())
			return fsin(s, sin[0]);

		else if (!tg.empty())
			return ftg(s, tg[0]);

		else if (!ctg.empty())
			return fctg(s, ctg[0]);

		else if (!arccos.empty())
			return farccos(s, arccos[0]);

		else if (!arcsin.empty())
			return farcsin(s, arcsin[0]);

		else if (!arctg.empty())
			return farctg(s, arctg[0]);

		else if (!arcctg.empty())
			return farcctg(s, arcctg[0]);
	}
	//functions of dif

	if ((s.front() == '(') && (s.back() == ')'))
	{
		s.erase(s.end() - 1);
		s.erase(s.begin());
		return dif(s);
	}

	if (s == input)
	{
		throw exception("incorrect input");
	}

	return "error";

}

void Differential::difer()
{
	output = dif(input);
	handling();//bugs
}

void Differential::handling()
{
	while (output.find("*(1)") != output.npos)
	{
		output.erase(output.find("*(1)"), 4);
	}
	while (output.find("(1)*") != output.npos)
	{
		output.erase(output.find("(1)*"), 4);
	}
	while (output.find("1*") != output.npos)
	{
		output.erase(output.find("1*"), 2);
	}
	while (output.find("*1") != output.npos)
	{
		output.erase(output.find("*1"), 2);
	}

	while (output.find("+-") != output.npos)
	{
		output.replace(output.find("+-"), 2, "-");
	}
	while (output.find("-+") != output.npos)
	{
		output.replace(output.find("-+"), 2, "-");
	}
	while (output.find("--") != output.npos)
	{
		output.replace(output.find("--"), 2, "+");
	}
	while ((output.find("0") != output.npos) && (output[0] != '0'))
	{
		if (output[output.find("0") + 1] == '+')
			output.erase(output.find("0")-1, 3);
		else
			output.erase(output.find("0")-1, 2);
	}
	while (((output[0] == '0') || (output[0] == '+')) && (output != "0"))
	{
		output.erase(0, 1);
	}
	while (output.back() == '-')
	{
		output.pop_back();
	}
}