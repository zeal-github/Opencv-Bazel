workspace(name = "OpencvBazel")

new_local_repository(
    name = "opencv",
    # path = "/home/linzy5/.local/",
    # path = "/home/linzy5/OpenSourceSoftware/opencv-build-4.x/install",
    path = "/home/linzy5/OpenSourceSoftware/opencv-build-4.x-static/install",
    build_file = "opencv.BUILD",
)

new_local_repository(
    name = "system",
    path = "/usr/lib/x86_64-linux-gnu/",
    build_file = "system.BUILD"
)