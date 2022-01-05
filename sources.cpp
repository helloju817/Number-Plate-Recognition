#include <iostream>
#include "opencv2\opencv.hpp"
using namespace std;
using namespace cv;

//Mat과 IplImage는 호환 가능!
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
        cout << "영역 지정 완료" << endl;
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
        cout << "이미지 파일이 없습니다." << endl;
        return -1; 
    }
    imshow("image", img);
    Mat clone = img.clone();                    //복사본 생성
    setMouseCallback("image", onMouse);
    while (1) {
        int key = waitKey(100);                 //사용자로부터 키를 기다린다.
        if (key == 13)break;                    //enter키 입력시, 종료
        else if (key == 's') {                  //s키 입력시 , save
            roi = clone(Rect(startpos_x, startpos_y, endpos_x - startpos_x, endpos_y - startpos_y));
            imwrite("img//number.jpg", roi);
            cout << "저장되었습니다." << endl;
        }
        if (key == 13)break;
        //키보드 왼쪽 키 입력 시, 색조절
        else if (key == 2424832) {
            img -= 10;
            cout << "-10" << endl;
        }
        //키보드 오른쪽 키 입력 시, 색조절
        else if (key == 2555904) {
            img += 10;
            cout << "+10" << endl;
        }
    }
    //이미지에 변화가 생겼으므로 다시 보여주는 함수를 호출해야한다. 
    imshow("src", img);           
    return 0;

    //Mat 클래스 작성 시 메모리 관리 X
    //cvWaitKey();
    //cvDestroyAllWindows();
    //cvReleaseImage(&img);

}


