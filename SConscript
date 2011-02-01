# -*- python -*-

Import("env")
env = env.Clone()

env.SharedLibrary(
    target = "libcwpp.so",
    source = [
        "src/core/Window.cpp",
        "src/core/Frame.cpp",
        "src/core/Size.cpp",
        "src/core/WindowManager.cpp",
        "src/layout/RowFrame.cpp",
        "src/layout/ColumnFrame.cpp",
        "src/window/BufferedWindow.cpp"
    ],
    LIBS = ["ncurses"]
)
