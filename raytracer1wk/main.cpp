#include <iostream>

int main()
{
	int width = 256;
	int height = 256;

	std::cout << "P3\n" << width << " " << height << "\n255\n";
	for (auto j = 0;j < height;j++) {
		std::clog << "\rScanlines remaining: " << (height - j) << " ";
		for (auto i = 0;i < width;i++) {
			auto r = double(i) / (width - 1);
			auto g = double(j) / (height - 1);
			auto b = 0.5;

			int ir = static_cast<int>(255.999 * r);
			int ig = static_cast<int>(255.999 * g);
			int ib = static_cast<int>(255.999 * b);

			std::cout << ir << " " << ig << " " << ib << std::endl;
		}
	}
	std::clog << "\rDone                     \n";
}