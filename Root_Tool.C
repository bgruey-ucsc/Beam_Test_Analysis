#include "headers.h"

void
Set_Canvas( TCanvas* c, char* title, char* x, char* y, char* name = "htemp")
{
	TH1F* h = (TH1F*)c->GetPrimitive( name );

	h->SetTitle( title );

	TAxis* axis = (TAxis*)h->GetXaxis();
	axis->SetTitle( x );
	axis = (TAxis*)h->GetYaxis();
	axis->SetTitle( y );

}


void
TH1_Gaus_Fit( TCanvas* c, char* name = "htemp" )
{
	TH1F* h = (TH1F*)c->GetPrimitive( name );
	h->Fit("gaus");
}
