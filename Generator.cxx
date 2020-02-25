//////////////////////////////////////////////
//
// Author : Samuel Meehan <samuel.meehan@cern.ch>
//
// Description : This is a toy monte carlo generator to simulate the
// two-body decay of a massive particle with a mass of 15 GeV and a width of 3 GeV
// assuming it is a Gaussian.  It will print the event kinematics of the two
// outgoing particles.
//
//////////////////////////////////////////////

#include <iostream>
#include <random> // HINT : You may need to include a header to use random stuff in c++

#include <FourVector> // HINT : You may need to include a header to give access to the FourVector class

// start tools for generating Gaussian random numbers
std::default_random_engine generator;
std::normal_distribution<double> gen_mass(15.0,3.0);
std::uniform_real_distribution<double> gen_esplit(0.2,0.7);
std::uniform_real_distribution<double> gen_theta(0.0,M_PI);
std::uniform_real_distribution<double> gen_phi(0.0,2*M_PI);

// function prototype for the generation of a single event kinematics
void GenEvent(FourVector *v1, FourVector *v2);

int main(int argc, char *argv[]){

  std::cout<<"STARTING"<<std::endl;

  if(argc==1){
    std::cout<<"Must give me a number of events - exitting"<<std::endl;
    return 11;
  }
  
  int nevents = std::atoi(argv[1]);
  std::cout<<"Generating NEvents : "<<nevents<<std::endl;
  
  // define the two four vectors from the decay
  FourVector *fv1 = new FourVector();
  FourVector *fv2 = new FourVector();

  // event loop to generate some number of decays
  for(int iEv=0; iEv<nevents; iEv++){  
    GenEvent(fv1, fv2);
    if(iEv%10==0){
      fv1->Print();
      fv2->Print();
    }
  }

  return 23;  
}

// where the magin happens and we generate the decays of a massive particle
void GenEvent(FourVector *v1, FourVector *v2){

  std::cout<<"Generating Event"<<std::endl;
  
  // random generation
  float mass     = gen_mass(generator);
  float esplit   = gen_esplit(generator);
  float p1_theta = gen_theta(generator);
  float p1_phi   = gen_phi(generator);

  // translate to p1 assuming it is massless
  float e1  = mass*esplit;
  float pz1 = e1 * std::cos(p1_theta);
  float py1 = e1 * std::sin(p1_theta) * std::sin(p1_phi);
  float px1 = e1 * std::sin(p1_theta) * std::cos(p1_phi);
  
  v1->SetFourVector(px1, py1, pz1, e1);

  // conservation of momentum to get p2
  FourVector *mother = new FourVector(0,0,0,mass);
  
  v2->SetFourVector(mother->GetPx()-v1->GetPx(),
                    mother->GetPy()-v1->GetPy(),
                    mother->GetPz()-v1->GetPz(),
                    mother->GetE()-v1->GetE());
  
}
