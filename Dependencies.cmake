include(cmake/CPM.cmake)

# Done as a function so that updates to variables like
# CMAKE_CXX_FLAGS don't propagate out to other
# targets
function(tclang_setup_dependencies)

  if(NOT TARGET spdlog::spdlog)
    cpmaddpackage(
      NAME
      spdlog
      VERSION
      1.12.0
      GITHUB_REPOSITORY
      "gabime/spdlog"
      OPTIONS
      "SPDLOG_USE_STD_FORMAT ON"
      "SPDLOG_ENABLE_PCH ON"
      "SPDLOG_BUILD_PIC ON"
      "SPDLOG_WCHAR_SUPPORT ON"
      "SPDLOG_WCHAR_FILENAMES ON"
      "SPDLOG_BUILD_WARNINGS ON")
  endif()

endfunction()
