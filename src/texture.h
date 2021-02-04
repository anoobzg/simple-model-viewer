#ifndef _TEXTURE_H
#define _TEXTURE_H
#include <string>

#include "glad/glad.h"
#include "stb_image.h"

class Texture {
 public:
  GLuint id;

  Texture() {
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glBindTexture(GL_TEXTURE_2D, 0);
  }
  Texture(const std::string& filepath) : Texture() { loadImage(filepath); }
  ~Texture() { glDeleteTextures(1, &id); }

  void loadImage(const std::string& filepath) const {
    // load image
    int width, height, channels;
    unsigned char* image =
        stbi_load(filepath.c_str(), &width, &height, &channels, 3);

    // send image to texture
    glBindTexture(GL_TEXTURE_2D, id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
                 GL_UNSIGNED_BYTE, image);
    glBindTexture(GL_TEXTURE_2D, 0);

    stbi_image_free(image);
  }
};

#endif