#ifndef triangulation_h_
#define triangulation_h_

#include <vector>
#include "camera/pinhole_camera.h"
#include "sfm/track.h"
#include "sfm/structure_point.h"
#include "sfm/graph.h"

using std::vector;
using std::pair;

namespace open3DCV {
    
    // DLT
    void triangulate_linear(const vector<Mat34f>& poses, const vector<Vec2f>& pts, Vec3f& pt3d);
    void triangulate_linear(const vector<Mat34f>& poses, const vector<Keypoint>& keys, Vec3f& pt3d);
    void triangulate_linear(const vector<Mat34f>& poses, const Track& track, Structure_Point& struct_pts);
//    void triangulate_linear(const vector<PinholeCamera>& cameras, Graph& graph);
    
    // mid-point algorithm
    void triangulate_midpoint(const vector<Vec3f>& centers, const vector<Vec3f>& directions, const vector<Vec2f>& pts, Vec3f& pt3d);
//    void triangulate_midpoint(const vector<PinholeCamera>& cameras, const vector<Keypoint>& keys, Vec3f& pt3d);
//    void triangulate_midpoint(const vector<PinholeCamera>& cameras, const Track& track, Structure_Point& struct_pts);
    
    // minimizing the sampsen error
    void triangulate_nonlinear(Graph& graph);
    void triangulate_nonlinear(const vector<Mat34f>& poses, const vector<Vec2f>& pts, Vec3f& pt3d);
    void triangulate_nonlinear(const vector<Mat34f>& poses, const vector<Keypoint>& keys, Vec3f& pt3d);
    void triangulate_nonlinear(const vector<Mat34f>& poses, const Track& track, Structure_Point& struct_pts);
    void triangulate_nonlinear(const vector<Mat34f>& poses, const vector<pair<Vec2f, Vec2f> >& pts, vector<Vec3f>& pts3d); // 2-view
    void triangulate_nonlinear(const vector<Mat34f>& poses, const vector<DMatch>& pts, vector<Vec3f>& pts3d);
    void triangulate_nonlinear(const vector<Mat34f>& poses, const vector<Track>& tracks, vector<Structure_Point>& struct_pts);
    void residule(const Vec3f& pt3d, const vector<Vec2f>& pts, const vector<Mat34f>& Q, Vecf& e, Matf& J);
    
    // angular triangulation
    void triangulate_angular(const vector<Mat34f>& poses, const vector<Vec2f>& pts, Vec3f& pt3d);
//    void triangulate_angular(const vector<PinholeCamera>& cameras, const Track& track, Structure_Point& struct_pts);
    
    // reprojection error
    float reprojection_error(const Graph& graph);
    
    //! Recker et. al '12 angular triangulation
    /*!
     * Computes the 3D scene structure using the algorithm proposed in
     * WACV '12 by Recker et. al. This implementation uses a midpoint start
     * and also uses an adaptive gradient descent for optimization. This
     * implementation also does not compute the statistical sample used
     * in the paper.  The sample should be computed prior to calling this
     * function.
     * \param cameras The collection of cameras
     * \param track The feature track for the 3D point
     * \return The 3D computed scene point
     */
//    StructurePoint angular(const vector<PinholeCamera> &cameras, const FeatureTrack &track) const;
//    Vector3d angular_gradient(const vector<PinholeCamera> &cameras, const FeatureTrack& track, const Vector3d &point) const;

}


#endif // triangulation_h_
