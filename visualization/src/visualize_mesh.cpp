#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/features/normal_3d.h>
#include <pcl/surface/gp3.h>
#include <pcl/io/vtk_io.h>
#include <pcl/io/vtk_lib_io.h>
#include <pcl/visualization/pcl_visualizer.h>

#include <boost/shared_ptr.hpp>
#include <string>
#include <cassert>

int main (int argc, char* argv[]) {
    // Loading VTK filename
    assert(argc >= 2);
    std::string vtk_filename(argv[1]);

    pcl::PolygonMesh mesh;
    pcl::io::loadPolygonFileVTK(vtk_filename, mesh);

    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer (new pcl::visualization::PCLVisualizer ("Mesh Visualization"));
    viewer->setBackgroundColor (0, 0, 0);
    viewer->addPolygonMesh(mesh, "meshes", 0);
    viewer->addCoordinateSystem (1.0);
    viewer->initCameraParameters();
    
    while (!viewer -> wasStopped()) {
        viewer->spinOnce(100);
        boost::this_thread::sleep(boost::posix_time::microseconds (100000));
    }
    
    return 0;
}
