/***************************************************************************
 *    Capacitance model                                                    *
 *       used to simulate capacitances in KTechLab                         *
 *    Copyright (c) 2010 Zoltan Padrah                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/


#ifndef CAPACITANCE_H
#define CAPACITANCE_H

#include "interfaces/simulator/ielement.h"

namespace KTechLab {

class Capacitance : public IElement
{
    public:
    // Capacitance();
    Capacitance(QVariantMap parentInModel);

    virtual void actOnSimulationStep(double currentTime);
    virtual void fillMatrixCoefficients();
};

}
#endif // CAPACITANCE_H
