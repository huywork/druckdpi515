#!/dls_sw/prod/tools/RHEL5/bin/dls-python2.6

from scpi_sim import *

class DruckDPI515(scpi):

    def __init__(self, name="none", ui=None, tcpPort=9001, rpcPort=9002):
        '''Constructor.  Remember to call the base class constructor.'''
        scpi.__init__(self, ui=ui, tcpPort=tcpPort, rpcPort=rpcPort, responseHasAddress=True)
        self.diagnostic("Initialising DruckDPI515 simulator, V1.0")
        self.diagnostic("Power is %s" % self.power)
        # Define the SCPI items
        #*!*Section simulation begin*!*
        self.add(item('CAL:ZERO:AUTO', '', 0, 0, None, scpi.command, [param(None, '1')]))
        self.add(item('CAL:ZERO:AUTO', '', 0, 0, None, scpi.command, [param(None, '0')]))
        self.add(item('CAL:ZERO:AUTO', '', 0, 0, None, scpi.readOnly, [param(['ok', 'in progress', 'timed out', 'offset o/s lims', 'aborted'], None)]))
        self.add(item('CAL:ZERO:AUTO:VAL', '', 0, 0, None, scpi.readWrite, [param(None, None)]))
        self.add(item('CAL:ZERO:TIME', '', 0, 0, None, scpi.readOnly, [param(None, None)]))
        self.add(item('CAL:ZERO:TIME:STAT', '', 0, 0, None, scpi.readWrite, [param(['off', 'on'], None)]))
        self.add(item('INP:LOG', '', 0, 0, None, scpi.readOnly, [param(['off', 'on'], None)]))
        self.add(item('INST:CAT', '', 0, 0, None, scpi.readOnly, [param(None, None)]))
        self.add(item('INST:LIM1', '', 0, 0, None, scpi.readOnly, [param(None, None),param(None, None),param(None, None)]))
        self.add(item('INST:LIM1', '', 0, 0, None, scpi.readOnly, [param(None, None),param(None, None),param(None, None)]))
        self.add(item('INST:LIM1', '', 0, 0, None, scpi.readOnly, [param(None, None),param(None, None),param(None, None)]))
        self.add(item('INST:SN', '', 0, 0, None, scpi.readOnly, [param(None, None)]))
        self.add(item('INST:UNIT1', '', 0, 0, None, scpi.readOnly, [param(None, None)]))
        self.add(item('INST:VERS', '', 0, 0, None, scpi.readOnly, [param(None, None)]))
        self.add(item('OUTP:ISOL', '', 0, 0, None, scpi.readWrite, [param(['off', 'on'], None)]))
        self.add(item('OUTP:LOG1:LEV', '', 0, 0, None, scpi.readWrite, [param(['low', 'high'], None)]))
        self.add(item('OUTP:LOG2:LEV', '', 0, 0, None, scpi.readWrite, [param(['low', 'high'], None)]))
        self.add(item('OUTP:STAT', '', 0, 0, None, scpi.readWrite, [param(['off', 'on'], None)]))
        self.add(item('SENS:PRES', '', 0, 0, None, scpi.readOnly, [param(None, None)]))
        self.add(item('SENS:BAR', '', 0, 0, None, scpi.readOnly, [param(None, None)]))
        self.add(item('SENS:CORR:HEAD', '', 0, 0, None, scpi.readWrite, [param(['air', 'nitr'], None),param(None, None)]))
        self.add(item('SENS:CORR:HEAD', '', 0, 0, None, scpi.readWrite, [param(['air', 'nitr'], None),param(None, None)]))
        self.add(item('SENS:CORR:HEAD:STAT', '', 0, 0, None, scpi.readWrite, [param(['off', 'on'], None)]))
        self.add(item('SENS:FILT:FREQ', '', 0, 0, None, scpi.readWrite, [param(None, None)]))
        self.add(item('SENS:FILT:STAT', '', 0, 0, None, scpi.readWrite, [param(['off', 'on'], None)]))
        self.add(item('SENS:FILL:TIME', '', 0, 0, None, scpi.readWrite, [param(None, 30)]))
        self.add(item('SENS:FILL:TIME:STAT', '', 0, 0, None, scpi.readWrite, [param(['off', 'on'], None)]))
        self.add(item('SENS:RANG', '', 0, 0, None, scpi.readWrite, [param(None, '210.00barg')]))
        self.add(item('SOUR:EFF', '', 0, 0, None, scpi.readOnly, [param(None, None)]))
        self.add(item('SOUR:INL', '', 0, 0, None, scpi.readWrite, [param(None, None)]))
        self.add(item('SOUR:INL:TIME', '', 0, 0, None, scpi.readWrite, [param(None, None)]))
        self.add(item('SOUR', '', 0, 0, None, scpi.readWrite, [param(None, None)]))
        self.add(item('SOUR:VENT', '', 0, 0, None, scpi.command, [param(None, '1')]))
        self.add(item('SOUR:VENT', '', 0, 0, None, scpi.command, [param(None, '0')]))
        self.add(item('SOUR:VENT', '', 0, 0, None, scpi.readOnly, [param(['ok', 'in progress', 'timed out', 'o/s lims', 'aborted'], None)]))
        self.add(item('SOUR:VENT:TIME', '', 0, 0, None, scpi.readWrite, [param(None, None)]))
        self.add(item('SOUR:RANG', '', 0, 0, None, scpi.readWrite, [param(None, '210.00barg')]))
        self.add(item('SOUR:RANG:AUTO', '', 0, 0, None, scpi.readWrite, [param(['off', 'on'], None)]))
        self.add(item('SOUR:RANG:LOW', '', 0, 0, None, scpi.readOnly, [param(None, None)]))
        self.add(item('SOUR:SLEW', '', 0, 0, None, scpi.readWrite, [param(None, None)]))
        self.add(item('SOUR:SLEW:MODE', '', 0, 0, None, scpi.readWrite, [param(['max', 'val'], None)]))
        self.add(item('SOUR:SLEW:OVER', '', 0, 0, None, scpi.readWrite, [param(['not allowed', 'allowed'], None)]))
        self.add(item('STAT:OPER:ENAB', '', 0, 0, None, scpi.readWrite, [param(None, None)]))
        self.add(item('STAT:OPER:EVEN', '', 0, 0, None, scpi.readOnly, [param(None, None)]))
        self.add(item('STAT:OPER:PRES:COND', '', 0, 0, None, scpi.readOnly, [param(None, None)]))
        self.add(item('STAT:OPER:PRES:ENAB', '', 0, 0, None, scpi.readWrite, [param(None, None)]))
        self.add(item('STAT:OPER:PRES:EVEN', '', 0, 0, None, scpi.readOnly, [param(None, None)]))
        self.add(item('SYST:ERR', '', 0, 0, None, scpi.readOnly, [param(None, None),param(None, None)]))
        self.add(item('SYST:ERR', '', 0, 0, None, scpi.readOnly, [param(None, None),param(None, None)]))
        self.add(item('SYST:VERS', '', 0, 0, None, scpi.readOnly, [param(None, None)]))
        self.add(item('UNIT:PRES', '', 0, 0, None, scpi.readWrite, [param(None, 'BAR')]))
        self.add(item('UNIT:DEF1', '', 0, 0, None, scpi.readWrite, [param(None, None),param(None, None)]))
        self.add(item('UNIT:DEF1', '', 0, 0, None, scpi.readWrite, [param(None, None),param(None, None)]))
        self.add(item('UNIT:DEF2', '', 0, 0, None, scpi.readWrite, [param(None, None),param(None, None)]))
        self.add(item('UNIT:DEF2', '', 0, 0, None, scpi.readWrite, [param(None, None),param(None, None)]))
        self.add(item('*CLS', '', 0, 0, None, scpi.command, [param(None, None)]))
        self.add(item('*ESE', '', 0, 0, None, scpi.readWrite, [param(None, None)]))
        self.add(item('*ESR', '', 0, 0, None, scpi.readOnly, [param(None, None)]))
        self.add(item(':GTL', '', 0, 0, None, scpi.command, [param(None, None)]))
        self.add(item(':LLO', '', 0, 0, None, scpi.command, [param(None, None)]))
        self.add(item(':LOC', '', 0, 0, None, scpi.command, [param(None, None)]))
        self.add(item(':REM', '', 0, 0, None, scpi.command, [param(None, None)]))
        self.add(item('*RST', '', 0, 0, None, scpi.command, [param(None, None)]))
        self.add(item('*SRE', '', 0, 0, None, scpi.readWrite, [param(None, None)]))
        self.add(item('*STB', '', 0, 0, None, scpi.readOnly, [param(None, None)]))
        #*!*Section simulation end*!*

if __name__ == "__main__":
    # little test function that runs only when you run this file
    dev = DruckDPI515()
    # cheesy wait to stop the program exiting immediately
    while True:
        time.sleep(1)

