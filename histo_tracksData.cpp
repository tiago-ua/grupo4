void histo_tracksData(){
    TFile *ficheiro=new TFile("AmberTarget_Run_0.root","READ");
    TFile *ficheiroGravar=new TFile("Analise.root","RECREATE");
    TTree *dados=(TTree*)ficheiro->Get("tracksData");

    Int_t nBins=300;
    Double_t minBin=0.0;
    Double_t maxBin=600;

    Int_t nHistos=4;
    TH1D* histoDetetor[nHistos];
    TCanvas *canvas[nHistos];
    TString branchName;
    TString canvasName;

    //TArray color = ["kRed", "kBlue", "kGreen", "kBlack"];

    THStack *hs = new THStack("hs","Stacked 1D histograms");
        

    for (Int_t i=0;i<nHistos; i++){
        TString histoName="histoDetetor"+TString::Itoa(i,10);
        histoDetetor[i]=new TH1D(histoName, histoName, nBins, minBin, maxBin);
        branchName="EdepDet"+TString::Itoa(i,10)+"_keV";
        //canvasName="canvas"+TString::Itoa(i,10);

        histoDetetor[i]->SetFillColor(i);
        dados->Draw(branchName+">>"+histoName,branchName+">0","goff");
        histoDetetor[i]->SetTitle(histoName);
        histoDetetor[i]->Write();        
        hs->Add(histoDetetor[i]);
        
    }
    hs->Draw("Nostack");	
    hs->SetTitle("Tracks Data");
}



