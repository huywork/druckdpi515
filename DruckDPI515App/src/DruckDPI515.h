/*
 * DruckDPI515.h
 *
 *  Created on: 21 Sept 2012
 *      Author: fgz73762
 */

#ifndef DRUCKDPI515_H_
#define DRUCKDPI515_H_

#include "scpiPortDriver.h"

class DruckDPI515 //: scpiPortDriver
{
public:
	DruckDPI515(const char *portName, const char* devicePortName, int devicePortAddress, int channels = 2);
    virtual ~DruckDPI515();

protected:
    /* Parameter indices */
    int FIRST_PARAM;
    //*!*Section indexDeclaration begin*!*
    int indexPerformZero;
    int indexAbortZero;
    int indexAutoZeroState;
    int indexAutoZeroVal;
    int indexTimedZero;
    int indexTimedZeroState;
    int indexDigitalIn;
    int indexInstrCatalogue;
    int indexRangeName;
    int indexMaxRange;
    int indexMinRange;
    int indexInstrNumber;
    int indexUnits;
    int indexInstrVersion;
    int indexIsolationValve;
    int indexDigitalOut1;
    int indexDigitalOut2;
    int indexOutputState;
    int indexPressure;
    int indexBarometric;
    int indexGasUsed;
    int indexHeight;
    int indexHeadCorrState;
    int indexFilterFrequency;
    int indexFilterState;
    int indexFillTime;
    int indexFillTimeState;
    int indexSenseRange;
    int indexSetPointEffort;
    int indexInLimits;
    int indexInLimitsTime;
    int indexPressureSetPoint;
    int indexPerformVent;
    int indexAbortVent;
    int indexVentState;
    int indexVentTime;
    int indexSourceRange;
    int indexAutoSourceRange;
    int indexSourceRangeLow;
    int indexPressureSlewRate;
    int indexPressureSlewMode;
    int indexPressureOvershoot;
    int indexEnableRegister;
    int indexEventRegister;
    int indexPressureConditionRegister;
    int indexPressureEnableRegister;
    int indexPressureEventRegister;
    int indexSystemErrorNumber;
    int indexSystemError;
    int indexSystemScpiVers;
    int indexPressureUnits;
    int indexUserUnit1Name;
    int indexUserUnit1Factor;
    int indexUserUnit2Name;
    int indexUserUnit2Factor;
    int indexClearStatus;
    int indexStdEventEnable;
    int indexStdEventStatus;
    int indexAllowLocal;
    int indexLocalLockOut;
    int indexLocalOnly;
    int indexRemoteOnly;
    int indexResetInstrument;
    int indexServiceReqEnable;
    int indexStdStatusRegister;
    //*!*Section indexDeclaration end*!*
    int LAST_PARAM;
private:
    int channels;
    scpiPortDriver* skippy;
};


#endif /* DRUCKDPI515_H_ */
