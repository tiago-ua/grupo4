void Detector_0(){

	TFile * ficheiro= new TFile("AmberTarget_Run_0.root","READ");
	TFile * ficheiroGravar= new TFile("Analise.root","RECREATE");
	TTree * dados= (TTree*)  ficheiro -> Get("tracksData");

	Double_t detector0;
	Double_t detector1;
	Double_t detector2;
	Double_t detector3;
	Int_t PDG;

	Double_t Soma;

	dados->SetBranchAddress("EdepDet0_keV",&detector0);
	dados->SetBranchAddress("EdepDet1_keV",&detector1);
	dados->SetBranchAddress("EdepDet2_keV",&detector2);
	dados->SetBranchAddress("EdepDet3_keV",&detector3);
	dados->SetBranchAddress("particlePDG",&PDG);

	Long64_t  N = dados-> GetEntries();

	TTree* newTree = new TTree("newTree","newTree");
	newTree -> Branch("Soma", &Soma, "Soma/D");
	newTree->Branch("particlePDG",&PDG,"PGD/I");

	for (Int_t i=0; i< N; i++){
		dados->GetEntry(i);
		Soma=detector0+detector1+detector2+detector3;
		newTree -> Fill();
		
	} 
	//newTree->Scan();
	newTree -> Write();

}
