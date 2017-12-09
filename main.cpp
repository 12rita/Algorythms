
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

class Differential
{
private:
	string input, output;
	ifstream in;
	ofstream out;

public:
	Differential()
	{
		input = "empty";
		output = "unknown";
	}
	void sinput(string s)
	{
		input = s;
		if ((input[0]=='-')&&(input[1]=='-'))
        {
            input.erase(0,2);
        }
	}
	string soutput()
	{
		return output;
	}

	string mult(string s, string s1)
	{
		if (s.find('x') == s.npos)
		{
			if (s1.find('x') == s1.npos)
			{
				return("0");
			}
			else
			{
				return (s + '*' + dif(s1));
			}
		}
		else
		{
			if (s1.find('x') == s1.npos)
			{
				return (dif(s) + '*' + s1);
			}
			else
			{
				return(dif(s) + '*' + s1 + '+' + '(' + dif(s1) + ')' + '*' + s);
			}


		}
	}
	string div(string s, string s1)
	{
		if (s.find('x') == s.npos)
		{
			if (s1.find('x') == s1.npos)
			{
				return ("0");
			}
			else
			{
				return ('-' + dif(s1) + '*' + s + '/' + s1 + "^2");
			}
		}
		else
		{
			if (s1.find('x') == s1.npos)
			{
				return (dif(s) + '/' + s1);
			}
			else
			{
				return ("(" + dif(s) + '*' + s1 + '-' + dif(s1) + '*' + s + ")/" + dif(s1) + "^2");
			}
		}
	}
	string pow(string s, string s1)
	{
		if (s.find('x') == s.npos)
		{
			if (s1.find('x') == s1.npos)
			{
				return ("0");
			}
			else
			{
				return ('(' + s + '^' + s1 + "*ln(" + s + "))" + "*(" + dif(s1) + ')');
			}

		}
		else
		{
			if (s1.find('x') == s1.npos)
			{
				return ('(' + s1 + '*' + s + "^(" + s1 + "-1)*" + '(' + dif(s) + ')');
			}
			else
			{
				string s2 = "log(e," + s + ')';
				return ("1/(" + mult(s1, s2) + ')');
			}
		}
	}
	string logariphm(string s, string s1)
	{
	    if(s==s1)
        {
            return ("1");
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
				return ("1/(" + s1 + "ln(" + s + ")*(" + dif(s1) + ')');
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
				string s2 = "log(e," + s + ')';
				s = "log(e," + s1 + ')';
				return ("1/(" + div(s, s2) + ')');
			}
		}
        }
	}
	string  dif(string s)
	{
		vector<int>pm;
		vector<int>mul;
		vector<int>di;
		vector <int>po;
		vector <int>lo;
		vector <int>cos;
		vector <int>sin;
		vector <int>tg;
		vector <int>ctg;
		vector <int>arcsin;
		vector <int>arccos;
		vector <int>arctg;
		vector <int>arcctg;

		int k = 0;

		if ((s.front() == '(') && (s.back() == ')'))
		{
			s.erase(s.end() - 1);
			s.erase(s.begin());
		}
		if (s == "x")
		{
			return ("1");
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
				{
					pm.push_back(i);
				}
				else if (s[i] == '*')
				{
					mul.push_back(i);
				}
				else if (s[i] == '/')
				{
					di.push_back(i);
				}
				else if (s[i] == '^')
				{
					po.push_back(i);
				}
				else if ((s[i] == 'c') && (s[i + 1] == 'o') && (s[i + 2] == 's'))
				{
					if ((i == 0)|| (s[i - 1] != 'c'))
						cos.push_back(i);

				}
				else if ((s[i] == 's') && (s[i + 1] == 'i') && (s[i + 2] == 'n'))
				{
					if ((i == 0) || (s[i - 1] != 'c'))
					sin.push_back(i);
				}
				else if ((s[i] == 't') && (s[i + 1] == 'g'))
				{
					if ((i == 0) || (s[i - 1] != 'c'))
					tg.push_back(i);
				}
				else if ((s[i] == 'c') && (s[i + 1] == 't') && (s[i + 2] == 'g'))
				{
					if ((i == 0) || ((s[i - 1] != 'c')&&(s[i - 1] != 'r')))
					ctg.push_back(i);
				}
				else if (((s[i] == 'l') && (s[i + 1] == 'o') && (s[i + 2] == 'g'))||((s[i] == 'l') && (s[i + 1] == 'n')))
				{
					lo.push_back(i);

				}
				else if ((s[i] == 'a') && (s[i + 1] == 'r') && (s[i + 2] == 'c') && (s[i + 3] == 'c') && (s[i + 4] == 'o') && (s[i + 5] == 's'))
				{
					arccos.push_back(i);
				}
				else if ((s[i] == 'a') && (s[i + 1] == 'r') && (s[i + 2] == 'c') && (s[i + 3] == 's') && (s[i + 4] == 'i') && (s[i + 5] == 'n'))
				{
					arcsin.push_back(i);
				}
				else if ((s[i] == 'a') && (s[i + 1] == 'r') && (s[i + 2] == 'c') && (s[i + 3] == 't') && (s[i + 4] == 'g'))
				{
					arctg.push_back(i);
				}
				else if ((s[i] == 'a') && (s[i + 1] == 'r') && (s[i + 2] == 'c') && (s[i + 3] == 'c') && (s[i + 4] == 't') && (s[i + 5] == 'g'))
				{
					arcctg.push_back(i);
				}

			}

		}
		if (k != 0)
		{
			return ("Incorrect input");
		}
		if (s.find('x') == s.npos)
		{
			return ("0");
		}
		if (!pm.empty())
		{
			string s1 = "";
			s1 = dif(s.substr(0, pm[0]));

			for (auto i = 0; i < pm.size() - 1; i++)
			{
				s1 = s1 + s[pm[i]] + dif(s.substr(pm[i] + 1, pm[i + 1] - pm[i] - 1));
			}
			s1 = s1 + s[pm[pm.size() - 1]] + dif(s.substr(pm[pm.size() - 1] + 1));
			return (s1);
		}
		else if (!mul.empty())
		{
			string s1 = "";
			// s1='('+dif(s.substr(0, mul[0]))+")*"+s.substr(mul[0]+1)+'+'+s.substr(0, mul[0])+"*("+dif(s.substr(mul[0]+1))+')';
			s1 = mult(s.substr(0, mul[0]), s.substr(mul[0] + 1));
			return (s1);

		}
		else if (!di.empty())
		{
			string s1 = "";
			s1 = div(s.substr(0, di[0]), s.substr(di[0] + 1));
			return (s1);
		}
		else if (!po.empty())
		{
			string s1 = "";
			s1 = pow(s.substr(0, po[0]), s.substr(po[0] + 1));
			return (s1);
		}
		else if (!lo.empty())
		{
			string s1 = "";
			string s2 = "";
			if (s[lo[0]+1]=='n')
            {
                s2=s.substr(lo[0] + 3);
                s2.erase(s2.end()-1);
                s1="1/("+s2+")*(" + dif(s2) +')';
            }
            else if (s[lo[0]+1]=='o')
            {
                    for (auto i = lo[0]; i < s.size(); i++)
                    {
                        if (s[i] == '(')
                            k++;
                        else if (s[i] == ')')
                            k--;
                        if ((k == 1) && (s[i] == ','))
                        {
                            s1 = s.substr(lo[0] + 4, i - 4 - lo[0]);
                            s2 = s.substr(i + 1);
                            s2.erase(s2.end() - 1);

                            return(logariphm(s1, s2));
                        }
                        else
                        {
                            return ("incorrect input");
                        }
                    }

            }
			return(s1);

		}

		else if (!cos.empty())
		{
			string s1 = "";
			s1 = s.substr(cos[0] + 4);
			s1.erase(s1.end() - 1);
			return ("-sin(" + s1 + ')' + "*(" + dif(s1) + ')');
		}
		else if (!sin.empty())
		{
			string s1 = "";
			s1 = s.substr(sin[0] + 4);
			s1.erase(s1.end() - 1);
			return ("cos(" + s1 + ')' + "*(" + dif(s1) + ')');
		}
		else if (!tg.empty())
		{
			string s1 = "";
			s1 = s.substr(tg[0] + 3);
			s1.erase(s1.end() - 1);
			return ("1/(cos(" + s1 + "))^2" + "*(" + dif(s1) + ')');
		}

		else if (!ctg.empty())
		{
			string s1 = "";
			s1 = s.substr(ctg[0] + 4);
			s1.erase(s1.end() - 1);
			return ("-1/(sin(" + s1 + "))^2" + "*(" + dif(s1) + ')');
		}
		else if (!arccos.empty())
		{
			string s1 = "";
			s1 = s.substr(arccos[0] + 7);
			s1.erase(s1.end() - 1);
			return ("-1/(1-(" + s1 + ")^2)^(1/2)" + "*(" + dif(s1) + ')');
		}
		else if (!arcsin.empty())
		{
			string s1 = "";
			s1 = s.substr(arcsin[0] + 7);
			s1.erase(s1.end() - 1);
			return ("1/(1-(" + s1 + ")^2)^(1/2)" + "*(" + dif(s1) + ')');
		}
		else if (!arctg.empty())
		{
			string s1 = "";
			s1 = s.substr(arctg[0] + 6);
			s1.erase(s1.end() - 1);
			return ("1/(1+(" + s1 + ")^2)" + "*(" + dif(s1) + ')');
		}
		else if (!arcctg.empty())
		{
			string s1 = "";
			s1 = s.substr(arcctg[0] + 7);
			s1.erase(s1.end() - 1);
			return ("-1/(1+(" + s1 + ")^2)" + "*(" + dif(s1) + ')');
		}

		if (s == input)
		{
			return ("incorrect input");
		}

	}

	void difer()
	{
		output = dif(input);
		handling();
    }
    void handling()
    {
         while (output.find("*(1)")!=output.npos)
        {
            output.erase(output.find("*(1)"), 4);
        }
        while (output.find("*(0)")!=output.npos)
        {
            output=="0";
        }
        while (output.find("+-")!=output.npos)
        {
            output.replace(output.find("+-"),2,"-");
        }
        while (output.find("-+")!=output.npos)
        {
            output.replace(output.find("-+"),2,"-");
        }
        while (output.find("--")!=output.npos)
        {
            output.replace(output.find("--"),2,"+");
        }
        while ((output.find("0")!=output.npos)&&(output[0]!='0'))
        {
            if (output[output.find("0")+1]!='-')
            output.erase(output.find("0"),2);
            else
            output.erase(output.find("0"),1);
        }
         while  ((output[0]=='0')||(output[0]=='+'))
        {
            output.erase(0,1);
        }



  }
};

int main()
{
	string s;
	cout << "Input your function" << endl;
	while (getline(cin, s))
	{
		Differential d;
		d.sinput(s);
		d.difer();
		cout << "Get your derivative" << endl << d.soutput() << endl;
		cout << "Input your function" << endl;

	}
	return 0;
//	system("pause");

}
