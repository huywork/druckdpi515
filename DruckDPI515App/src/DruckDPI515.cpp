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
#define indexConditionRegister_str "CONDITIONREGISTER"
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
DruckDPI515::DruckDPI515(const char* portName, const char* devicePortName,
        int devicePortAddress)
    : scpiPortDriver(portName, devicePortName, devicePortAddress,
        0 /*maxAddr*/, NUM_PARAMS, scpiHasAddress /*responseMode*/)
{
    //*!*Section createParameter begin*!*
    createScpiItem(indexPerformZero_str, asynParamInt32, &indexPerformZero, "CAL:ZERO:AUTO", "", 0, 0, NULL, scpiCommand, NULL, 5, false);
    createScpiItem(indexAbortZero_str, asynParamInt32, &indexAbortZero, "CAL:ZERO:AUTO", "", 0, 0, NULL, scpiCommand, NULL, 5, false);
    createScpiItem(indexAutoZeroState_str, asynParamInt32, &indexAutoZeroState, "CAL:ZERO:AUTO", "", 0, 0, NULL, scpiReadOnly, NULL, 5, false);
    createScpiItem(indexAutoZeroVal_str, asynParamFloat64, &indexAutoZeroVal, "CAL:ZERO:AUTO:VAL", "", 0, 0, NULL, scpiReadWrite, NULL, 5, false);
    createScpiItem(indexTimedZero_str, asynParamInt32, &indexTimedZero, "CAL:ZERO:TIME", "", 0, 0, NULL, scpiReadOnly, NULL, 5, false);
    createScpiItem(indexTimedZeroState_str, asynParamInt32, &indexTimedZeroState, "CAL:ZERO:TIME:STAT", "", 0, 0, NULL, scpiReadWrite, NULL, 5, false);
    createScpiItem(indexDigitalIn_str, asynParamInt32, &indexDigitalIn, "INP:LOG", "", 0, 0, NULL, scpiReadOnly, NULL, 5, false);
    createScpiItem(indexInstrCatalogue_str, asynParamOctet, &indexInstrCatalogue, "INST:CAT", "", 0, 0, NULL, scpiReadOnly, NULL, 5, false);
    createScpiItem(indexRangeName_str, asynParamOctet, &indexRangeName, "INST:LIM1", "", 0, 0, NULL, scpiReadOnly, NULL, 5, false);
    createScpiParam(indexRangeName, indexMaxRange_str, asynParamFloat64, &indexMaxRange, NULL, false);
    createScpiParam(indexRangeName, indexMinRange_str, asynParamFloat64, &indexMinRange, NULL, false);
    createScpiItem(indexInstrNumber_str, asynParamInt32, &indexInstrNumber, "INST:SN", "", 0, 0, NULL, scpiReadOnly, NULL, 5, false);
    createScpiItem(indexUnits_str, asynParamOctet, &indexUnits, "INST:UNIT1", "", 0, 0, NULL, scpiReadOnly, NULL, 5, false);
    createScpiItem(indexInstrVersion_str, asynParamInt32, &indexInstrVersion, "INST:VERS", "", 0, 0, NULL, scpiReadOnly, NULL, 5, false);
    createScpiItem(indexIsolationValve_str, asynParamInt32, &indexIsolationValve, "OUTP:ISOL", "", 0, 0, NULL, scpiReadWrite, NULL, 5, false);
    createScpiItem(indexDigitalOut1_str, asynParamInt32, &indexDigitalOut1, "OUTP:LOG1:LEV", "", 0, 0, NULL, scpiReadWrite, NULL, 5, false);
    createScpiItem(indexDigitalOut2_str, asynParamInt32, &indexDigitalOut2, "OUTP:LOG2:LEV", "", 0, 0, NULL, scpiReadWrite, NULL, 5, false);
    createScpiItem(indexOutputState_str, asynParamInt32, &indexOutputState, "OUTP:STAT", "", 0, 0, NULL, scpiReadWrite, NULL, 5, false);
    createScpiItem(indexPressure_str, asynParamFloat64, &indexPressure, "SENS:PRES", "", 0, 0, NULL, scpiReadOnly, NULL, 1, false);
    createScpiItem(indexBarometric_str, asynParamFloat64, &indexBarometric, "SENS:BAR", "", 0, 0, NULL, scpiReadOnly, NULL, 5, false);
    createScpiItem(indexGasUsed_str, asynParamInt32, &indexGasUsed, "SENS:CORR:HEAD", "", 0, 0, GasUsedEnum, scpiReadWrite, NULL, 5, false);
    createScpiParam(indexGasUsed, indexHeight_str, asynParamFloat64, &indexHeight, NULL, false);
    createScpiItem(indexHeadCorrState_str, asynParamInt32, &indexHeadCorrState, "SENS:CORR:HEAD:STAT", "", 0, 0, NULL, scpiReadWrite, NULL, 5, false);
    createScpiItem(indexFilterFrequency_str, asynParamFloat64, &indexFilterFrequency, "SENS:FILT:FREQ", "", 0, 0, NULL, scpiReadWrite, NULL, 5, false);
    createScpiItem(indexFilterState_str, asynParamInt32, &indexFilterState, "SENS:FILT:STAT", "", 0, 0, NULL, scpiReadWrite, NULL, 5, false);
    createScpiItem(indexFillTime_str, asynParamInt32, &indexFillTime, "SENS:FILL:TIME", "", 0, 0, NULL, scpiReadWrite, NULL, 5, false);
    createScpiItem(indexFillTimeState_str, asynParamInt32, &indexFillTimeState, "SENS:FILL:TIME:STAT", "", 0, 0, NULL, scpiReadWrite, NULL, 5, false);
    createScpiItem(indexSenseRange_str, asynParamOctet, &indexSenseRange, "SENS:RANG", "", 0, 0, NULL, scpiReadWrite, NULL, 5, false);
    createScpiItem(indexSetPointEffort_str, asynParamInt32, &indexSetPointEffort, "SOUR:EFF", "", 0, 0, NULL, scpiReadOnly, NULL, 5, false);
    createScpiItem(indexInLimits_str, asynParamFloat64, &indexInLimits, "SOUR:INL", "", 0, 0, NULL, scpiReadWrite, NULL, 5, false);
    createScpiItem(indexInLimitsTime_str, asynParamFloat64, &indexInLimitsTime, "SOUR:INL:TIME", "", 0, 0, NULL, scpiReadWrite, NULL, 5, false);
    createScpiItem(indexPressureSetPoint_str, asynParamFloat64, &indexPressureSetPoint, "SOUR", "", 0, 0, NULL, scpiReadWrite, NULL, 5, false);
    createScpiItem(indexPerformVent_str, asynParamInt32, &indexPerformVent, "SOUR:VENT", "", 0, 0, NULL, scpiCommand, NULL, 5, false);
    createScpiItem(indexAbortVent_str, asynParamInt32, &indexAbortVent, "SOUR:VENT", "", 0, 0, NULL, scpiCommand, NULL, 5, false);
    createScpiItem(indexVentState_str, asynParamInt32, &indexVentState, "SOUR:VENT", "", 0, 0, NULL, scpiReadOnly, NULL, 5, false);
    createScpiItem(indexVentTime_str, asynParamInt32, &indexVentTime, "SOUR:VENT:TIME", "", 0, 0, NULL, scpiReadWrite, NULL, 5, false);
    createScpiItem(indexSourceRange_str, asynParamOctet, &indexSourceRange, "SOUR:RANG", "", 0, 0, NULL, scpiReadWrite, NULL, 5, false);
    createScpiItem(indexAutoSourceRange_str, asynParamInt32, &indexAutoSourceRange, "SOUR:RANG:AUTO", "", 0, 0, NULL, scpiReadWrite, NULL, 5, false);
    createScpiItem(indexSourceRangeLow_str, asynParamOctet, &indexSourceRangeLow, "SOUR:RANG:LOW", "", 0, 0, NULL, scpiReadOnly, NULL, 5, false);
    createScpiItem(indexPressureSlewRate_str, asynParamFloat64, &indexPressureSlewRate, "SOUR:SLEW", "", 0, 0, NULL, scpiReadWrite, NULL, 5, false);
    createScpiItem(indexPressureSlewMode_str, asynParamInt32, &indexPressureSlewMode, "SOUR:SLEW:MODE", "", 0, 0, PressureSlewModeEnum, scpiReadWrite, NULL, 5, false);
    createScpiItem(indexPressureOvershoot_str, asynParamInt32, &indexPressureOvershoot, "SOUR:SLEW:OVER", "", 0, 0, NULL, scpiReadWrite, NULL, 5, false);
    createScpiItem(indexConditionRegister_str, asynParamInt32, &indexConditionRegister, "STAT:OPER:COND", "", 0, 0, NULL, scpiReadOnly, NULL, 5, false);
    createScpiItem(indexEnableRegister_str, asynParamInt32, &indexEnableRegister, "STAT:OPER:ENAB", "", 0, 0, NULL, scpiReadWrite, NULL, 5, false);
    createScpiItem(indexEventRegister_str, asynParamInt32, &indexEventRegister, "STAT:OPER:EVEN", "", 0, 0, NULL, scpiReadOnly, NULL, 5, false);
    createScpiItem(indexPressureConditionRegister_str, asynParamInt32, &indexPressureConditionRegister, "STAT:OPER:PRES:COND", "", 0, 0, NULL, scpiReadOnly, NULL, 5, false);
    createScpiItem(indexPressureEnableRegister_str, asynParamInt32, &indexPressureEnableRegister, "STAT:OPER:PRES:ENAB", "", 0, 0, NULL, scpiReadWrite, NULL, 5, false);
    createScpiItem(indexPressureEventRegister_str, asynParamInt32, &indexPressureEventRegister, "STAT:OPER:PRES:EVEN", "", 0, 0, NULL, scpiReadOnly, NULL, 5, false);
    createScpiItem(indexSystemErrorNumber_str, asynParamInt32, &indexSystemErrorNumber, "SYST:ERR", "", 0, 0, NULL, scpiReadOnly, NULL, 5, false);
    createScpiParam(indexSystemErrorNumber, indexSystemError_str, asynParamOctet, &indexSystemError, NULL, false);
    createScpiItem(indexSystemScpiVers_str, asynParamOctet, &indexSystemScpiVers, "SYST:VERS", "", 0, 0, NULL, scpiReadOnly, NULL, 5, false);
    createScpiItem(indexPressureUnits_str, asynParamOctet, &indexPressureUnits, "UNIT:PRES", "", 0, 0, NULL, scpiReadWrite, NULL, 5, false);
    createScpiItem(indexUserUnit1Name_str, asynParamOctet, &indexUserUnit1Name, "UNIT:DEF1", "", 0, 0, NULL, scpiReadWrite, NULL, 5, false);
    createScpiParam(indexUserUnit1Name, indexUserUnit1Factor_str, asynParamFloat64, &indexUserUnit1Factor, NULL, false);
    createScpiItem(indexUserUnit2Name_str, asynParamOctet, &indexUserUnit2Name, "UNIT:DEF2", "", 0, 0, NULL, scpiReadWrite, NULL, 5, false);
    createScpiParam(indexUserUnit2Name, indexUserUnit2Factor_str, asynParamFloat64, &indexUserUnit2Factor, NULL, false);
    createScpiItem(indexClearStatus_str, asynParamInt32, &indexClearStatus, "*CLS", "", 0, 0, NULL, scpiCommand, NULL, 5, true);
    createScpiItem(indexStdEventEnable_str, asynParamInt32, &indexStdEventEnable, "*ESE", "", 0, 0, NULL, scpiReadWrite, NULL, 5, false);
    createScpiItem(indexStdEventStatus_str, asynParamInt32, &indexStdEventStatus, "*ESR", "", 0, 0, NULL, scpiReadOnly, NULL, 5, false);
    createScpiItem(indexAllowLocal_str, asynParamInt32, &indexAllowLocal, ":GTL", "", 0, 0, NULL, scpiCommand, NULL, 5, true);
    createScpiItem(indexLocalLockOut_str, asynParamInt32, &indexLocalLockOut, ":LLO", "", 0, 0, NULL, scpiCommand, NULL, 5, true);
    createScpiItem(indexLocalOnly_str, asynParamInt32, &indexLocalOnly, ":LOC", "", 0, 0, NULL, scpiCommand, NULL, 5, true);
    createScpiItem(indexRemoteOnly_str, asynParamInt32, &indexRemoteOnly, ":REM", "", 0, 0, NULL, scpiCommand, NULL, 5, true);
    createScpiItem(indexResetInstrument_str, asynParamInt32, &indexResetInstrument, "*RST", "", 0, 0, NULL, scpiCommand, NULL, 5, true);
    createScpiItem(indexServiceReqEnable_str, asynParamInt32, &indexServiceReqEnable, "*SRE", "", 0, 0, NULL, scpiReadWrite, NULL, 5, false);
    createScpiItem(indexStdStatusRegister_str, asynParamInt32, &indexStdStatusRegister, "*STB", "", 0, 0, NULL, scpiReadOnly, NULL, 5, false);
    //*!*Section createParameter end*!*
    //*!*Section initParameter begin*!*
    setIntegerParam(indexPerformZero, '1');
    setIntegerParam(indexAbortZero, '0');
    setIntegerParam(indexAutoZeroState, 0);
    setDoubleParam(indexAutoZeroVal, 0.0);
    setIntegerParam(indexTimedZero, 0);
    setIntegerParam(indexTimedZeroState, 0);
    setIntegerParam(indexDigitalIn, 0);
    setStringParam(indexInstrCatalogue, "");
    setStringParam(indexRangeName, "");
    setDoubleParam(indexMaxRange, 0.0);
    setDoubleParam(indexMinRange, 0.0);
    setIntegerParam(indexInstrNumber, 0);
    setStringParam(indexUnits, "");
    setIntegerParam(indexInstrVersion, 0);
    setIntegerParam(indexIsolationValve, 0);
    setIntegerParam(indexDigitalOut1, 0);
    setIntegerParam(indexDigitalOut2, 0);
    setIntegerParam(indexOutputState, 0);
    setDoubleParam(indexPressure, 0.0);
    setDoubleParam(indexBarometric, 0.0);
    setIntegerParam(indexGasUsed, 0);
    setDoubleParam(indexHeight, 0.0);
    setIntegerParam(indexHeadCorrState, 0);
    setDoubleParam(indexFilterFrequency, 0.0);
    setIntegerParam(indexFilterState, 0);
    setIntegerParam(indexFillTime, 30);
    setIntegerParam(indexFillTimeState, 0);
    setStringParam(indexSenseRange, "210.00barg");
    setIntegerParam(indexSetPointEffort, 0);
    setDoubleParam(indexInLimits, 0.0);
    setDoubleParam(indexInLimitsTime, 0.0);
    setDoubleParam(indexPressureSetPoint, 0.0);
    setIntegerParam(indexPerformVent, '1');
    setIntegerParam(indexAbortVent, '0');
    setIntegerParam(indexVentState, 0);
    setIntegerParam(indexVentTime, 0);
    setStringParam(indexSourceRange, "210.00barg");
    setIntegerParam(indexAutoSourceRange, 0);
    setStringParam(indexSourceRangeLow, "");
    setDoubleParam(indexPressureSlewRate, 0.0);
    setIntegerParam(indexPressureSlewMode, 0);
    setIntegerParam(indexPressureOvershoot, 0);
    setIntegerParam(indexConditionRegister, 0);
    setIntegerParam(indexEnableRegister, 0);
    setIntegerParam(indexEventRegister, 0);
    setIntegerParam(indexPressureConditionRegister, 0);
    setIntegerParam(indexPressureEnableRegister, 0);
    setIntegerParam(indexPressureEventRegister, 0);
    setIntegerParam(indexSystemErrorNumber, 0);
    setStringParam(indexSystemError, "");
    setStringParam(indexSystemScpiVers, "");
    setStringParam(indexPressureUnits, "BAR");
    setStringParam(indexUserUnit1Name, "");
    setDoubleParam(indexUserUnit1Factor, 0.0);
    setStringParam(indexUserUnit2Name, "");
    setDoubleParam(indexUserUnit2Factor, 0.0);
    setIntegerParam(indexClearStatus, 0);
    setIntegerParam(indexStdEventEnable, 0);
    setIntegerParam(indexStdEventStatus, 0);
    setIntegerParam(indexAllowLocal, 0);
    setIntegerParam(indexLocalLockOut, 0);
    setIntegerParam(indexLocalOnly, 0);
    setIntegerParam(indexRemoteOnly, 0);
    setIntegerParam(indexResetInstrument, 0);
    setIntegerParam(indexServiceReqEnable, 0);
    setIntegerParam(indexStdStatusRegister, 0);
    //*!*Section initParameter end*!*
}

/** Destructor.
  */
DruckDPI515::~DruckDPI515()
{
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
static const iocshArg* const DruckDPI515ConfigArgs[] =
    {&DruckDPI515ConfigArg0, &DruckDPI515ConfigArg1, &DruckDPI515ConfigArg2};
static const iocshFuncDef configDruckDPI515 = {"DruckDPI515Config", 3, DruckDPI515ConfigArgs};
static void configDruckDPI515CallFunc(const iocshArgBuf *args)
{
    DruckDPI515Config(args[0].sval, args[1].sval, args[2].ival);
}

static void DruckDPI515Register(void)
{
    iocshRegister(&configDruckDPI515, configDruckDPI515CallFunc);
}

extern "C" { epicsExportRegistrar(DruckDPI515Register); }


