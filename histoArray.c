void histoArray(){

        TFile *ficheiro=new TFile("AmberTarget_Run_0.root", "READ");
        TFile *ficheirogravar=new TFile("Analise.root", "RECREATE");
        TTree *dados = (TTree*)ficheiro->Get("edep_Per_Event");

        Int_t nbins = 500;
        Double_t minBin = 0.0;
        Double_t maxBin = 400000;
	
	Int_t nHistos = 4;
        TH1D* histoDetetor[nHistos]; 
	TCanvas *canvas[nHistos];
	TString branchName;
	TString canvasName;

	for (Int_t i=0; i<nHistos; i++){
		TString histoName = "histoDetetor" + TString::Itoa(i,10);
		histoDetetor[i] = new TH1D(histoName,histoName,nbins,minBin,maxBin);
		branchName="detector"+TString::Itoa(i,10);
        	canvasName="canvas"+TString::Itoa(i,10);
		canvas[i] = new TCanvas(canvasName,canvasName);
		canvas[i]->SetLogy();
        	dados->Draw(branchName+">>"+histoName,branchName+">0");

		histoDetetor[i] -> SetTitle(branchName);
        	histoDetetor[i] -> Write();
	}
}
