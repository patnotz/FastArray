// Copyright 2011 Patrick K. Notz
#include <fa_autoversion.hpp>
#include <fa_version.hpp>
#include <string>

namespace fa {
std::string version() {
  std::string v = "v";
  return v + FA_VERSION;
}
}  // namespace clu
