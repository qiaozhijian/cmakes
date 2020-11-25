//
// Created by qzj on 2020/11/25.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <vector>
#include "opencv2/core.hpp"

using namespace std;
void loadIMUOdo(const string& path, vector<cv::Point3f>& vIMU, vector<cv::Point3f>& vACC, vector<cv::Point2f>& vEncoder);
void loadTimeStamp(const string& path, vector<uint64_t>& vTimeData);

int main(){
    int size = 2;
    float data[size];

    for(int i=0; i<size; i++){
        data[i] = i;
    }
    // save
    std::ofstream outF("test.bin", std::ios::binary);
    outF.write(reinterpret_cast<char*>(data), sizeof(data));
    outF.close();

    std::cout << "write file" << std::endl;
    for(int i=0; i<size; i++){
        std::cout << i << ": "<< data[i] << std::endl;
    }
    vector<cv::Point3f> vIMU;
    vector<cv::Point3f> vACC;
    vector<cv::Point2f> vEncoder;
    loadIMUOdo("imu_odo.bin",vIMU,vACC,vEncoder);


    vector<uint64_t> vTimeData;
    loadTimeStamp("timeStamp.bin",vTimeData);

    return 0;
}

void loadIMUOdo(const string& path, vector<cv::Point3f>& vIMU, vector<cv::Point3f>& vACC, vector<cv::Point2f>& vEncoder)
{
    std::ifstream cntF(path, std::ios::binary);
    cntF.seekg(0, ios::end);
    uint64_t size = cntF.tellg() / sizeof(float);
    cntF.close();

    float rData[size];
    std::ifstream inF(path, std::ios::binary);
    inF.read((char*)rData, sizeof(float) * size);
    inF.close();

    int sizeMsg = size / 8;
    vIMU.clear();
    vACC.clear();
    vEncoder.clear();
    for(int i=0;i<sizeMsg;i++)
    {
        vIMU.push_back(cv::Point3f(rData[i*8+0],rData[i*8+1],rData[i*8+2]));
        vACC.push_back(cv::Point3f(rData[i*8+3],rData[i*8+4],rData[i*8+5]));
        vEncoder.push_back(cv::Point2f(rData[i*8+6],rData[i*8+7]));
    }

    return;
}


void loadTimeStamp(const string& path, vector<uint64_t>& vTimeData)
{
    std::ifstream cntF(path, std::ios::binary);
    cntF.seekg(0, ios::end);
    uint64_t size = cntF.tellg() / sizeof(uint64_t);
    cntF.close();

    uint64_t rData[size];
    std::ifstream inF(path, std::ios::binary);
    inF.read((char*)rData, sizeof(uint64_t) * size);
    inF.close();

    vTimeData.clear();
    for(int i=0;i<size;i++)
    {
        vTimeData.push_back(rData[i]);
    }

    return;
}

