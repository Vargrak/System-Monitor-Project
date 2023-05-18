# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/SystemResourceMonitor_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/SystemResourceMonitor_autogen.dir/ParseCache.txt"
  "SystemResourceMonitor_autogen"
  )
endif()
