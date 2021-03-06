#include "Header.h"
#include "Differential.h"

using namespace std;

int main(int argc,char* argv[])
{
	ofstream out(argv[1]);
	ifstream in(argv[2]);
	string s;

	try
	{
		if (!in.is_open())
			throw logic_error("no file!");
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
	}
	catch (const exception& a)
	{
		out << a.what() << endl;
	}


	return 0;
	//system("pause");

}
