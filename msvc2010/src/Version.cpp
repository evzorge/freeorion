#include "../../util/Version.h"

namespace {
    static const std::string retval = "v0.4 [SVN 4599] MSVC 2010";
}

const std::string& FreeOrionVersionString()
{ return retval; }
