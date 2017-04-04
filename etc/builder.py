# -*- coding: utf-8 -*-
from iocbuilder import AutoSubstitution
from iocbuilder import Device
from iocbuilder.arginfo import *
from iocbuilder.modules.asyn import Asyn
from iocbuilder.modules.scpi import ScpiDevice
from iocbuilder.modules.scpi import Scpi

class _DruckDPI515Template(AutoSubstitution):
    '''Controls a Druck DPI515 pressure controller.'''

    # The template file
    TemplateFile = 'DruckDPI515.template'

class DruckDPI515(Device):
    '''Controls a Druck DPI515 pressure controller.'''

    # Dependencies
    Dependencies = (ScpiDevice,)
    # Libraries
    LibFileList = ['DruckDPI515']
    DbdFileList = ['DruckDPI515']

    # Constructor, just store parameters
    def __init__(self, PORT, SERPORT, SERPORTADDR, **args):
        self.__super.__init__()
        self.PORT = PORT
        self.SERPORT = SERPORT
        self.SERPORTADDR = SERPORTADDR
        _DruckDPI515Template(PORT=PORT, **args)

    # Once per instantiation
    def Initialise(self):
        print 'DruckDPI515Config(\"%(PORT)s\", \"%(SERPORT)s\", %(SERPORTADDR)d)' % self.__dict__

    # Arguments
    ArgInfo = _DruckDPI515Template.ArgInfo + makeArgInfo(__init__,
        PORT = Simple("This device asyn port name", str),
        SERPORT = Simple("The asyn serial port name", str),
        SERPORTADDR = Simple("The asyn serial port address", int))

