# -*- python -*-

import os

Import("env")
env = env.Clone()

headers = [
    "core/Frame.hpp",
    "core/Size.hpp",
    "core/Window.hpp",
    "core/WindowManager.hpp",
    "layout/ColumnFrame.hpp",
    "layout/RowFrame.hpp",
    "stream/Stream.hpp",
    "window/BufferedWindow.hpp",
    "window/InputWindow.hpp"
]

sources = [
    "src/core/Window.cpp",
    "src/core/Frame.cpp",
    "src/core/Size.cpp",
    "src/core/WindowManager.cpp",
    "src/layout/RowFrame.cpp",
    "src/layout/ColumnFrame.cpp",
    "src/window/BufferedWindow.cpp",
    "src/window/BufferedStream.cpp",
    "src/window/InputWindow.cpp",
    "src/util/StringUtils.cpp"
]

# Compile
shlib = env.SharedLibrary(
    target = "libcwpp.so",
    source = sources,
    LIBS = ["ncurses"]
)

# Install
lib_prefix = "/usr/lib"
inc_prefix = "/usr/include/libcwpp"

env.Alias("install", env.Install(lib_prefix, shlib))

for header in headers :
    env.Alias("install", env.Install(inc_prefix + os.path.sep + header[:header.rfind('/')], "include/libcwpp/" + header))
