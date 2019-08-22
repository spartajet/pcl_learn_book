//
// Created by guoxi on 2019/8/22.
//
#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <armadillo>

using namespace arma;
using namespace std;

int main(int argc, char **argv) {
    pcl::PointCloud<pcl::PointXYZ> cloud;


    mat points_mat;
    points_mat.load("1-1.txt", auto_detect);

// Fill in the cloud data
    cloud.width = 5;
    cloud.height = 1;
    cloud.is_dense = false;
    cloud.points.resize(cloud.width * cloud.height);

    pcl::io::savePCDFileASCII("test_pcd.pcd", cloud);
    std::cerr << "Saved " << cloud.points.size() << " data points to test_pcd.pcd." << std::endl;

    for (size_t i = 0; i < cloud.points.size(); ++i)
        std::cerr << "    " << cloud.points[i].x << " " << cloud.points[i].y << " "
                  << cloud.points[i].z << std::endl;
    system("pause");
    return (0);
}
