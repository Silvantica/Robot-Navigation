#pragma once
#include <exception>
struct InvalidGridException : public std::exception {
  const char* what() const noexcept;
};
