# -*- python -*-

import os

Import("env")
env = env.Clone()

headers = [
    "core/Frame.hpp",
    "core/Size.hpp",
    "core/Canvas.hpp",
    "core/Window.hpp",
    "core/WindowManager.hpp",
    "layout/ColumnFrame.hpp",
    "layout/RowFrame.hpp",
    "stream/Stream.hpp",
    "window/BufferedWindow.hpp",
    "window/InputWindow.hpp",
    "window/ListWindow.hpp"
]

sources = [
    "core/Window.cpp",
    "core/Frame.cpp",
    "core/Size.cpp",
    "core/Canvas.cpp",
    "core/WindowManager.cpp",
    "layout/RowFrame.cpp",
    "layout/ColumnFrame.cpp",
    "window/BufferedWindow.cpp",
    "window/BufferedStream.cpp",
    "window/InputWindow.cpp",
    "window/ListWindow.cpp",
    "util/StringUtils.cpp"
]

# Compile
shlib = env.SharedLibrary(
    "cwpp",
    source = ["src/%s" % x for x in sources],
    LIBS = ["ncurses"]
)

# Install
lib_prefix = "/usr/lib"
inc_prefix = "/usr/include/libcwpp"

env.Alias("install", env.Install(lib_prefix, shlib))

for header in headers :
    env.Alias("install", env.Install(inc_prefix + os.path.sep + header[:header.rfind('/')], "include/libcwpp/" + header))

# Default target
Default(shlib)
