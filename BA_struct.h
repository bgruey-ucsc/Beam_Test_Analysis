
#include <string.h>


#ifndef BEAM_ANALYSIS_STRUCT

typedef struct {

	int channel;
	int average;
	int gain; /* gain events? Use 1. No gain? Use 0 */

	/* Booleans to ignore undefined cuts */
	int tmax_b;
	int pmax_b;
	int split_b;

	float tmax[2];
	float pmax[2];
	float gain_m;
	float gain_b;

} BA_t;


void
BA_clear (BA_t *cut)
{
	cut->tmax_b = 0;
	cut->pmax_b = 0;
	cut->split_b = 0;

	cut->channel = 0;
	cut->average = 0;
	cut->gain = 0;

	cut->tmax[0] = 0.0;
	cut->tmax[1] = 0.0;
	cut->pmax[0] = 0.0;
	cut->pmax[1] = 0.0;
	
	cut->gain_m = 0.0;
	cut->gain_b = 0.0;
}

char *
Get_BA_str (BA_t *cut)
{
	char pmax[512];
	pmax[0] = '\0';
	char tmax[512];
	tmax[0] = '\0';
	char split[512];
	split[0] = '\0';

	if (cut->tmax_b)
	sprintf (tmax, "%f < %dt%dMax && %dt%dMax < %f"
		, cut->tmax[0], cut->channel, cut->average, cut->channel, cut->average, cut->tmax[1]);
	if (cut->pmax_b)
	sprintf (pmax, "%f < %dp%dMax && %dp%dMax < %f"
		, cut->pmax[0], cut->channel, cut->average, cut->channel, cut->average, cut->pmax[1]);

	if (cut->split_b)
	{
		if (cut->gain)
			sprintf (split, "%dt%dMax > %f * %dp%dMax + %f", cut->channel, cut->average
				, cut->gain_m, cut->channel, cut->average, cut->gain_b);
		else
			sprintf (split, "%dt%dMax < %f * %dp%dMax + %f", cut->channel, cut->average
				, cut->gain_m, cut->channel, cut->average, cut->gain_b);
	}

	char *ret = (char*)calloc( strlen (pmax) + strlen (tmax) + strlen (split) + 1, sizeof (char));

	strcpy (ret, tmax);
	strcat (ret, pmax);
	strcat (ret, split);

	return ret;
}

#endif
