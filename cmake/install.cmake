install(
        TARGETS piwm
        EXPORT piwmTargets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
        FILE_SET HEADERS DESTINATION include
)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
        piwmConfigVersion.cmake
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion
)

install(
        EXPORT piwmTargets
        FILE piwmTargets.cmake
        NAMESPACE pi::
        DESTINATION lib/cmake/piwm
)

install(
        FILES
        cmake/piwmConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/piwmConfigVersion.cmake
        DESTINATION lib/cmake/piwm
)
