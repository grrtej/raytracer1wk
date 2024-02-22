#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main()
{
	std::ifstream ppmfile("out.ppm");
	std::string magic;
	ppmfile >> magic;

	int width, height, maxval;
	ppmfile >> width >> height >> maxval;

	std::cout << "magic = " << magic << std::endl;
	std::cout << "width = " << width << std::endl;
	std::cout << "height = " << height << std::endl;
	std::cout << "maxval = " << maxval << std::endl;

	std::vector<std::uint8_t> pixels;
	for (auto j = 0;j < height;j++) {
		for (auto i = 0;i < width;i++) {
			int r, g, b;
			ppmfile >> r >> g >> b;

			pixels.push_back(r);
			pixels.push_back(g);
			pixels.push_back(b);
		}
	}

	stbi_write_jpg("out.jpg", width, height, 3, pixels.data(), 90);
	std::cout << "created jpg from ppm" << std::endl;
}