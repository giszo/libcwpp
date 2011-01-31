# -*- python -*-

Import("env")
env = env.Clone()

env.SharedLibrary(
    target = "libcwpp.so",
    source = [
        "src/Window.cpp",
        "src/Frame.cpp",
        "src/RowFrame.cpp",
        "src/WindowFrame.cpp",
        "src/Size.cpp"
    ]
)
