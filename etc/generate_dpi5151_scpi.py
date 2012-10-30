#!/dls_sw/prod/tools/RHEL5/bin/dls-python2.6

from generate_scpi import *

if __name__ == "__main__":
    scpi = Scpi(baseClassGroup='instr')
    # Define the items
    scpi.add(Item('CAL:ZERO:AUTO', accessMode=Item.command, params=
        [Param('PerformZero', group='cal', defaultValue='1')] ))
    scpi.add(Item('CAL:ZERO:AUTO', accessMode=Item.command, params=
        [Param('AbortZero', group='cal', defaultValue='0')] ))
    scpi.add(Item('CAL:ZERO:AUTO', accessMode=Item.readOnly, params=
        [Param('AutoZeroState', group='cal', enum=['ok', 'in progress', 'timed out', 'offset o/s lims', 'aborted'], numericEnum=True)] ))
    scpi.add(Item('CAL:ZERO:AUTO:VAL', params=
        [Param('AutoZeroVal', dataType=Param.floatType, group='cal')] ))
    scpi.add(Item('CAL:ZERO:TIME', accessMode=Item.readOnly, params=
        [Param('TimedZero', dataType=Param.integerType, group='cal')] ))
    scpi.add(Item('CAL:ZERO:TIME:STAT', params=
        [Param('TimedZeroState', group='cal', enum=['off', 'on'], numericEnum=True)] ))
    scpi.add(Item('INP:LOG', accessMode=Item.readOnly, params=
        [Param('DigitalIn', group='outp', enum=['off', 'on'], numericEnum=True)] ))
    scpi.add(Item('INST:CAT', accessMode=Item.readOnly, params=
        [Param('InstrCatalogue', dataType=Param.longStringType, group='instr')] ))
    scpi.add(Item('INST:LIM1', accessMode=Item.readOnly, params=
        [Param('RangeName', dataType=Param.stringType, group='instr'),
        Param('MaxRange', dataType=Param.floatType, group='instr'),
        Param('MinRange', dataType=Param.floatType, group='instr')] ))
    scpi.add(Item('INST:SN', accessMode=Item.readOnly, params=
        [Param('InstrNumber', dataType=Param.integerType, group='instr')] ))
    scpi.add(Item('INST:UNIT1', accessMode=Item.readOnly, params=
        [Param('Units', dataType=Param.stringType, group='instr')] ))
    scpi.add(Item('INST:VERS', accessMode=Item.readOnly, params=
        [Param('InstrVersion', dataType=Param.integerType, group='instr')] ))
    scpi.add(Item('OUTP:ISOL', params=
        [Param('IsolationValve', group='outp', enum=['off', 'on'], numericEnum=True)] ))
    scpi.add(Item('OUTP:LOG1:LEV', params=
        [Param('DigitalOut1', group='outp', enum=['low', 'high'], numericEnum=True)] ))
    scpi.add(Item('OUTP:LOG2:LEV', params=
        [Param('DigitalOut2', group='outp', enum=['low', 'high'], numericEnum=True)] ))
    scpi.add(Item('OUTP:STAT', params=
        [Param('OutputState', group='outp', enum=['off', 'on'], numericEnum=True)] ))
    scpi.add(Item('SENS:PRES', accessMode=Item.readOnly, pollPeriod=1, params=
        [Param('Pressure', dataType=Param.floatType, group='sense')] ))
    scpi.add(Item('SENS:BAR', accessMode=Item.readOnly, params=
        [Param('Barometric', dataType=Param.floatType, group='sense')] ))
    scpi.add(Item('SENS:CORR:HEAD', params=
        [Param('GasUsed', group='sense', enum=['air', 'nitr']),
        Param('Height', dataType=Param.floatType, group='sense')] ))
    scpi.add(Item('SENS:CORR:HEAD:STAT', params=
        [Param('HeadCorrState', group='sense', enum=['off', 'on'], numericEnum=True)] ))
    #scpi.add(Item('SENS:CORR:HEAD:OFF', params=
    #    [Param('OffsetCorr', dataType=Param.floatType, group='sense')] ))
    #scpi.add(Item('SENS:CORR:HEAD:OFF:STAT', params=
    #    [Param('OffsetCorrState', group='sense', enum=['off', 'on'])] ))
    #scpi.add(Item('SENS:FILT:STEP', params=
    #    [Param('FilterStep', dataType=Param.floatType, group='sense')] ))
    scpi.add(Item('SENS:FILT:FREQ', params=
        [Param('FilterFrequency', dataType=Param.floatType, group='sense')] ))
    scpi.add(Item('SENS:FILT:STAT', params=
        [Param('FilterState', group='sense', enum=['off', 'on'], numericEnum=True)] ))
    scpi.add(Item('SENS:FILL:TIME', params=
        [Param('FillTime', dataType=Param.integerType, group='sense', defaultValue=30)] ))
    scpi.add(Item('SENS:FILL:TIME:STAT', params=
        [Param('FillTimeState', group='sense', enum=['off', 'on'], numericEnum=True)] ))
    scpi.add(Item('SENS:RANG', params=
        [Param('SenseRange', dataType=Param.stringType, group='sense', defaultValue='210.00barg')] ))
    scpi.add(Item('SOUR:EFF', accessMode=Item.readOnly, params=
        [Param('SetPointEffort', group='source')] ))
    scpi.add(Item('SOUR:INL', params=
        [Param('InLimits', dataType=Param.floatType, group='source')] ))
    scpi.add(Item('SOUR:INL:TIME', params=
        [Param('InLimitsTime', dataType=Param.floatType, group='source')] ))
    scpi.add(Item('SOUR', params=
        [Param('PressureSetPoint', dataType=Param.floatType, group='source')] ))
    scpi.add(Item('SOUR:VENT', accessMode=Item.command, params=
        [Param('PerformVent', group='source', defaultValue='1')] ))
    scpi.add(Item('SOUR:VENT', accessMode=Item.command, params=
        [Param('AbortVent', group='source', defaultValue='0')] ))
    scpi.add(Item('SOUR:VENT', accessMode=Item.readOnly, params=
        [Param('VentState', group='source', enum=['ok', 'in progress', 'timed out', 'o/s lims', 'aborted'], numericEnum=True)] ))
    scpi.add(Item('SOUR:VENT:TIME', params=
        [Param('VentTime', group='source')] ))
    scpi.add(Item('SOUR:RANG', params=
        [Param('SourceRange', dataType=Param.stringType, group='source', defaultValue='210.00barg')] ))
    scpi.add(Item('SOUR:RANG:AUTO', params=
        [Param('AutoSourceRange', group='source', enum=['off', 'on'], numericEnum=True)] ))
    scpi.add(Item('SOUR:RANG:LOW', accessMode=Item.readOnly, params=
        [Param('SourceRangeLow', dataType=Param.stringType, group='source')] ))
    scpi.add(Item('SOUR:SLEW', params=
        [Param('PressureSlewRate', dataType=Param.floatType, group='source')] ))
    scpi.add(Item('SOUR:SLEW:MODE', params=
        [Param('PressureSlewMode', group='source', enum=['max', 'val'])] ))
    scpi.add(Item('SOUR:SLEW:OVER', params=
        [Param('PressureOvershoot', group='source', enum=['not allowed', 'allowed'], numericEnum=True)] ))
    scpi.add(Item('STAT:OPER:COND', accessMode=Item.readOnly, params=
        [Param('ConditionRegister', group='stat')] ))
    scpi.add(Item('STAT:OPER:ENAB', params=
        [Param('EnableRegister', group='stat')] ))
    scpi.add(Item('STAT:OPER:EVEN', accessMode=Item.readOnly, params=
        [Param('EventRegister', group='stat')] ))
    scpi.add(Item('STAT:OPER:PRES:COND', accessMode=Item.readOnly, params=
        [Param('PressureConditionRegister', group='stat')] ))
    scpi.add(Item('STAT:OPER:PRES:ENAB', params=
        [Param('PressureEnableRegister', group='stat')] ))
    scpi.add(Item('STAT:OPER:PRES:EVEN', accessMode=Item.readOnly, params=
        [Param('PressureEventRegister', group='stat')] ))
    scpi.add(Item('SYST:ERR', accessMode=Item.readOnly, params=
        [Param('SystemErrorNumber', group='sys'),
        Param('SystemError', dataType=Param.stringType, group='sys')] ))
    scpi.add(Item('SYST:VERS', accessMode=Item.readOnly, params=
        [Param('SystemScpiVers', dataType=Param.stringType, group='sys')] ))
    scpi.add(Item('UNIT:PRES', params=
        [Param('PressureUnits', dataType=Param.stringType, group='unit', defaultValue='BAR')] ))
    scpi.add(Item('UNIT:DEF1', params=
        [Param('UserUnit1Name', dataType=Param.stringType, group='unit'),
        Param('UserUnit1Factor', dataType=Param.floatType, group='unit')] ))
    scpi.add(Item('UNIT:DEF2', params=
        [Param('UserUnit2Name', dataType=Param.stringType, group='unit'),
        Param('UserUnit2Factor', dataType=Param.floatType, group='unit')] ))
    scpi.add(Item('*CLS', accessMode=Item.command, params=
        [Param('ClearStatus', group='stat', iocOnly=True)] ))
    scpi.add(Item('*ESE', params=
        [Param('StdEventEnable', group='stat')] ))
    scpi.add(Item('*ESR', accessMode=Item.readOnly, params=
        [Param('StdEventStatus', group='stat')] ))
    scpi.add(Item(':GTL', accessMode=Item.command, params=
        [Param('AllowLocal', group='sys', iocOnly=True)] ))
    scpi.add(Item(':LLO', accessMode=Item.command, params=
        [Param('LocalLockOut', group='sys', iocOnly=True)] ))
    scpi.add(Item(':LOC', accessMode=Item.command, params=
        [Param('LocalOnly', group='sys', iocOnly=True)] ))
    scpi.add(Item(':REM', accessMode=Item.command, params=
        [Param('RemoteOnly', group='sys', iocOnly=True)] ))
    scpi.add(Item('*RST', accessMode=Item.command, params=
        [Param('ResetInstrument', group='sys', iocOnly=True)] ))
    scpi.add(Item('*SRE', params=
        [Param('ServiceReqEnable', group='stat')] ))
    scpi.add(Item('*STB', accessMode=Item.readOnly, params=
        [Param('StdStatusRegister', group='stat')] ))
    # Generate the files
    scpi.genIncludeFile('DruckDPI515App/src/DruckDPI515.h')
    scpi.genSourceFile('DruckDPI515App/src/DruckDPI515.cpp')
    scpi.genTemplateFile('DruckDPI515App/Db/DruckDPI515.template')
    scpi.genSimulation('etc/simulations/DruckDPI515_sim.py')
    # Generate the EDM panels
    scpi.genEdmPanel('DruckDPI515App/opi/edl/DruckDPI515_outp.edl', 'outp')
    scpi.genEdmPanel('DruckDPI515App/opi/edl/DruckDPI515_instr.edl', 'instr')
    scpi.genEdmPanel('DruckDPI515App/opi/edl/DruckDPI515_cal.edl', 'cal')
    scpi.genEdmPanel('DruckDPI515App/opi/edl/DruckDPI515_sense.edl', 'sense')
    scpi.genEdmPanel('DruckDPI515App/opi/edl/DruckDPI515_source.edl', 'source')
    scpi.genEdmPanel('DruckDPI515App/opi/edl/DruckDPI515_stat.edl', 'stat')
    scpi.genEdmPanel('DruckDPI515App/opi/edl/DruckDPI515_unit.edl', 'unit')
    scpi.genEdmPanel('DruckDPI515App/opi/edl/DruckDPI515_sys.edl', 'sys')
