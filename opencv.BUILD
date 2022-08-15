package(default_visibility = ["//visibility:public"])

cc_library(
    name = "opencv_headers",
    hdrs = glob(["include/**/*.h"]) + glob(["include/**/*.hpp"]),
    # includes = ["include/opencv4"],
    strip_include_prefix="include/opencv4",
)

cc_library(
    name = "opencv_libs",
    srcs = glob(["lib/*.so"]),
)

cc_library(
    name = "opencv",
    deps = [
        ":opencv_headers",
        ":opencv_libs",
    ],
)
