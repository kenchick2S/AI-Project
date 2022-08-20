#include<opencv2/opencv.hpp>
#include<iostream>


void maxloc(cv::Mat A , float *max, cv::Point *max_loc){
    double temp = 0.0;
    for(int i=0; i<A.rows; i++){
        for(int j=0; j<A.cols; j++){
            if(i != j){
                if(std::abs(A.ptr<float>(i)[j]) > std::abs(temp)){
                    temp = A.ptr<float>(i)[j];
                    (*max_loc).x = i;
                    (*max_loc).y = j;
                }
            }
        }
    }
    *max = temp;
}

void SVD(cv::Mat A, cv::Mat U, cv::Mat S, cv::Mat Vt){
        int m = A.rows, n = A.cols, temp;
        //std::cout << m << "," << n << std::endl;
        if(m < n){
            temp = m;
            m = n;
            n = temp;
        }
        else{
            //cv::transpose(A, A);
        }
        U = cv::Mat::zeros(cv::Size(m, m), CV_32FC1);
        S = cv::Mat::zeros(cv::Size(n, 1), CV_32FC1);
        Vt = cv::Mat::zeros(cv::Size(n, n), CV_32FC1);

        cv::Mat A_t = cv::Mat::zeros(cv::Size(m, m), CV_32FC1);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                A_t.ptr<float>(i)[j] =  A.ptr<float>(i)[j];
            }
        }
        // std::cout<< A_t.rowRange(m-2, m) << std::endl;

        float max;
        cv::Point max_loc;
        float theta, cos, sin;
        cv::Mat A_new = cv::Mat::zeros(cv::Size(m, m), CV_32FC1);
        // std::cout<< A_t.ptr<float>(max_loc.x)[max_loc.y] <<", "<< max <<std::endl;
        for(int i=0; i<std::max(m, 30); i++){
            maxloc(A_t , &max, &max_loc);
            //std::cout<<"max: "<< max <<std::endl;
            //std::cout<<"max: "<< max_loc <<std::endl;
            theta = std::atan2(2*A_t.ptr<float>(max_loc.x)[max_loc.y], A_t.ptr<float>(max_loc.x)[max_loc.x]-A_t.ptr<float>(max_loc.y)[max_loc.y])*0.5;
            cos = std::cos(theta);
            sin = std::sin(theta);
            //std::cout<<"theta: "<< theta <<std::endl;
            //std::cout<<"sin: "<< sin <<std::endl;
            A_t.copyTo(A_new);

            for(int j=0; j<m; j++){
                 A_new.ptr<float>(j)[max_loc.x] = cos*A_t.ptr<float>(j)[max_loc.x] + sin*A_t.ptr<float>(j)[max_loc.y];
            }
            for(int j=0; j<m; j++){
                 A_new.ptr<float>(j)[max_loc.y] = cos*A_t.ptr<float>(j)[max_loc.y] - sin*A_t.ptr<float>(j)[max_loc.x];
            }
            //std::cout<< A_new <<std::endl;
            //std::cout<<"A_t: "<< A_t <<std::endl;
            A_new.ptr<float>(max_loc.x)[max_loc.x] = cos*A_new.ptr<float>(max_loc.x)[max_loc.x] + sin*A_new.ptr<float>(max_loc.y)[max_loc.x];
            A_new.ptr<float>(max_loc.y)[max_loc.y] = cos*A_new.ptr<float>(max_loc.y)[max_loc.y] - sin*A_new.ptr<float>(max_loc.x)[max_loc.y];
            A_new.ptr<float>(max_loc.x)[max_loc.y] = 0;
            A_new.ptr<float>(max_loc.y)[max_loc.x] = 0;
            

            for(int j=0; j<m; j++){
                for(int k=0; k<m; k++){
                    A_new.ptr<float>(j)[k] = A_new.ptr<float>(k)[j];
                }
            }
            /*for(int k=0; k<m; k++){
                    A_new.ptr<float>(max_loc.y)[k] = A_new.ptr<float>(k)[max_loc.y];
            }*/
            A_new.copyTo(A_t);
            //std::cout<< A_t <<std::endl;
        }
        for(int i=0; i<m; i++){
            std::cout<<A_t.ptr<float>(i)[i]<<" ";
        }
        std::cout<<std::endl;
}
void SVD_1(cv::Mat A, cv::Mat U, cv::Mat S, cv::Mat Vt){
        int m = A.rows, n = A.cols, temp;
        //std::cout << m << "," << n << std::endl;
        if(m < n){
            temp = m;
            m = n;
            n = temp;
        }
        else{
            //cv::transpose(A, A);
        }
        U = cv::Mat::zeros(cv::Size(m, m), CV_32FC1);
        S = cv::Mat::zeros(cv::Size(n, 1), CV_32FC1);
        Vt = cv::Mat::zeros(cv::Size(n, n), CV_32FC1);

        cv::Mat A_t = cv::Mat::zeros(cv::Size(m, m), CV_32FC1);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                A_t.ptr<float>(i)[j] =  A.ptr<float>(i)[j];
            }
        }
        // std::cout<< A_t.rowRange(m-2, m) << std::endl;

        float max;
        cv::Point max_loc;
        float theta, cos, sin;
        cv::Mat A_new = cv::Mat::zeros(cv::Size(m, m), CV_32FC1);
        // std::cout<< A_t.ptr<float>(max_loc.x)[max_loc.y] <<", "<< max <<std::endl;
        for(int i=0; i<std::max(m, 30); i++){
            maxloc(A_t , &max, &max_loc);
            //std::cout<<"max: "<< max <<std::endl;
            //std::cout<<"max: "<< max_loc <<std::endl;
            theta = std::atan2(2*A_t.ptr<float>(max_loc.x)[max_loc.y], A_t.ptr<float>(max_loc.x)[max_loc.x]-A_t.ptr<float>(max_loc.y)[max_loc.y])*0.5;
            cos = std::cos(theta);
            sin = std::sin(theta);
            //std::cout<<"theta: "<< theta <<std::endl;
            //std::cout<<"sin: "<< sin <<std::endl;
            A_t.copyTo(A_new);

            for(int j=0; j<m; j++){
                 A_new.ptr<float>(j)[max_loc.x] = cos*A_t.ptr<float>(j)[max_loc.x] + sin*A_t.ptr<float>(j)[max_loc.y];
            }
            for(int j=0; j<m; j++){
                 A_new.ptr<float>(j)[max_loc.y] = cos*A_t.ptr<float>(j)[max_loc.y] - sin*A_t.ptr<float>(j)[max_loc.x];
            }
            //std::cout<< A_new <<std::endl;
            //std::cout<<"A_t: "<< A_t <<std::endl;
            A_new.ptr<float>(max_loc.x)[max_loc.x] = cos*A_new.ptr<float>(max_loc.x)[max_loc.x] + sin*A_new.ptr<float>(max_loc.y)[max_loc.x];
            A_new.ptr<float>(max_loc.y)[max_loc.y] = cos*A_new.ptr<float>(max_loc.y)[max_loc.y] - sin*A_new.ptr<float>(max_loc.x)[max_loc.y];
            A_new.ptr<float>(max_loc.x)[max_loc.y] = 0;
            A_new.ptr<float>(max_loc.y)[max_loc.x] = 0;
            

            for(int j=0; j<m; j++){
                for(int k=0; k<m; k++){
                    A_new.ptr<float>(j)[k] = A_new.ptr<float>(k)[j];
                }
            }
            /*for(int k=0; k<m; k++){
                    A_new.ptr<float>(max_loc.y)[k] = A_new.ptr<float>(k)[max_loc.y];
            }*/
            A_new.copyTo(A_t);
            //std::cout<< A_t <<std::endl;
        }
        for(int i=0; i<m; i++){
            std::cout<<A_t.ptr<float>(i)[i]<<" ";
        }
        std::cout<<std::endl;
}

int main(int argc, char** argv) {

    cv::Mat src = cv::imread("D:/image/python/lena.jpg", 0);

    cv::Mat result;
    cv::Mat tempt;
    cv::Mat U, S, V;
    cv::Mat U1, S1, V1;
    src.convertTo(tempt, CV_32FC1);
    float mat[3][3] =  {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    cv::Mat temp = cv::Mat::zeros(cv::Size(3, 3), CV_32FC1);
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++)
            temp.ptr<float>(i)[j] = mat[i][j];
    }
    SVD(temp, U1, S1, V1);
    //SVD(tempt, U, S, V);
    cv::SVD::compute(tempt, S, U, V);//SVD分解

    cv::Mat s = cv::Mat::zeros(cv::Size(S.rows, S.rows), CV_32FC1);
    double theratio = 0.1;
    int len = theratio * S.rows;
    for (int i = 0; i < len; ++i) s.ptr<float>(i)[i] = S.ptr<float>(i)[0];

    //std::cout << S.cols; // N rows / 1 cols (Nx1)

    result = U * s * V; 

    std::cout<< S << std::endl;
    cv::Mat outputImg;  
    result.convertTo(outputImg, CV_8UC1);

    cv::imshow("origin", src);
    cv::imshow("compressed", outputImg);

    cv::waitKey(0);
    return 0;
}
