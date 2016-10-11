#include "Beam_Analysis_lib.h"

#define NUM_CH 4
#define CHANNELS {1, 2, 3, 4}

void
Define_Data_Cuts(TTree *tree)
{
	int channels[] = CHANNELS;
	int num_ch = NUM_CH;

	BA_t **cuts = (BA_t**)calloc (num_ch, sizeof(BA_t*));
	for (int i = 0; i < num_ch; i++)
	{
		cuts[i] = (BA_t*)calloc (num_ch, sizeof(BA_t));
		BA_clear (cuts[i]);
		cuts[i]->channel = channels[i];
		cuts[i]->average = 0;
	}


	for (int i = 0; i < num_ch; i++)
		BA_tMax_Cuts(tree, cuts[i]);	

	char* check = Get_BA_str (cuts[0]);
	printf("%s", check);
}
