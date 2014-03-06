# -*- coding: utf-8 -*-
from iocbuilder import AutoSubstitution
from iocbuilder import Device
from iocbuilder.arginfo import *
from iocbuilder.modules.asyn import Asyn
from iocbuilder.modules.scpi import ScpiDevice

class DruckDPI515Template(AutoSubstitution):
    '''Controls a Druck DPI515 pressure controller.'''

    # The template file
    TemplateFile = 'DruckDPI515.template'

class DruckDPI515(DruckDPI515Template, Device):
    '''Controls a Druck DPI515 pressure controller.'''

    # Dependencies
    Dependencies = (ScpiDevice,)
    # Libraries
    LibFileList = ['DruckDPI515']
    DbdFileList = ['DruckDPI515']

    # Constructor, just store parameters
    def __init__(self, name, PORTADDR=0, **args):
        self.__super.__init__(**args)
        # put the args from the autosubstitution into the self.* dictionary
        self.__dict__.update(self.args)
        self.name = name
        self.PORTADDR = PORTADDR

    # Once per instantiation
    def Initialise(self):
        print 'DruckDPI515Config(\"%(name)s\", \"%(PORT)s\", %(PORTADDR)d)' % self.__dict__

    # Arguments
    ArgInfo = DruckDPI515Template.ArgInfo + makeArgInfo(__init__,
        name = Simple("Device name", str),
        PORTADDR = Simple("Asyn port address", int))

