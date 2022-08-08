# Opencv-Bazel
Minimum example to show how to build bazel project which depends on opencv

This project is tested on:
1. opencv 4.6.0
2. bazel 5.2.0

# Steps Outline

1. compile opencv locally
2. setup bazel configurations. (WORKSPACE && BUILD files)
3. link opencv in your target binary


# Compile opencv
Reference: [Official: tutorial_linux_install](https://docs.opencv.org/4.x/d7/d9f/tutorial_linux_install.html)

```bash
# Install minimal prerequisites (Ubuntu 18.04 as reference)
sudo apt update && sudo apt install -y cmake g++ wget unzip

cd /dir/path/to/place/source/

# Download and unpack sources
wget -O opencv.zip https://github.com/opencv/opencv/archive/4.x.zip
wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/4.x.zip
unzip opencv.zip
unzip opencv_contrib.zip
# Create build directory and switch into it
mkdir -p build-opencv-4.x && cd build-opencv-4.x
# Configure
cmake -DOPENCV_EXTRA_MODULES_PATH=../opencv_contrib-4.x/modules -DCMAKE_INSTALL_PREFIX=.local ../opencv-4.x
# Build
cmake --build .

# Install to /path/to/build-opencv-4.x/install
make install # dont need superuser privileges
```

After conducting installtion steps above, all required files will be located in `/path/to/build-opencv-4.x/install`

directory tree of `/path/to/build-opencv-4.x/install`
```bash
.
├── bin                                 # opencv example, e.g. opencv_version
├── include                             
│   └── opencv4                         # headers, we may add this directory to header search path
│       └── opencv2
│           ├── core.hpp
│           ├── opencv.hpp
│           └── other headers
├── lib                                 # library, opencv will build in dinamic mode by default
│   ├── cmake
│   ├── ... othre dynamic library
│   ├── ... othre dynamic library
│   ├── libopencv_core.so -> libopencv_core.so.406
│   ├── libopencv_core.so.406 -> libopencv_core.so.4.6.0
│   ├── libopencv_core.so.4.6.0
│   └── python3.8
└── share                               # other files
    ├── licenses
    └── opencv4

```

# setup bazel

Firstly, you should may your workspace to find opencv, add below configuration into your `WORKSPACE` file

```bash
new_local_repository(
    name = "opencv",
    path = "/path/to/build-opencv-4.x/install",
    build_file = "opencv.BUILD", 
)

```

create an `opencv.BUILD` file in the same directory of your WORKSPACE

```bash
# opencv.BUILD
package(default_visibility = ["//visibility:public"])

cc_library(
    name = "opencv_headers",
    hdrs = glob(["include/**/*.h"]) + glob(["include/**/*.hpp"]),
    # includes = ["include/opencv4"],
    strip_include_prefix="include/opencv4",
)

cc_library(
    name = "opencv_libs",
    srcs = glob(["lib/*.so*"])
)


cc_library(
    name = "opencv",
    deps = [
        ":opencv_headers",
        ":opencv_libs",
    ],
    visibility = ["//visibility:public"],
)
```

# link opencv in your target binary
For now, opencv can be depend on by `@opencv://opencv`.
This only thing is add opencv as dependence in your cc_binary
```bash
load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_binary(
    name = "WriteVideo",
    srcs = ["WriteVideo.cpp"],
    deps = [
        "@opencv//:opencv",
    ]
)

```
