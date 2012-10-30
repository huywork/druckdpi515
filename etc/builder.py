from iocbuilder import AutoSubstitution
from iocbuilder import Device
from iocbuilder.arginfo import *
from iocbuilder.modules.asyn import Asyn
from iocbuilder.modules.scpi import ScpiDevice

class DruckDPI515(AutoSubstitution):
    '''Controls a Druck DPI515 pressure controller.'''

    # The template file
    TemplateFile = 'DruckDPI515.template'

class DruckDPI515Device(Device):
    '''Controls a Druck DPI515 pressure controller.'''

    # Dependancies
    Dependencies = (ScpiDevice,)

    # Libraries
    LibFileList = ['DruckDPI515']
    DbdFileList = ['DruckDPI515']

    # Constructor, just store parameters
    def __init__(self, PORT, SERIALPORT, SERIALPORTADDR=0):
        Device.__init__(self)
        self.PORT = PORT
        self.SERIALPORT = SERIALPORT
        self.SERIALPORTADDR = SERIALPORTADDR

    # Once per instantiation
    def Initialise(self):
        print "DruckDPI515Config(%(PORT)s, %(SERIALPORT)s, %(SERIALPORTADDR)d)" % self.__dict__

    # Arguments
    ArgInfo = makeArgInfo(__init__,
        PORT = Simple("Asyn port name", str),
        SERIALPORT = Simple("Asyn serial port name", str),
        SERIALPORTADDR = Simple("Asyn serial port address", int))

