#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
using namespace std;

int main (int argc, char** argv)
{
    vector<float> v;
    for(int i=1;i<5;i++)
        v.push_back(i);
    vector<float>::iterator iter=std::find(v.begin(),v.end(),6.0);//返回的是一个迭代器指针
    cout<<*iter<<endl;
    cout<<*v.begin()<<endl;
    cout<<*(v.end()-1)<<endl;
    cout<<"bool: "<<(std::find(v.begin(),v.end(),2.1) == v.end())<<endl;
    if(iter==v.end())
        cout<<"ERROR!"<<endl;
    //注意迭代器指针输出元素的方式和distance用法
    else
        cout<<"the index of value "<<(*iter)<<" is " << std::distance(v.begin(), iter)<<std::endl;
    return 0;

    pcl::PointCloud<pcl::PointXYZ> cloud;

// Fill in the cloud data
    cloud.width = 5;
    cloud.height = 1;
    cloud.is_dense = false;
    cloud.points.resize (cloud.width * cloud.height);

    for (size_t i = 0; i < cloud.points.size (); ++i)
    {
        cloud.points[i].x = 1024 * rand () / (RAND_MAX + 1.0f);
        cloud.points[i].y = 1024 * rand () / (RAND_MAX + 1.0f);
        cloud.points[i].z = 1024 * rand () / (RAND_MAX + 1.0f);
    }

    cout<<"savePCDFileASCII"<<endl;
    pcl::io::savePCDFileASCII ("test_pcd.pcd", cloud);
    cout<<"savePCDFileASCII finish"<<endl;

    std::cerr << "Saved " << cloud.points.size () << " data points to test_pcd.pcd." << std::endl;

    for (size_t i = 0; i < cloud.points.size (); ++i)
        std::cerr << " " << cloud.points[i].x << " " << cloud.points[i].y << " " << cloud.points[i].z << std::endl;

    return (0);
}
