#include "Header.h"
#include "Differential.h"

using namespace std;

int main()
{
	ifstream test("test.txt");
	string tin;
	while (test >> tin)
	{
		ofstream out(tin + ".out");
		ifstream in(tin + ".in");
		string s;
		if (!in.is_open())
		{
			out << "no file";
		}
		else
			while (getline(in, s))
			{

				try
				{
					Differential d;
					d.sinput(s);
					d.difer();
					//cout << "Get your derivative" << endl << d.soutput() << endl;
					//cout << "Input your function" << endl;
					out << d.soutput() << endl;
				}
				catch (const exception& a)

				{
					out << a.what() << endl;
				}
			}
		out.close();
		in.close();
	}
	return 0;
	//system("pause");
}
