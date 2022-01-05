#include <iostream>
#include "opencv2\opencv.hpp"
using namespace std;
using namespace cv;

//Mat�� IplImage�� ȣȯ ����!
Mat toMat(IplImage* img)
{
    return cvarrToMat(img);
}

IplImage* toIplImage(cv::Mat mat)
{
    auto img = new IplImage(mat);
    return img;
}


Mat img, roi;
int startpos_x, startpos_y, endpos_x, endpos_y;

bool capture = false;
void onMouse(int event, int x, int y, int flags, void* param) { 
    if (event == CV_EVENT_LBUTTONDOWN) {
        startpos_x = x;
        startpos_y = y;
        capture = true;
    }
    else if (event == CV_EVENT_MOUSEMOVE) {
        if (capture == true)
            circle(img, Point(x, y), 1, Scalar(0, 130, 230), 1);
    }

    else if (event == CV_EVENT_LBUTTONUP) {
        cout << "���� ���� �Ϸ�" << endl;
        endpos_x = x;
        endpos_y = y;
        capture = false;
        rectangle(img, Rect(startpos_x, startpos_y, endpos_x - startpos_x, endpos_y - startpos_y), Scalar(0, 0, 255), 2);
        imshow("image", img);

    }

}

int main() {
    img = imread("img\\carnumber.jpg");
    if (img.empty()) {
        cout << "�̹��� ������ �����ϴ�." << endl;
        return -1; 
    }
    imshow("image", img);
    Mat clone = img.clone();                    //���纻 ����
    setMouseCallback("image", onMouse);
    while (1) {
        int key = waitKey(100);                 //����ڷκ��� Ű�� ��ٸ���.
        if (key == 13)break;                    //enterŰ �Է½�, ����
        else if (key == 's') {                  //sŰ �Է½� , save
            roi = clone(Rect(startpos_x, startpos_y, endpos_x - startpos_x, endpos_y - startpos_y));
            imwrite("img//number.jpg", roi);
            cout << "����Ǿ����ϴ�." << endl;
        }
        if (key == 13)break;
        //Ű���� ���� Ű �Է� ��, ������
        else if (key == 2424832) {
            img -= 10;
            cout << "-10" << endl;
        }
        //Ű���� ������ Ű �Է� ��, ������
        else if (key == 2555904) {
            img += 10;
            cout << "+10" << endl;
        }
    }
    //�̹����� ��ȭ�� �������Ƿ� �ٽ� �����ִ� �Լ��� ȣ���ؾ��Ѵ�. 
    imshow("src", img);           
    return 0;

    //Mat Ŭ���� �ۼ� �� �޸� ���� X
    //cvWaitKey();
    //cvDestroyAllWindows();
    //cvReleaseImage(&img);

}


