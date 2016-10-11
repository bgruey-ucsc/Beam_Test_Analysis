

#include "headers.h"

TGraph *
h_graph(double val, double xmin, double xmax)
{
	double x[100];
	double y[100];
	double step = 0.01 * (xmax - xmin);
	for (int i = 0; i < 100; i++)
	{
		x[i] = xmin + step * ((double)i);
		y[i] = val;
	}
	return new TGraph(100, x, y);
}

TGraph *
v_graph(double val, double ymin, double ymax)
{
	double x[100];
	double y[100];
	double step = 0.01 * (ymax - ymin);
	for (int i = 0; i < 100; i++)
	{
		y[i] = ymin + step * ((double)i);
		x[i] = val;
	}
	return new TGraph(100, x, y);
}
