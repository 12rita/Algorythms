#include "Header.h"
#include "Differential.h"

using namespace std;

int main()
{
	ofstream out("output.txt");
	ifstream in("input.txt");
	string s;

	try
	{
		if (!in.is_open())
			throw logic_error("no file!");
		while (getline(in, s))
		{

			Differential d;
			d.sinput(s);
			d.difer();
			//cout << "Get your derivative" << endl << d.soutput() << endl;
			//cout << "Input your function" << endl;
			out << d.soutput() << endl;
		}
	}
	catch (exception a)
	{
		out << a.what() << endl;
	}

	return 0;
	//system("pause");

}
