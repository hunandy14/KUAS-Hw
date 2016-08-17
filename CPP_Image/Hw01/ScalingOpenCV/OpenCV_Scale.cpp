/**********************************************************
Name : 
Date : 2016/08/12
By   : CharlotteHonG
Final: 2016/08/12
**********************************************************/
#define Ratio 5
#include <opencv.hpp>

int main(int argc, char const *argv[]){
    // �Y�񭿲v
    float scale = Ratio;
    // �Ыصe��
    IplImage *src = 0;
    IplImage *dst = 0;
    // ���J�Ϥ�
    src = cvLoadImage("IMG.JPG");
    // �e���j�p
    CvSize dst_cvsize;
    dst_cvsize.width = (int)(src->width * scale);
    dst_cvsize.height = (int)(src->height * scale);
    // �Ыؼv��
    dst = cvCreateImage( dst_cvsize, src->depth, src->nChannels);

    // �վ�v���j�p
    // cvResize(src,dst,CV_INTER_NN); // CV_INTER_NN - �̾F�񴡭�
    cvResize(src,dst,CV_INTER_LINEAR); // CV_INTER_LINEAR - ���u�ʴ���
    // cvResize(src,dst,CV_INTER_AREA); //CV_INTER_AREA - �������Y���ļ�(�Y�p�i�קK�i��)
    // cvResize(src,dst,CV_INTER_CUBIC); //CV_INTER_CUBIC - �ߤ贡��

    // �ץX�Ϥ�
    cvSaveImage("IMG_OUT.jpg", dst);
    // �}�ҹϤ�
    cvNamedWindow("IMG - src", CV_WINDOW_AUTOSIZE );
    cvNamedWindow("IMG - dst", CV_WINDOW_AUTOSIZE );
    cvShowImage("IMG - src", src);
    cvShowImage("IMG - dst", dst);
    // ���ݫ����J
    cvWaitKey(0);
    // ����O����
    cvReleaseImage(&src);
    cvReleaseImage(&dst);
    // ��������
    cvDestroyWindow( "src" );
    cvDestroyWindow( "dst" );
    return EXIT_SUCCESS;
}