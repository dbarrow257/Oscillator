#ifndef __OSCILLATOR_PROBGPULINEAR_H__
#define __OSCILLATOR_PROBGPULINEAR_H__

#include "OscProbCalcerBase.h"

/**
 * @file OscProbCalcer_ProbGPULinear.h
 *
 * @class OscProbCalcerProbGPULinear
 *
 * @brief Oscillation calculation engine for linear propagation in ProbGPU.
 */
class OscProbCalcerProbGPULinear : public OscProbCalcerBase {
 public:

  /**
   * @brief Default constructor
   *
   * @param ConfigName_ Name of config used to setup the OscProbCalcerProbGPULinear() instance
   * @param Instance_ Which entry of the OscProbCalcerSetup config block should be read in the case where there are multiple OscProbCalcers to be initialised
   */
  OscProbCalcerProbGPULinear(std::string ConfigName_="", int Instance_=0);

  // ========================================================================================================================================================================
  // Functions which need implementation specific code

  /**
   * @brief Setup ProbGPU specific variables but due to it's immplementation, don't actually need to do anythin
   *
   * ProbGPU implementation is horrible, meaning that this function doesn't need to do anything
   */  
  void SetupPropagator();

  /**
   * @brief Calculate some oscillation probabilities for a particular oscillation parameter set
   *
   * Calculator oscillation probabilities in ProbGPU. This links to GetProb in ProbGPU. This function both calculates and stores
   * the oscillation probabilities in #fWeightArray.
   *
   * @param OscParams The parameter set to calculate oscillation probabilities at
   */
  void CalculateProbabilities(std::vector<FLOAT_T> OscParams);

  /**
   * @brief Return implementation specific index in the weight array for a specific combination of neutrino oscillation channel, energy and cosine zenith
   * 
   * @param NuTypeIndex The index in #fNeutrinoTypes (neutrino/antinuetrino) to return the pointer for 
   * @param OscChanIndex The index in #fOscillationChannels to return the pointer for
   * @param EnergyIndex The index in #fEnergyArray to return the pointer for 
   * @param CosineZIndex The index in #fCosineZArray to return the pointer for 
   *
   * @return Index in #fWeightArray which corresponds to the given inputs
   */
  int ReturnWeightArrayIndex(int NuTypeIndex, int OscChanIndex, int EnergyIndex, int CosineZIndex=-1);

    /**
   * @brief Define the size of fWeightArray
   *
   * This is implementation specific because because ProbGPU is setup to calculate all oscillation channels together, whilst others calculate only a single oscillation channel.
   *
   * @return Length that #fWeightArray should be initialised to
   */
  long DefineWeightArraySize();

  // ========================================================================================================================================================================
  // Functions which help setup implementation specific code

  // ========================================================================================================================================================================
  // Variables which are needed for implementation specific code

  /**
   * @brief Definition of oscillation parameters which are expected in this ProbGPU implementation
   */
  enum OscParams{kTH12, kTH23, kTH13, kDM12, kDM23, kDCP, kPATHL, kDENS, kNOscParams};

  /**
   * @brief Define the neutrino and antineutrino values expected by this implementation
   */
  enum NuType{Nubar=-1, Nu=1};

  /**
   * @brief Boolean declaring what values are being passed for the values of theta_13 (sin^2(theta) or sin^2(2*theta))
   */
  bool doubled_angle;
};

#endif
