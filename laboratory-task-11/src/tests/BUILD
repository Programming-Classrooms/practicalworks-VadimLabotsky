## src/tests/BUILD

cc_test(
    name = "tests",
    srcs = ["Test.cpp"],
    deps = [
        "@googletest//:gtest_main",
        "//src/class/All:All",
        "//src/class/AllSurnames:AllSurnames",
        "//src/class/AllNumbers:AllNumbers",
        "//src/class/Employee:Employee",
    ],
    data = [
        "//src/File:data"
    ],
)
