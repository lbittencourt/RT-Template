#ifndef SCENE_H_
#define SCENE_H_

#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <glm/glm.hpp>

#include "../Primitives/primitive.h"
#include "../Primitives/sphere.h"
#include "../Primitives/triangle.h"

class Scene
{
public:

    Scene( void );

    ~Scene( void );

    bool intersect( const Ray &ray,
                    IntersectionRecord &intersection_record ) const;

    void load( void );

    std::vector< Primitive::PrimitiveUniquePtr > primitives_;

};

#endif /* SCENE_H_ */

