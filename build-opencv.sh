cmake -DOPENCV_EXTRA_MODULES_PATH=../opencv_contrib-4.x/modules \
	 -D CMAKE_INSTALL_PREFIX=./install \
	 -D OPENCV_GENERATE_PKGCONFIG=ON \
	 ../opencv-4.x
