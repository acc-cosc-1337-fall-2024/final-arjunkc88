//
#ifndef POINT_PHASE_H
#define POINT_PHASE_H

#include "phase.h"

class PointPhase : public Phase {
private:
    int point;

public:
    explicit PointPhase(int p) : point(p) {}
    RollOutcome get_outcome(Roll* roll) override;
};

#endif // POINT_PHASE_H
