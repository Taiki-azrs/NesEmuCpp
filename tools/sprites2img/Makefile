OPENCVHEADER = /usr/local/include/opencv4
LIB_LOADPATH = -L/usr/local/lib
LINK_OPENCV_LIBS = \
-lopencv_core \
-lopencv_imgcodecs \
-lopencv_highgui \
-lopencv_imgproc

LDFLAGS = -lm -lstdc++ $(LIB_LOADPATH) $(LINK_OPENCV_LIBS)

sprites2img: sprites2img.cpp ../../src/cassette.cpp
	$(CXX) $^ -o $@ -I$(OPENCVHEADER) $(LIB_LOADPATH) $(LINK_OPENCV_LIBS) -I../../include/ -g

clean:
	rm -rf sprites2img

%.o: %.cpp
	$(CXX) $(ENABLE_DEBUG) -I$(OPENCVHEADER) $(LIB_LOADPATH) $(LINK_OPENCV_LIBS) -I../../include/ -c $<
