#include "plotTen.h"

#include <iostream>
#pragma comment(lib, "libmx.lib")
#pragma comment(lib, "libmex.lib")
#pragma comment(lib, "libeng.lib")
using namespace std;

void PlotTen::plot()
{
	double plottime[10]; // time for plot
	double plotprice[10]; // total value for plot
	for (int i = 0; i < 10; i++)
	{
		plotprice[i] = 0;
		plottime[i] = 0;
	}
	ifstream ifile("AccountInfo.txt");
	if (ifile.is_open())
	{
		char* delimiter = " ";
		char* nextToken = NULL;
		char * Token = NULL;
		string line;
		int count = 0;
		while (count < 10)
		{
			// have content
			if (getline(ifile, line))
			{
				if (!strcmp(line.c_str(), "AccountInfo")) // first line
				{
					continue; // jump first line
				}
				// get each word
				nextToken = NULL;
				Token = NULL;
				Token = strtok_s(const_cast<char*>(line.c_str()), delimiter, &nextToken); // get event
				Token = strtok_s(NULL, delimiter, &nextToken); // get amount								
				plotprice[count] = atof(Token);
				Token = strtok_s(NULL, delimiter, &nextToken); // get date
				plottime[count] = (double)atoi(Token);
				count++;
			}
			// end file
			else
			{
				ifile.close(); // close file
				break;
			}

		}
		for (int i = 0; i < 10; i++)
		{
			//cout << plotprice[i] << " " << plottime[i] << endl;
		}
	}
	else
	{
		cout << "open account info file error!" << endl;
	}


	Engine *ep;
	ep = engOpen(NULL);
	if (ep == NULL) {
		cout << "Error: Not Found" << endl;
		exit(1);
	}
	mxArray *A;
	A = mxCreateDoubleMatrix(1, 10, mxREAL);
	memcpy((void *)mxGetPr(A), (void *)plotprice, sizeof(double) * 10);
	engPutVariable(ep, "y", A);
	mxArray *B;
	B = mxCreateDoubleMatrix(1, 10, mxREAL);
	memcpy((void *)mxGetPr(B), (void *)plottime, sizeof(double) * 10);
	engPutVariable(ep, "x", B);
	engEvalString(ep, "plot(x,y)");
	system("pause");
	//clean operation
	mxDestroyArray(A);
	mxDestroyArray(B);
	engEvalString(ep, "close;");
	//close engine
	engClose(ep);
}