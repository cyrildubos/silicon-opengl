#include <iostream>

#include <silicon/application.hpp>

int main() {
  std::cout << "Hello, World!" << std::endl;

  Silicon::Application application(1280, 720, "Application");

  application.run();

  return 0;
}