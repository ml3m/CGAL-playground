#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Mesh_triangulation_3.h>
#include <CGAL/Mesh_complex_3_in_triangulation_3.h>
#include <CGAL/Mesh_criteria_3.h>
#include <CGAL/Labeled_mesh_domain_3.h>
#include <CGAL/make_mesh_3.h>

// Domain
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::FT FT;
typedef K::Point_3 Point;
typedef FT (Function)(const Point&);
typedef CGAL::Labeled_mesh_domain_3<K> Mesh_domain;

#ifdef CGAL_CONCURRENT_MESH_3
typedef CGAL::Parallel_tag Concurrency_tag;
#else
typedef CGAL::Sequential_tag Concurrency_tag;
#endif

// Triangulation
typedef CGAL::Mesh_triangulation_3<Mesh_domain,CGAL::Default,Concurrency_tag>::type Tr;
typedef CGAL::Mesh_complex_3_in_triangulation_3<Tr> C3t3;
// Criteria
typedef CGAL::Mesh_criteria_3<Tr> Mesh_criteria;

// To avoid verbose function and named parameters call
using namespace CGAL::parameters;

// Function
FT cat_function(const Point& p) {
    const double head_radius = 0.5;
    const double body_radius = 0.8;

    // A simple formula to represent a cat shape
    // Combining spheres for head and body with some adjustments
    double head = (p.z() + 1)*(p.z() + 1) + (sqrt(p.x()*p.x() + p.y()*p.y()) - head_radius)*(sqrt(p.x()*p.x() + p.y()*p.y()) - head_radius) - 0.25; // Head
    double body = (p.z() - 0.5)*(p.z() - 0.5) + (sqrt(p.x()*p.x() + p.y()*p.y()) - body_radius)*(sqrt(p.x()*p.x() + p.y()*p.y()) - body_radius) - 0.25; // Body

    // Combined implicit function for a simple cat-like shape
    return head * body;
}

int main()
{
  Mesh_domain domain =
    Mesh_domain::create_implicit_mesh_domain(cat_function,
                                             K::Sphere_3(CGAL::ORIGIN, 4.));
  // Mesh criteria
  Mesh_criteria criteria(facet_angle=30, facet_size=0.1, facet_distance=0.025,
                         cell_radius_edge_ratio=2, cell_size=0.1);

  // Mesh generation
  C3t3 c3t3 = CGAL::make_mesh_3<C3t3>(domain, criteria);
  // Output
  std::ofstream medit_file("cat.mesh");
  c3t3.output_to_medit(medit_file);
  return 0;
}
