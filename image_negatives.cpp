#include<opencv2/opencv.hpp>

int main(){
	cv::Mat image = cv::imread("/User/mankulgupta/mankul/sample_images/neg1.png");
	cv::imshow("image", image);
	cv::waitkey(0);
	return 0;
}
