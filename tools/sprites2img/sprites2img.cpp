#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
using namespace cv;
using namespace std;

#include "type.hpp"
#include "cassette.hpp"


void display(cv::Mat image) {
  std::string windowName = "windowName";
  cv::namedWindow(windowName);
  cv::imshow(windowName, image);
  cv::waitKey(1000 * 10);
  cv::destroyWindow(windowName);
}
int main(){
  nes::cassette cst("mariobros3.nes");

  // int cols = image.cols;
  // int rows = image.rows;
  int IMG_W_NUM=64;
  int IMG_W=IMG_W_NUM*8;
  int IMG_H_NUM=cst.size_of_CHR()/16/IMG_W_NUM;
  int IMG_H=IMG_H_NUM*8;
  vector<vector<int>> vec_sp(IMG_H,vector<int>(IMG_W));
  Mat image = Mat::zeros(IMG_H,IMG_W, CV_8U);  
  for(int wj = 0; wj < IMG_W_NUM; wj++) {
    for(int hj = 0; hj < IMG_H_NUM; hj++) {
      for(int i=0;i<8;i++){
	int j_idx=hj*16*IMG_W_NUM+wj*16;
	for(int m=0;m<8;m++){
	  int one = cst.read_CHR(j_idx+i) >> 7-m  & 0x01;
	  int two = cst.read_CHR(j_idx+8+i) >> 7-m  & 0x01;
	  int out=one*85+two*170;
	  image.at<nes::byte>(i+hj*8,m+wj*8) = out;
	}
      }
    }
  }
  imwrite("out.png",image);
  display(image);
  return 0;
}
