#include<opencv2/opencv.hpp>
#include<iostream>
int main(){
	// path is absolute. please change accordingly.
	//cv::Mat image = cv::imread("/Users/mankulgupta/mankul/sample_images/neg1.png");
	cv::Mat image = cv::imread("/Users/mankulgupta/mankul/sample_images/corridor.png");
	int L = 255;
	int rows = image.rows;
	int cols = image.cols;
	std::cout<<"image size is : rows: "<<rows<<" cols: "<<cols<<std::endl;
	for (int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			//write logic
			//image.at<u_char>(i,j) = L - image.at<u_char>(i,j);
		}
	}
	cv::imshow("image", image);
	cv::waitKey(0);
	return 0;
}
