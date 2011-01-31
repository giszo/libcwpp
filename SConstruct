# -*- python -*-

env = Environment()
env["CPPFLAGS"] = "-O2 -Wall -Iinclude"

SConscript(
    [
        "SConscript",
        "example/SConscript"
    ],
    exports = "env"
)
