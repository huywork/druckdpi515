#include "DruckDPI515.h"
#include <epicsExport.h>
#include <iocsh.h>

//*!*Section stringDefinition begin*!*
#define indexPerformZero_str "PERFORMZERO"
#define indexAbortZero_str "ABORTZERO"
#define indexAutoZeroState_str "AUTOZEROSTATE"
#define indexAutoZeroVal_str "AUTOZEROVAL"
#define indexTimedZero_str "TIMEDZERO"
#define indexTimedZeroState_str "TIMEDZEROSTATE"
#define indexDigitalIn_str "DIGITALIN"
#define indexInstrCatalogue_str "INSTRCATALOGUE"
#define indexRangeName_str "RANGENAME"
#define indexMaxRange_str "MAXRANGE"
#define indexMinRange_str "MINRANGE"
#define indexInstrNumber_str "INSTRNUMBER"
#define indexUnits_str "UNITS"
#define indexInstrVersion_str "INSTRVERSION"
#define indexIsolationValve_str "ISOLATIONVALVE"
#define indexDigitalOut1_str "DIGITALOUT1"
#define indexDigitalOut2_str "DIGITALOUT2"
#define indexOutputState_str "OUTPUTSTATE"
#define indexPressure_str "PRESSURE"
#define indexBarometric_str "BAROMETRIC"
#define indexGasUsed_str "GASUSED"
#define indexHeight_str "HEIGHT"
#define indexHeadCorrState_str "HEADCORRSTATE"
#define indexFilterFrequency_str "FILTERFREQUENCY"
#define indexFilterState_str "FILTERSTATE"
#define indexFillTime_str "FILLTIME"
#define indexFillTimeState_str "FILLTIMESTATE"
#define indexSenseRange_str "SENSERANGE"
#define indexSetPointEffort_str "SETPOINTEFFORT"
#define indexInLimits_str "INLIMITS"
#define indexInLimitsTime_str "INLIMITSTIME"
#define indexPressureSetPoint_str "PRESSURESETPOINT"
#define indexPerformVent_str "PERFORMVENT"
#define indexAbortVent_str "ABORTVENT"
#define indexVentState_str "VENTSTATE"
#define indexVentTime_str "VENTTIME"
#define indexSourceRange_str "SOURCERANGE"
#define indexAutoSourceRange_str "AUTOSOURCERANGE"
#define indexSourceRangeLow_str "SOURCERANGELOW"
#define indexPressureSlewRate_str "PRESSURESLEWRATE"
#define indexPressureSlewMode_str "PRESSURESLEWMODE"
#define indexPressureOvershoot_str "PRESSUREOVERSHOOT"
#define indexEnableRegister_str "ENABLEREGISTER"
#define indexEventRegister_str "EVENTREGISTER"
#define indexPressureConditionRegister_str "PRESSURECONDITIONREGISTER"
#define indexPressureEnableRegister_str "PRESSUREENABLEREGISTER"
#define indexPressureEventRegister_str "PRESSUREEVENTREGISTER"
#define indexSystemErrorNumber_str "SYSTEMERRORNUMBER"
#define indexSystemError_str "SYSTEMERROR"
#define indexSystemScpiVers_str "SYSTEMSCPIVERS"
#define indexPressureUnits_str "PRESSUREUNITS"
#define indexUserUnit1Name_str "USERUNIT1NAME"
#define indexUserUnit1Factor_str "USERUNIT1FACTOR"
#define indexUserUnit2Name_str "USERUNIT2NAME"
#define indexUserUnit2Factor_str "USERUNIT2FACTOR"
#define indexClearStatus_str "CLEARSTATUS"
#define indexStdEventEnable_str "STDEVENTENABLE"
#define indexStdEventStatus_str "STDEVENTSTATUS"
#define indexAllowLocal_str "ALLOWLOCAL"
#define indexLocalLockOut_str "LOCALLOCKOUT"
#define indexLocalOnly_str "LOCALONLY"
#define indexRemoteOnly_str "REMOTEONLY"
#define indexResetInstrument_str "RESETINSTRUMENT"
#define indexServiceReqEnable_str "SERVICEREQENABLE"
#define indexStdStatusRegister_str "STDSTATUSREGISTER"
//*!*Section stringDefinition end*!*
#define NUM_PARAMS (&LAST_PARAM - &FIRST_PARAM - 1)

//*!*Section enumDefinition begin*!*
static const char* GasUsedEnum = "air\0nitr\0";
static const char* PressureSlewModeEnum = "max\0val\0";
//*!*Section enumDefinition end*!*

/** Constructor.
  * \param[in] portName Name of this asyn port.
  * \param[in] devicePortName Name of the asyn port connected to the device.
  * \param[in] devicePortAddress Address of the device port (normally 0).
 */
DruckDPI515::DruckDPI515(const char* portName, const char* devicePortName, int devicePortAddress, int channels)
    : skippy(NULL), channels(channels)
	//: scpiPortDriver(portName,
	//		  devicePortName,
	//		  devicePortAddress, 0 /*maxAddr*/,
	//		  NUM_PARAMS,
	//		  scpiPortDriver::scpiHasAddress /*responseMode*/), channels(channels)
{

	this->skippy = new scpiPortDriver(portName,
									  devicePortName,
									  devicePortAddress, 0 /*maxAddr*/,
									  NUM_PARAMS,
									  scpiPortDriver::scpiHasAddress /*responseMode*/);
	if (skippy != NULL)
	{
		//*!*Section createParameter begin*!*
		skippy->createScpiItem(indexPerformZero_str, asynParamInt32, &indexPerformZero, "CAL:ZERO:AUTO", "", 0, 0, NULL, scpiPortDriver::scpiCommand, NULL, 5, false);
		skippy->createScpiItem(indexAbortZero_str, asynParamInt32, &indexAbortZero, "CAL:ZERO:AUTO", "", 0, 0, NULL, scpiPortDriver::scpiCommand, NULL, 5, false);
		skippy->createScpiItem(indexAutoZeroState_str, asynParamInt32, &indexAutoZeroState, "CAL:ZERO:AUTO", "", 0, 0, NULL, scpiPortDriver::scpiReadOnly, NULL, 5, false);
		skippy->createScpiItem(indexAutoZeroVal_str, asynParamFloat64, &indexAutoZeroVal, "CAL:ZERO:AUTO:VAL", "", 0, 0, NULL, scpiPortDriver::scpiReadWrite, NULL, 0, false);
		skippy->createScpiItem(indexTimedZero_str, asynParamInt32, &indexTimedZero, "CAL:ZERO:TIME", "", 0, 0, NULL, scpiPortDriver::scpiReadOnly, NULL, 5, false);
		skippy->createScpiItem(indexTimedZeroState_str, asynParamInt32, &indexTimedZeroState, "CAL:ZERO:TIME:STAT", "", 0, 0, NULL, scpiPortDriver::scpiReadWrite, NULL, 0, false);
		skippy->createScpiItem(indexDigitalIn_str, asynParamInt32, &indexDigitalIn, "INP:LOG", "", 0, 0, NULL, scpiPortDriver::scpiReadOnly, NULL, 5, false);
		skippy->createScpiItem(indexInstrCatalogue_str, asynParamOctet, &indexInstrCatalogue, "INST:CAT", "", 0, 0, NULL, scpiPortDriver::scpiReadOnly, NULL, 5, false);
		skippy->createScpiItem(indexRangeName_str, asynParamOctet, &indexRangeName, "INST:LIM1", "", 0, 0, NULL, scpiPortDriver::scpiReadOnly, NULL, 5, false);
		skippy->createScpiParam(indexRangeName, indexMaxRange_str, asynParamFloat64, &indexMaxRange, NULL, false);
		skippy->createScpiParam(indexRangeName, indexMinRange_str, asynParamFloat64, &indexMinRange, NULL, false);
		skippy->createScpiItem(indexInstrNumber_str, asynParamInt32, &indexInstrNumber, "INST:SN", "", 0, 0, NULL, scpiPortDriver::scpiReadOnly, NULL, 5, false);
		skippy->createScpiItem(indexUnits_str, asynParamOctet, &indexUnits, "INST:UNIT1", "", 0, 0, NULL, scpiPortDriver::scpiReadOnly, NULL, 5, false);
		skippy->createScpiItem(indexInstrVersion_str, asynParamInt32, &indexInstrVersion, "INST:VERS", "", 0, 0, NULL, scpiPortDriver::scpiReadOnly, NULL, 5, false);
		skippy->createScpiItem(indexIsolationValve_str, asynParamInt32, &indexIsolationValve, "OUTP:ISOL", "", 0, 0, NULL, scpiPortDriver::scpiReadWrite, NULL, 0, false);
		skippy->createScpiItem(indexDigitalOut1_str, asynParamInt32, &indexDigitalOut1, "OUTP:LOG1:LEV", "", 0, 0, NULL, scpiPortDriver::scpiReadWrite, NULL, 0, false);
		skippy->createScpiItem(indexDigitalOut2_str, asynParamInt32, &indexDigitalOut2, "OUTP:LOG2:LEV", "", 0, 0, NULL, scpiPortDriver::scpiReadWrite, NULL, 0, false);
		skippy->createScpiItem(indexOutputState_str, asynParamInt32, &indexOutputState, "OUTP:STAT", "", 0, 0, NULL, scpiPortDriver::scpiReadWrite, NULL, 0, false);
		skippy->createScpiItem(indexPressure_str, asynParamFloat64, &indexPressure, "SENS:PRES", "", 0, 0, NULL, scpiPortDriver::scpiReadOnly, NULL, 1, false);
		skippy->createScpiItem(indexBarometric_str, asynParamFloat64, &indexBarometric, "SENS:BAR", "", 0, 0, NULL, scpiPortDriver::scpiReadOnly, NULL, 5, false);
		skippy->createScpiItem(indexGasUsed_str, asynParamInt32, &indexGasUsed, "SENS:CORR:HEAD", "", 0, 0, GasUsedEnum, scpiPortDriver::scpiReadWrite, NULL, 0, false);
		skippy->createScpiParam(indexGasUsed, indexHeight_str, asynParamFloat64, &indexHeight, NULL, false);
		skippy->createScpiItem(indexHeadCorrState_str, asynParamInt32, &indexHeadCorrState, "SENS:CORR:HEAD:STAT", "", 0, 0, NULL, scpiPortDriver::scpiReadWrite, NULL, 0, false);
		skippy->createScpiItem(indexFilterFrequency_str, asynParamFloat64, &indexFilterFrequency, "SENS:FILT:FREQ", "", 0, 0, NULL, scpiPortDriver::scpiReadWrite, NULL, 0, false);
		skippy->createScpiItem(indexFilterState_str, asynParamInt32, &indexFilterState, "SENS:FILT:STAT", "", 0, 0, NULL, scpiPortDriver::scpiReadWrite, NULL, 0, false);
		skippy->createScpiItem(indexFillTime_str, asynParamInt32, &indexFillTime, "SENS:FILL:TIME", "", 0, 0, NULL, scpiPortDriver::scpiReadWrite, NULL, 0, false);
		skippy->createScpiItem(indexFillTimeState_str, asynParamInt32, &indexFillTimeState, "SENS:FILL:TIME:STAT", "", 0, 0, NULL, scpiPortDriver::scpiReadWrite, NULL, 0, false);
		skippy->createScpiItem(indexSenseRange_str, asynParamOctet, &indexSenseRange, "SENS:RANG", "", 0, 0, NULL, scpiPortDriver::scpiReadWrite, NULL, 0, false);
		skippy->createScpiItem(indexSetPointEffort_str, asynParamInt32, &indexSetPointEffort, "SOUR:EFF", "", 0, 0, NULL, scpiPortDriver::scpiReadOnly, NULL, 5, false);
		skippy->createScpiItem(indexInLimits_str, asynParamFloat64, &indexInLimits, "SOUR:INL", "", 0, 0, NULL, scpiPortDriver::scpiReadWrite, NULL, 0, false);
		skippy->createScpiItem(indexInLimitsTime_str, asynParamFloat64, &indexInLimitsTime, "SOUR:INL:TIME", "", 0, 0, NULL, scpiPortDriver::scpiReadWrite, NULL, 0, false);
		skippy->createScpiItem(indexPressureSetPoint_str, asynParamFloat64, &indexPressureSetPoint, "SOUR", "", 0, 0, NULL, scpiPortDriver::scpiReadWrite, NULL, 0, false);
		skippy->createScpiItem(indexPerformVent_str, asynParamInt32, &indexPerformVent, "SOUR:VENT", "", 0, 0, NULL, scpiPortDriver::scpiCommand, NULL, 5, false);
		skippy->createScpiItem(indexAbortVent_str, asynParamInt32, &indexAbortVent, "SOUR:VENT", "", 0, 0, NULL, scpiPortDriver::scpiCommand, NULL, 5, false);
		skippy->createScpiItem(indexVentState_str, asynParamInt32, &indexVentState, "SOUR:VENT", "", 0, 0, NULL, scpiPortDriver::scpiReadOnly, NULL, 5, false);
		skippy->createScpiItem(indexVentTime_str, asynParamInt32, &indexVentTime, "SOUR:VENT:TIME", "", 0, 0, NULL, scpiPortDriver::scpiReadWrite, NULL, 0, false);
		skippy->createScpiItem(indexSourceRange_str, asynParamOctet, &indexSourceRange, "SOUR:RANG", "", 0, 0, NULL, scpiPortDriver::scpiReadWrite, NULL, 0, false);
		skippy->createScpiItem(indexAutoSourceRange_str, asynParamInt32, &indexAutoSourceRange, "SOUR:RANG:AUTO", "", 0, 0, NULL, scpiPortDriver::scpiReadWrite, NULL, 0, false);
		skippy->createScpiItem(indexSourceRangeLow_str, asynParamOctet, &indexSourceRangeLow, "SOUR:RANG:LOW", "", 0, 0, NULL, scpiPortDriver::scpiReadOnly, NULL, 5, false);
		skippy->createScpiItem(indexPressureSlewRate_str, asynParamFloat64, &indexPressureSlewRate, "SOUR:SLEW", "", 0, 0, NULL, scpiPortDriver::scpiReadWrite, NULL, 0, false);
		skippy->createScpiItem(indexPressureSlewMode_str, asynParamInt32, &indexPressureSlewMode, "SOUR:SLEW:MODE", "", 0, 0, PressureSlewModeEnum, scpiPortDriver::scpiReadWrite, NULL, 0, false);
		skippy->createScpiItem(indexPressureOvershoot_str, asynParamInt32, &indexPressureOvershoot, "SOUR:SLEW:OVER", "", 0, 0, NULL, scpiPortDriver::scpiReadWrite, NULL, 0, false);
		skippy->createScpiItem(indexEnableRegister_str, asynParamInt32, &indexEnableRegister, "STAT:OPER:ENAB", "", 0, 0, NULL, scpiPortDriver::scpiReadWrite, NULL, 0, false);
		skippy->createScpiItem(indexEventRegister_str, asynParamInt32, &indexEventRegister, "STAT:OPER:EVEN", "", 0, 0, NULL, scpiPortDriver::scpiReadOnly, NULL, 5, false);
		skippy->createScpiItem(indexPressureConditionRegister_str, asynParamInt32, &indexPressureConditionRegister, "STAT:OPER:PRES:COND", "", 0, 0, NULL, scpiPortDriver::scpiReadOnly, NULL, 5, false);
		skippy->createScpiItem(indexPressureEnableRegister_str, asynParamInt32, &indexPressureEnableRegister, "STAT:OPER:PRES:ENAB", "", 0, 0, NULL, scpiPortDriver::scpiReadWrite, NULL, 0, false);
		skippy->createScpiItem(indexPressureEventRegister_str, asynParamInt32, &indexPressureEventRegister, "STAT:OPER:PRES:EVEN", "", 0, 0, NULL, scpiPortDriver::scpiReadOnly, NULL, 5, false);
		skippy->createScpiItem(indexSystemErrorNumber_str, asynParamInt32, &indexSystemErrorNumber, "SYST:ERR", "", 0, 0, NULL, scpiPortDriver::scpiReadOnly, NULL, 5, false);
		skippy->createScpiParam(indexSystemErrorNumber, indexSystemError_str, asynParamOctet, &indexSystemError, NULL, false);
		skippy->createScpiItem(indexSystemScpiVers_str, asynParamOctet, &indexSystemScpiVers, "SYST:VERS", "", 0, 0, NULL, scpiPortDriver::scpiReadOnly, NULL, 5, false);
		skippy->createScpiItem(indexPressureUnits_str, asynParamOctet, &indexPressureUnits, "UNIT:PRES", "", 0, 0, NULL, scpiPortDriver::scpiReadWrite, NULL, 0, false);
		skippy->createScpiItem(indexUserUnit1Name_str, asynParamOctet, &indexUserUnit1Name, "UNIT:DEF1", "", 0, 0, NULL, scpiPortDriver::scpiReadWrite, NULL, 0, false);
		skippy->createScpiParam(indexUserUnit1Name, indexUserUnit1Factor_str, asynParamFloat64, &indexUserUnit1Factor, NULL, false);
		skippy->createScpiItem(indexUserUnit2Name_str, asynParamOctet, &indexUserUnit2Name, "UNIT:DEF2", "", 0, 0, NULL, scpiPortDriver::scpiReadWrite, NULL, 0, false);
		skippy->createScpiParam(indexUserUnit2Name, indexUserUnit2Factor_str, asynParamFloat64, &indexUserUnit2Factor, NULL, false);
		skippy->createScpiItem(indexClearStatus_str, asynParamInt32, &indexClearStatus, "*CLS", "", 0, 0, NULL, scpiPortDriver::scpiCommand, NULL, 5, true);
		skippy->createScpiItem(indexStdEventEnable_str, asynParamInt32, &indexStdEventEnable, "*ESE", "", 0, 0, NULL, scpiPortDriver::scpiReadWrite, NULL, 0, false);
		skippy->createScpiItem(indexStdEventStatus_str, asynParamInt32, &indexStdEventStatus, "*ESR", "", 0, 0, NULL, scpiPortDriver::scpiReadOnly, NULL, 5, false);
		skippy->createScpiItem(indexAllowLocal_str, asynParamInt32, &indexAllowLocal, ":GTL", "", 0, 0, NULL, scpiPortDriver::scpiCommand, NULL, 5, true);
		skippy->createScpiItem(indexLocalLockOut_str, asynParamInt32, &indexLocalLockOut, ":LLO", "", 0, 0, NULL, scpiPortDriver::scpiCommand, NULL, 5, true);
		skippy->createScpiItem(indexLocalOnly_str, asynParamInt32, &indexLocalOnly, ":LOC", "", 0, 0, NULL, scpiPortDriver::scpiCommand, NULL, 5, true);
		skippy->createScpiItem(indexRemoteOnly_str, asynParamInt32, &indexRemoteOnly, ":REM", "", 0, 0, NULL, scpiPortDriver::scpiCommand, NULL, 5, true);
		skippy->createScpiItem(indexResetInstrument_str, asynParamInt32, &indexResetInstrument, "*RST", "", 0, 0, NULL, scpiPortDriver::scpiCommand, NULL, 5, true);
		skippy->createScpiItem(indexServiceReqEnable_str, asynParamInt32, &indexServiceReqEnable, "*SRE", "", 0, 0, NULL, scpiPortDriver::scpiReadWrite, NULL, 0, false);
		skippy->createScpiItem(indexStdStatusRegister_str, asynParamInt32, &indexStdStatusRegister, "*STB", "", 0, 0, NULL, scpiPortDriver::scpiReadOnly, NULL, 5, false);
		//*!*Section createParameter end*!*
		//*!*Section initParameter begin*!*
		skippy->setIntegerParam(indexPerformZero, '1');
		skippy->setIntegerParam(indexAbortZero, '0');
		skippy->setIntegerParam(indexAutoZeroState, 0);
		skippy->setDoubleParam(indexAutoZeroVal, 0.0);
		skippy->setIntegerParam(indexTimedZero, 0);
		skippy->setIntegerParam(indexTimedZeroState, 0);
		skippy->setIntegerParam(indexDigitalIn, 0);
		skippy->setStringParam(indexInstrCatalogue, "");
		skippy->setStringParam(indexRangeName, "");
		skippy->setDoubleParam(indexMaxRange, 0.0);
		skippy->setDoubleParam(indexMinRange, 0.0);
		skippy->setIntegerParam(indexInstrNumber, 0);
		skippy->setStringParam(indexUnits, "");
		skippy->setIntegerParam(indexInstrVersion, 0);
		skippy->setIntegerParam(indexIsolationValve, 0);
		skippy->setIntegerParam(indexDigitalOut1, 0);
		skippy->setIntegerParam(indexDigitalOut2, 0);
		skippy->setIntegerParam(indexOutputState, 0);
		skippy->setDoubleParam(indexPressure, 0.0);
		skippy->setDoubleParam(indexBarometric, 0.0);
		skippy->setIntegerParam(indexGasUsed, 0);
		skippy->setDoubleParam(indexHeight, 0.0);
		skippy->setIntegerParam(indexHeadCorrState, 0);
		skippy->setDoubleParam(indexFilterFrequency, 0.0);
		skippy->setIntegerParam(indexFilterState, 0);
		skippy->setIntegerParam(indexFillTime, 30);
		skippy->setIntegerParam(indexFillTimeState, 0);
		skippy->setStringParam(indexSenseRange, "210.00barg");
		skippy->setIntegerParam(indexSetPointEffort, 0);
		skippy->setDoubleParam(indexInLimits, 0.0);
		skippy->setDoubleParam(indexInLimitsTime, 0.0);
		skippy->setDoubleParam(indexPressureSetPoint, 0.0);
		skippy->setIntegerParam(indexPerformVent, '1');
		skippy->setIntegerParam(indexAbortVent, '0');
		skippy->setIntegerParam(indexVentState, 0);
		skippy->setIntegerParam(indexVentTime, 0);
		skippy->setStringParam(indexSourceRange, "210.00barg");
		skippy->setIntegerParam(indexAutoSourceRange, 0);
		skippy->setStringParam(indexSourceRangeLow, "");
		skippy->setDoubleParam(indexPressureSlewRate, 0.0);
		skippy->setIntegerParam(indexPressureSlewMode, 0);
		skippy->setIntegerParam(indexPressureOvershoot, 0);
		skippy->setIntegerParam(indexEnableRegister, 0);
		skippy->setIntegerParam(indexEventRegister, 0);
		skippy->setIntegerParam(indexPressureConditionRegister, 0);
		skippy->setIntegerParam(indexPressureEnableRegister, 0);
		skippy->setIntegerParam(indexPressureEventRegister, 0);
		skippy->setIntegerParam(indexSystemErrorNumber, 0);
		skippy->setStringParam(indexSystemError, "");
		skippy->setStringParam(indexSystemScpiVers, "");
		skippy->setStringParam(indexPressureUnits, "BAR");
		skippy->setStringParam(indexUserUnit1Name, "");
		skippy->setDoubleParam(indexUserUnit1Factor, 0.0);
		skippy->setStringParam(indexUserUnit2Name, "");
		skippy->setDoubleParam(indexUserUnit2Factor, 0.0);
		skippy->setIntegerParam(indexClearStatus, 0);
		skippy->setIntegerParam(indexStdEventEnable, 0);
		skippy->setIntegerParam(indexStdEventStatus, 0);
		skippy->setIntegerParam(indexAllowLocal, 0);
		skippy->setIntegerParam(indexLocalLockOut, 0);
		skippy->setIntegerParam(indexLocalOnly, 0);
		skippy->setIntegerParam(indexRemoteOnly, 0);
		skippy->setIntegerParam(indexResetInstrument, 0);
		skippy->setIntegerParam(indexServiceReqEnable, 0);
		skippy->setIntegerParam(indexStdStatusRegister, 0);
		//*!*Section initParameter end*!*
	}
}

/** Destructor.
  */
DruckDPI515::~DruckDPI515()
{
	if (skippy != NULL) delete skippy;
}

/** Configuration command, called directly or from iocsh.
  * \param[in] portName The name of this asyn port.
  * \param[in] devicePortName The name of the serial port connected to the device.
  * \param[in] devicePortAddress The address of the serial port (usually 0).
  */
extern "C" int DruckDPI515Config(const char *portName, const char* devicePortName,
    int devicePortAddress)
{
    new DruckDPI515(portName, devicePortName, devicePortAddress);
    return(asynSuccess);
}

/* Code for iocsh registration */
static const iocshArg DruckDPI515ConfigArg0 = {"Port name", iocshArgString};
static const iocshArg DruckDPI515ConfigArg1 = {"Device port name", iocshArgString};
static const iocshArg DruckDPI515ConfigArg2 = {"Device port address", iocshArgInt};
static const iocshArg DruckDPI515ConfigArg3 = {"Number of channels", iocshArgInt};
static const iocshArg* const DruckDPI515ConfigArgs[] =
    {&DruckDPI515ConfigArg0, &DruckDPI515ConfigArg1, &DruckDPI515ConfigArg2, &DruckDPI515ConfigArg3};
static const iocshFuncDef configDruckDPI515 = {"DruckDPI515Config", 4, DruckDPI515ConfigArgs};
static void configDruckDPI515CallFunc(const iocshArgBuf *args)
{
    DruckDPI515Config(args[0].sval, args[1].sval, args[2].ival);
}

static void DruckDPI515Register(void)
{
    iocshRegister(&configDruckDPI515, configDruckDPI515CallFunc);
}

extern "C" { epicsExportRegistrar(DruckDPI515Register); }


