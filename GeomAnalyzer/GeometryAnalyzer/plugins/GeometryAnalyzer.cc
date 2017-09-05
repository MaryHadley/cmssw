// -*- C++ -*-
//
// Package:    GeomAnalyzer/GeometryAnalyzer
// Class:      GeometryAnalyzer
// 
/**\class GeometryAnalyzer GeometryAnalyzer.cc GeomAnalyzer/GeometryAnalyzer/plugins/GeometryAnalyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Mary Hill Hadley
//         Created:  Tue, 05 Sep 2017 12:54:43 GMT
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/TrackerCommon/interface/TrackerTopology.h"
#include "Geometry/Records/interface/TrackerTopologyRcd.h"
#include "FWCore/Framework/interface/ESHandle.h"

//
// class declaration
//

// If the analyzer does not use TFileService, please remove
// the template argument to the base class so the class inherits
// from  edm::one::EDAnalyzer<> and also remove the line from
// constructor "usesResource("TFileService");"
// This will improve performance in multithreaded jobs.

class GeometryAnalyzer : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
   public:
      explicit GeometryAnalyzer(const edm::ParameterSet&);
      ~GeometryAnalyzer();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;

      // ----------member data ---------------------------
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
GeometryAnalyzer::GeometryAnalyzer(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed
   usesResource("TFileService");

}
//edm::ESHandle tTopoHandle;
//iSetup.get().get(tTopoHandle);
//const TrackerTopology* const tTopo = tTopoHandle.product();
//typedef std::vector DetIdContainer;
//edm::ESHandle geo;
//iSetup.get().get(geo);
//std::string DetIdPrint;
//DetIdContainer allIds=geo->detIds();
//for( DetIdContainer::const_iterator id = allIds.begin(), detUnitIdEnd = allIds.end(); id != detUnitIdEnd; ++id ) {
  //  if ( id->det()==DetId::Tracker ) {
    //    unsigned int subdet=id->subdetId();

GeometryAnalyzer::~GeometryAnalyzer()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
GeometryAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;



#ifdef THIS_IS_AN_EVENT_EXAMPLE
   Handle<ExampleData> pIn;
   iEvent.getByLabel("example",pIn);
#endif
   
#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
#endif
edm::ESHandle<TrackerGeometry> tTopoHandle;
iSetup.get().get(tTopoHandle);
const TrackerTopology* const tTopo = tTopoHandle.product();
typedef std::vector DetIdContainer;
edm::ESHandle geo;
iSetup.get().get(geo);
std::string DetIdPrint;
DetIdContainer allIds=geo->detIds();
for( DetIdContainer::const_iterator id = allIds.begin(), detUnitIdEnd = allIds.end(); id != detUnitIdEnd; ++id ) {
    if ( id->det()==DetId::Tracker ) {
        unsigned int subdet=id->subdetId();}
        tTopo->Print(subdet);
        }
    } 
}
// ------------ method called once each job just before starting event loop  ------------
void 
GeometryAnalyzer::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
GeometryAnalyzer::endJob() 
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
GeometryAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(GeometryAnalyzer);
