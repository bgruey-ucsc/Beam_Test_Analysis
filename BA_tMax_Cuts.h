
/*
 *	Defines tMax cuts for a channe off raw data
 *
 *	Updates the tmax's
 */


void
BA_tMax_Cuts (TTree *tree, BA_t *cut)
{
	float *tmax = cut->tmax;
	int channel = cut->channel;

	char plot[512];
	char tmax_cut[512];
	int done = 0; /* bool to check our cuts are good */

	TCanvas* c = new TCanvas();
	
	sprintf (plot, "%dt0Max:%dp0Max", channel, channel);
	tmax_cut[0] = '\0';

	tree->Draw (plot, "");
	c->Update();

	printf("First we'll do a tMax cut.\n");

	while (!done)
	{
	
		printf ("What is the minimum tmax?\n");
		scanf ("%f", &tmax[0]);
		printf ("What is the maximum tmax?\n");
		scanf ("%f", &tmax[1]);
	
		sprintf(tmax_cut, "%f < %dt0Max && %dt0Max < %f"
			, tmax[0], channel, channel, tmax[1]);

		tree->Draw (plot, tmax_cut);
		c->Update();
		printf("Finished with the tMax cut?\n1 -> Yes, finished\n0 -> No, update\n");
		scanf ("%d", &done);
	} /* end while !done */

	delete c;
}
