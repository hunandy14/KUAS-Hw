/**********************************************************
Name : 
Date : 2016/08/12
By   : CharlotteHonG
Final: 2016/08/12
**********************************************************/
#define Ratio 5
#include <opencv.hpp>

int main(int argc, char const *argv[]){
    // 縮放倍率
    float scale = Ratio;
    // 創建畫布
    IplImage *src = 0;
    IplImage *dst = 0;
    // 載入圖片
    src = cvLoadImage("IMG.JPG");
    // 畫布大小
    CvSize dst_cvsize;
    dst_cvsize.width = (int)(src->width * scale);
    dst_cvsize.height = (int)(src->height * scale);
    // 創建影像
    dst = cvCreateImage( dst_cvsize, src->depth, src->nChannels);

    // 調整影像大小
    // cvResize(src,dst,CV_INTER_NN); // CV_INTER_NN - 最鄰近插值
    cvResize(src,dst,CV_INTER_LINEAR); // CV_INTER_LINEAR - 雙線性插值
    // cvResize(src,dst,CV_INTER_AREA); //CV_INTER_AREA - 像素關係重採樣(縮小可避免波紋)
    // cvResize(src,dst,CV_INTER_CUBIC); //CV_INTER_CUBIC - 立方插值

    // 匯出圖片
    cvSaveImage("IMG_OUT.jpg", dst);
    // 開啟圖片
    cvNamedWindow("IMG - src", CV_WINDOW_AUTOSIZE );
    cvNamedWindow("IMG - dst", CV_WINDOW_AUTOSIZE );
    cvShowImage("IMG - src", src);
    cvShowImage("IMG - dst", dst);
    // 等待按鍵輸入
    cvWaitKey(0);
    // 釋放記憶體
    cvReleaseImage(&src);
    cvReleaseImage(&dst);
    // 關閉視窗
    cvDestroyWindow( "src" );
    cvDestroyWindow( "dst" );
    return EXIT_SUCCESS;
}