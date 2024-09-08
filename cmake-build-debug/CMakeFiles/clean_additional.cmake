# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QcloudObj_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QcloudObj_autogen.dir\\ParseCache.txt"
  "QcloudObj_autogen"
  )
endif()
