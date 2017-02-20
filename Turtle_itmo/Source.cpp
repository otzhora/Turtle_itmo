#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;




int main()
{
	ifstream in("turtle.in");
	ofstream out("turtle.out");

	int h, w;
	in >> h >> w;

	vector< vector<int> >  field(h, vector<int>(w));
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			in >> field[i][j];

	for (int i = h - 1; i >= 0; --i)
		for (int j = 0; j < w; j++)
		{
			if (i < h - 1 && j > 0)
			{
				field[i][j] += max(field[i + 1][j], field[i][j - 1]);
			}
			else if (i == h - 1 && j > 0)
			{
				field[i][j] += field[i][j - 1];
			}
			else if (j == 0 && i < h - 1)
			{
				field[i][j] += field[i + 1][j];
			}
		}

	/*for (int i = 0; i < h; i++)
	{
	for (int j = 0; j < w; j++)
	out << field[i][j] << " ";
	out << endl;
	}*/
	out << field[0][w - 1];
}