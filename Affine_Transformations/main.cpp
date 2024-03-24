#include<opencv2/opencv.hpp>
#include"network.hpp"
#include"util_exceptions.hpp"
#include<iostream>

using namespace cv;

//download image from the source. need to test lib imported for different projects.
void downloadImage(const char * url, const char * filePath){
	NetworkConnection nc;
	nc.getJpegFileFromURL(url, filePath);
}


// read image.
Mat readImage(const char * filePath){
	Mat image = imread(filePath);
	return image;
}

// Rotation successfull.
void rotate_image_complete(Mat image, double angle){
	Mat frame, rotatedImage;
	int x, y;
	x = image.cols - 1;
	y = image.rows - 1;

	// diagonal for the image end to end.
	int diagonal = (int)std::sqrt(x * x + y * y);

	Mat rotationMatrix(diagonal, diagonal, image.type());
	Point2f centre(diagonal/2.0, diagonal/2.0);
	
	int offset_x = ( diagonal - x ) / 2;
	int offset_y = ( diagonal - y ) / 2;

	image.copyTo(rotationMatrix.rowRange(offset_x , offset_x + x ).colRange(offset_y, offset_y + y));

	Mat rotMat = getRotationMatrix2D(centre, angle, 1.0);


	warpAffine(rotMat, rotatedImage, rotationMatrix, rotationMatrix.size());

	double radians = ( angle * M_PI ) / 180.0;

	double sinR = abs(std::sin(radians));
	double cosR = abs(std::cos(radians));


	imshow("complete rotate",rotatedImage);
	waitKey(0);
}

void rotate_image(Mat image, double angle){
	int x = image.cols-1;
	int y = image.rows-1;
 	Point2f centre (x/3.0, y/3.0);
	
	
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
	// const char * url = "https://download.samplelib.com/jpeg/sample-city-park-400x300.jpg";
	const char * filePath = "/Users/mankulgupta/mankul/sample_images/sample1.jpeg";

	// not required
	// downloadImage(url, filePath);
	Mat image = readImage(filePath);

	// rotate_image(image, 45);
	rotate_image_complete(image, 45);
	return 0;
}
