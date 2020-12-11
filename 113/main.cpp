#include <iostream>
#include <opencv.hpp>
using namespace cv;
using namespace std;

float Lut[256] = { 0 };

void LutBuild(float gammar)
{
	//����Lutͼ
	for (int i = 0; i < 256; i++)
	{
		Lut[i] = pow((i*1.0 / 255), gammar) * 255;
	}
}
void Gammar(Mat srcMat)
{
	//srcMat.copyTo(dstMat);
	int height = srcMat.rows; //����
	int width = srcMat.cols;//ÿ��Ԫ������
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{

			srcMat.at<Vec3b>(j, i)[0] = Lut[srcMat.at<Vec3b>(j, i)[0]];
			srcMat.at<Vec3b>(j, i)[1] = Lut[srcMat.at<Vec3b>(j, i)[1]];
			srcMat.at<Vec3b>(j, i)[2] = Lut[srcMat.at<Vec3b>(j, i)[2]];
		}//���д������
	}

}
int main()
{
	cv::Mat srcMat = imread("C:/Users/HS/Desktop/3.jpg");

	LutBuild(0.44);
	Gammar(srcMat);
	imshow("srcMat", srcMat);

	waitKey(0);

}