#include <iomanip>

struct strawtubes{
    UInt_t fUniqueID;
    UInt_t fBits;
    FairMultiLinkedData* fLink;
    Int_t fTrackID;
    UInt_t fEventId;
    Double32_t fPx;
    Double32_t fPy;
    Double32_t fPz;
    Double32_t fTime;
    Double32_t fLength;
    Double32_t fELoss;
    Int_t fDetectorID;
    Double32_t fX;
    Double32_t fY;
    Double32_t fZ;
    Int_t fPdgCode;
    Double_t fdist2Wire;
};

void Comparison()
{
    TFile *sample = new TFile("new_sample.root");
    TFile *data = new TFile("ship.conical.MuonBack-TGeant4.root");
    sample_strawtubes_tree = (TTree*) sample->Get("cbmsim");
    data_strawtubes_tree = (TTree*) data->Get("cbmsim");
    strawtubes Strawtubes_data;
    strawtubes Strawtubes_sample;
    
    sample_strawtubes_tree->SetBranchAddress("strawtubesPoint",&Strawtubes_sample);
    data_strawtubes_tree->SetBranchAddress("strawtubesPoint",&Strawtubes_data);
    
    sample_strawtubes_tree->GetEntry(0);
    data_strawtubes_tree->GetEntry(0);
    
    cout<<setw(20)<<"sample: "<<setw(20)<<"data:"<<endl;
    cout<<setw(20)<<Strawtubes_sample.fUniqueID<<setw(20)<<Strawtubes_data.fUniqueID<<endl;
    cout<<setw(20)<<Strawtubes_sample.fBits<<setw(20)<<Strawtubes_data.fBits<<endl;
    cout<<setw(20)<<Strawtubes_sample.fTrackID<<setw(20)<<Strawtubes_data.fTrackID<<endl;
    cout<<setw(20)<<Strawtubes_sample.fEventId<<setw(20)<<Strawtubes_data.fEventId<<endl;
    cout<<setw(20)<<Strawtubes_sample.fPx<<setw(20)<<Strawtubes_data.fPx<<endl;
    cout<<setw(20)<<Strawtubes_sample.fPy<<setw(20)<<Strawtubes_data.fPy<<endl;
    cout<<setw(20)<<Strawtubes_sample.fPz<<setw(20)<<Strawtubes_data.fPz<<endl;
    cout<<setw(20)<<Strawtubes_sample.fTime<<setw(20)<<Strawtubes_data.fTime<<endl;
    cout<<setw(20)<<Strawtubes_sample.fLength<<setw(20)<<Strawtubes_data.fLength<<endl;
    cout<<setw(20)<<Strawtubes_sample.fELoss<<setw(20)<<Strawtubes_data.fELoss<<endl;
    cout<<setw(20)<<Strawtubes_sample.fDetectorID<<setw(20)<<Strawtubes_data.fDetectorID<<endl;
    cout<<setw(20)<<Strawtubes_sample.fX<<setw(20)<<Strawtubes_data.fX<<endl;
    cout<<setw(20)<<Strawtubes_sample.fY<<setw(20)<<Strawtubes_data.fY<<endl;
    cout<<setw(20)<<Strawtubes_sample.fZ<<setw(20)<<Strawtubes_data.fZ<<endl;
    cout<<setw(20)<<Strawtubes_sample.fPdgCode<<setw(20)<<Strawtubes_data.fPdgCode<<endl;
    cout<<setw(20)<<Strawtubes_sample.fdist2Wire<<setw(20)<<Strawtubes_data.fdist2Wire<<endl;    
}
