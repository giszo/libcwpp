# -*- python -*-

env = Environment()
env["CPPFLAGS"] = ["-O2", "-Wall", "-std=c++11"]
env["CPPPATH"] = [Dir("include")]

SConscript(["SConscript", "example/SConscript", "tst/SConscript"], exports = "env")
