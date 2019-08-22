//
// Created by guoxi on 2019/8/22.
//
#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <armadillo>
#include<pcl\visualization\cloud_viewer.h> 

using namespace arma;
using namespace std;

int main(int argc, char **argv) {
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);

	cout << "start read txt" << endl;
    mat points_mat;
    points_mat.load("1-1.txt", auto_detect);
    const int points_count = points_mat.n_rows;
// Fill in the cloud data
    cloud->width = points_count;
    cloud->height = 1;
    cloud->is_dense = false;
    cloud->points.resize(points_count);
    for (int i = 0; i < points_count; ++i)
    {
		cloud->points[i].x = points_mat(i, 0);
		cloud->points[i].y = points_mat(i, 1);
		cloud->points[i].z = points_mat(i, 2);
		cloud->points[i].r = 255;
		cloud->points[i].g = 0;
		cloud->points[i].b = 0;
    }
	pcl::visualization::CloudViewer viewer("Cloud Viewer");//创建viewer对象 
	viewer.showCloud(cloud);//将pcb与viewer对象联系起来
	while (!viewer.wasStopped())//要想让自己所创窗口一直显示，则加上 while (!viewer.wasStopped()){ };即可.
	{
		Sleep(2000);
	}

	cout << "write pcd file" << endl;
    pcl::io::savePCDFileASCII("test_pcd.pcd", *cloud);
    std::cerr << "Saved " << cloud->points.size() << " data points to test_pcd.pcd." << std::endl;


    system("pause");
    return (0);
}
