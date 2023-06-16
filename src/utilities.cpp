#include <silicon/utilities.hpp>

namespace Silicon {
std::string read_file(const char* path) {
  std::string shader_string;

  auto file_stream = std::ifstream(path, std::ios::in);

  if (!file_stream.is_open())
    throw std::runtime_error("failed to read shader source");

  std::stringstream string_stream;
  string_stream << file_stream.rdbuf();

  file_stream.close();

  return string_stream.str();
}
} // namespace Silicon