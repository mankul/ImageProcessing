#include<opencv2/opencv.hpp>
#include"network.hpp"
#include"util_exceptions.hpp"
#include<iostream>


void downloadImage(const char * url, const char * filePath){
	NetworkConnection nc;
	nc.getJpegFileFromURL(url, filePath);
}

int main(){
	// path is absolute. please change accordingly.
	//cv::Mat image = cv::imread("/Users/mankulgupta/mankul/sample_images/neg1.png");
	// cv::Mat image = cv::imread("/Users/mankulgupta/mankul/sample_images/corridor.png");
	const char * url = "https://download.samplelib.com/jpeg/sample-city-park-400x300.jpg";
	const char * filePath = "/Users/mankulgupta/mankul/sample_images/sample1.jpeg";
	downloadImage(url, filePath);
	cv::Mat image = cv::imread(filePath);
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
