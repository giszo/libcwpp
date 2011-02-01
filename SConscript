# -*- python -*-

Import("env")
env = env.Clone()

env.SharedLibrary(
    target = "libcwpp.so",
    source = [
        "src/Window.cpp",
        "src/Frame.cpp",
        "src/RowFrame.cpp",
        "src/ColumnFrame.cpp",
        "src/Size.cpp",
        "src/WindowManager.cpp",
        "src/BufferedWindow.cpp"
    ],
    LIBS = ["ncurses"]
)
