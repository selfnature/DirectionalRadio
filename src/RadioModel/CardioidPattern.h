//
// Paula Uribe
// INRIA - Sophia Antipolis
// September 2009
// A Cardioid shaped antenna pattern was implemented for the directional antenna gain.
// The curve is scaled first according to the beamwidth value.
// After that the curve is normalized, and the gain is calculated as the product of the
// normalized curve with the maximum antenna gain (main lobe gain).
// The side/back lobes were modeled as circle. The gain in a given direction will be
// the greater value between the circle and the cardioid.
//

#ifndef __INET_CARDIOIDPATTERN_H
#define __INET_CARDIOIDPATTERN_H

#include "IAntennaPattern.h"

namespace RadioModel {

class INET_API CardioidPattern : public IAntennaPattern
{
  protected:
	// cardioid curve parameters
	double a;
	double scaled_a;
	double k;

	// radio parameters
	double dBThreshold;
	double beamWidth;
	double mainLobeGain;
	double sideLobeGain;
	double mainLobeOrientation;

  public:
	// methods to be re-implemented
	virtual void initialize();
    virtual double calculateGain(Coord& posA, Coord& posB);

};

}

#endif


