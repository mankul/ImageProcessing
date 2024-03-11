#include<opencv2/opencv.hpp>
#include"network.hpp"
#include"util_exceptions.hpp"
#include<iostream>

using namespace cv;


void downloadImage(const char * url, const char * filePath){
	NetworkConnection nc;
	nc.getJpegFileFromURL(url, filePath);
}

Mat readImage(const char * filePath){
	Mat image = imread(filePath);
	return image;
}


void rotate_image(Mat image, double angle){
	Point2f centre ((image.cols- 1)/2.0, (image.rows-1)/2.0);

	// Rotation matrix
	Mat rotation_matrix = getRotationMatrix2D(centre, angle, 1.0);

	// save rotated image to following matrix.
	Mat rotated_image;

	// Rotate matrix with warpAffine function.
	warpAffine(image, rotated_image, rotation_matrix, image.size());

	imshow("Rotated image 45 degree", rotated_image);

	waitKey(0);
	
}

// incomplete
void translate_image(Mat image){
	Mat matrix = Mat::zeros(3,3,CV_32FC1);

}


// incomplete
void scale_image(const char * filePath){
	Mat image = imread(filePath);
	int L = 255;
	int rows = image.rows;
	int cols = image.cols;
	std::cout<<"image size is : rows: "<<rows<<" cols: "<<cols<<std::endl;
	for (int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			// write logic
			image.at<u_char>(i,j) = L - image.at<u_char>(i,j);
		}
	}
	imshow("image", image);
	waitKey(0);
	
}



void displayImage(const char * filePath){
	Mat image = imread(filePath);
	int L = 255;
	int rows = image.rows;
	int cols = image.cols;
	std::cout<<"image size is : rows: "<<rows<<" cols: "<<cols<<std::endl;
	// for (int i = 0; i < rows; i++)
	// {
		// for(int j = 0; j < cols; j++)
		// {
			//write logic
			// image.at<u_char>(i,j) = L - image.at<u_char>(i,j);
		// }
	// }
	cv::imshow("image", image);
	cv::waitKey(0);
}

int main(){
	// path is absolute. please change accordingly.
	//cv::Mat image = cv::imread("/Users/mankulgupta/mankul/sample_images/neg1.png");
	// cv::Mat image = cv::imread("/Users/mankulgupta/mankul/sample_images/corridor.png");
	const char * url = "https://download.samplelib.com/jpeg/sample-city-park-400x300.jpg";
	const char * filePath = "/Users/mankulgupta/mankul/sample_images/sample1.jpeg";
	downloadImage(url, filePath);
	Mat image = readImage(filePath);
	rotate_image(image, 45);
	return 0;
}
