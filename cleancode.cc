#include <cassert>
#include <iostream>
#include <string>

namespace {

  bool hasTag(const std::string& line, const std::string& tag) {
    return line.find(tag) != std::string::npos;
  }

  enum class State {
    Outside,
    InsideRemove,
    InsideKeep,
  };

}

int main() {
  using namespace std::string_literals;

  std::string line;
  std::size_t count = 0;
  bool keep = true;
  State state = State::Outside;

  for (std::string line; std::getline(std::cin, line); ) {
    ++count;

    if (hasTag(line, "<<<<"s)) {
      if (state != State::Outside) {
        std::cerr << "An opening tag was wrongly detected on line " << count << '\n';
      }

      state = State::InsideRemove;
      keep = false;
    } else if (hasTag(line, ">>>>"s)) {
      if (state != State::InsideRemove && state != State::InsideKeep) {
        std::cerr << "A closing tag was wrongly detected on line " << count << '\n';
      }

      state = State::Outside;
      keep = true;
    } else if (hasTag(line, "====")) {
      if (state != State::InsideRemove) {
        std::cerr << "A middle tag was wrongly detected on line " << count << '\n';
      }

      state = State::InsideKeep;
      keep = true;
    } else if (keep) {
      if (state != State::Outside && state != State::InsideKeep) {
        std::cerr << "Line kept while not outside tags on line " << count << '\n';
      }

      std::cout << line << '\n';
    }
  }

  if (state != State::Outside) {
    std::cerr << "Missing closing tag at the end of the file\n";
  }

  return 0;
}
