import pbs.classes.Static

l = pbs.classes.Static.Static("galaxy_console", self)

l.inc_dirs.append("/usr/include/python2.7")

l.require("galaxy_std")

l.make()


