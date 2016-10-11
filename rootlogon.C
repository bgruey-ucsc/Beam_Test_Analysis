{
	int grid = 0;
	cout << endl << "\t Loading User Macros"<< endl;

	gROOT->LoadMacro("Define_Data_Cuts.C+");


	// Style Standards
	gStyle->SetOptFit(1111); // Place in the Fit Parameters and their errors when plotting.
//	gStyle->SetOptStat(0);
	gStyle->SetTitleFontSize(0.1);

	if( grid )
	{	
		gStyle->SetPadGridY(kTRUE);
		gStyle->SetPadGridX(kTRUE);
	}
	else
	{	
		gStyle->SetPadGridY(kFALSE);
		gStyle->SetPadGridX(kFALSE);
	}

	gStyle->SetMarkerStyle(6);
	gStyle->SetMarkerColor(kBlue);
	gStyle->SetLineColor(kRed);
	gROOT->ForceStyle();

	// July Data Scatter Plot Cuts
	char July_Scatter_Cut[] = "-83 < 2t0Max && 2t0Max < -80 && 20 < 2p0Max && 2p0Max < 110 && -82 < 3t0Max && 3t0Max < -78 && 50 < 3p0Max && 3p0Max < 110";

	char Nicolo_200_Ch1_cut[] = "(1t0Max-4cft0[20]) > -8.75e-4 * 1p0Max + 1.2 && 60 < 1p0Max && 1p0Max < 1185";
	char Nicolo_200_Ch2_cut[] = "(2t0Max-4cft0[20]) > -4.5e-4 * 2p0Max + 1.1 && 60 < 2p0Max && 2p0Max < 1185";
	char Nicolo_200_Ch3_cut[] = "(3t0Max-4cft0[20]) > -6.25e-4 * 3p0Max + 1.25 && 60 < 3p0Max && 3p0Max < 1185";

	char Nicolo_240_Ch2_cut[] = "-1.25 < 2t0Max && 2t0Max < -0.75 && 400 < 2p0Max && 2p0Max < 1300";

}
