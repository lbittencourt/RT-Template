#include "main.h"

int main( void )
{
    unsigned int x_resolution = 512;
    unsigned int y_resolution = 512;

    PinholeCamera camera{   -1.25f, 
                            1.25f, 
                            -1.25f, 
                            1.25f,
                            2.0f,
                            glm::ivec2{ x_resolution, y_resolution }, 
                            glm::vec3{ 0.0f, 0.0f,  1.0f },     // position
                            glm::vec3{ 0.0f, 1.0f,  0.0f },     // up
                            glm::vec3{ 0.0f, 0.0f, -1.0f } };   // look at
    Scene scene{};
    
    scene.load();

    Buffer rendering_buffer{ x_resolution, y_resolution };
    glm::vec3 background_color{ 0.0f, 0.0f, 0.0f };

    // Set up the renderer.
    RayTracer rt( camera,
                  scene,
                  background_color,
                  rendering_buffer );

    rt.integrate(); // Renders the final image.

    // Save the rendered image to a .ppm file.
    std::string path = "/home/lbittencourt/Documentos/Coding/C++/RT-Template/outputs/";
    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    std::string timestamp = asctime(timeinfo);
    rendering_buffer.save( path + timestamp + ".ppm" );

    return EXIT_SUCCESS;
}

