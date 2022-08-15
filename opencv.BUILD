package(default_visibility = ["//visibility:public"])

cc_library(
    name = "opencv_headers",
    hdrs = glob(["include/**/*.h"]) + glob(["include/**/*.hpp"]),
    # includes = ["include/opencv4"],
    strip_include_prefix="include/opencv4",
)

cc_library(
    name = "opencv_libs",
    srcs = [
        "lib/libopencv_aruco.a",
        "lib/libopencv_bgsegm.a",
        "lib/libopencv_bioinspired.a",
        "lib/libopencv_ccalib.a",
        "lib/libopencv_dpm.a",
        "lib/libopencv_fuzzy.a",
        "lib/libopencv_hfs.a",
        "lib/libopencv_img_hash.a",
        "lib/libopencv_intensity_transform.a",
        "lib/libopencv_line_descriptor.a",
        "lib/libopencv_rapid.a",
        "lib/libopencv_reg.a",
        "lib/libopencv_rgbd.a",
        "lib/libopencv_saliency.a",
        "lib/libopencv_stereo.a",
        "lib/libopencv_structured_light.a",
        "lib/libopencv_phase_unwrapping.a",
        "lib/libopencv_superres.a",
        "lib/libopencv_optflow.a",
        "lib/libopencv_surface_matching.a",
        "lib/libopencv_tracking.a",
        "lib/libopencv_highgui.a",
        "lib/libopencv_videoio.a",
        "lib/libopencv_plot.a",
        "lib/libopencv_xfeatures2d.a",
        "lib/libopencv_shape.a",
        "lib/libopencv_ximgproc.a",
        "lib/libopencv_video.a",
        "lib/libopencv_xobjdetect.a",
        "lib/libopencv_objdetect.a",
        "lib/libopencv_calib3d.a",
        "lib/libopencv_imgcodecs.a",
        "lib/libopencv_features2d.a",
        "lib/libopencv_imgproc.a",
        "lib/libopencv_flann.a",
        "lib/libopencv_core.a",
        ##################### 3rdparty ##################################
        "lib/opencv4/3rdparty/liblibjpeg-turbo.a",
        "lib/opencv4/3rdparty/liblibwebp.a",
        "lib/opencv4/3rdparty/liblibpng.a",
        "lib/opencv4/3rdparty/liblibtiff.a",
        "lib/opencv4/3rdparty/liblibopenjp2.a",
        "lib/opencv4/3rdparty/libzlib.a",
        # "lib/libdl",
        # "lib/libm",
        # "lib/libpthread",
        # "lib/librt",
    ],
    deps = [
       "@system//:system",
    ]
)

cc_library(
    name = "opencv",
    deps = [
        ":opencv_headers",
        ":opencv_libs",
    ],
)
