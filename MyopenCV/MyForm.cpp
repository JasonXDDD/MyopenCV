#include "MyForm.h"

using namespace MyopenCV;

void onMouse(int Event, int x, int y, int flags, void* param);
Mat src_img = imread("../Docs/triangle.bmp", CV_LOAD_IMAGE_COLOR);
Mat output_src_img(src_img.rows, src_img.cols, CV_8UC3, Scalar(0, 0, 0));
Mat warp_mat(2, 3, CV_32FC1);
int click_num = 0;
Point2f srcTri[3], dstTri[3];


[STAThreadAttribute]
int main(array<System::String ^>  ^args) {

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);


	namedWindow("image", 0);
	imshow("image", src_img);
	setMouseCallback("image", onMouse, NULL);


	Application::Run(gcnew MyForm());

	return 0;
}

void onMouse(int Event, int x, int y, int flags, void* param) {
	if (Event != EVENT_LBUTTONDOWN) return;

	if (click_num < 3 && click_num >= 0) {
		srcTri[click_num] = Point2f(x, y);
		printf("click number =%d  x=%d  Y=%d\n", click_num + 1, x, y);
	}
	else if (click_num >= 3 && click_num < 6) {
		dstTri[click_num - 3] = Point2f(x, y);
		printf("click number =%d  x=%d  Y=%d\n", click_num + 1, x, y);
	}

	else if (click_num == 6) {
		click_num = 0;
		warp_mat = getAffineTransform(srcTri, dstTri);
 		warpAffine(src_img, output_src_img, warp_mat, src_img.size());

		namedWindow("final", WINDOW_NORMAL);
		resizeWindow("final", 500, 500);
		imshow("final", output_src_img);
	}

	else return;

	click_num++;

}