add_executable(aero_sim_exe main.cpp geometry/Geometry.cpp geometry/Geometry.h state.h geometry/Enclosure.cpp geometry/Enclosure.h geometry/add_shapes.cpp geometry/add_shapes.h Application.cpp Application.h meshing/Meshing.cpp meshing/Meshing.h)
target_link_libraries(aero_sim_exe PRIVATE ImGui-SFML::ImGui-SFML)

# Copy DLLs needed for runtime on Windows
if(WIN32)
  if (BUILD_SHARED_LIBS)
    add_custom_command(TARGET aero_sim_exe POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy_if_different
          $<TARGET_FILE:ImGui-SFML::ImGui-SFML>
          $<TARGET_FILE:sfml-graphics>
          $<TARGET_FILE:sfml-window>
          $<TARGET_FILE:sfml-system>
          $<TARGET_FILE_DIR:aero_sim_exe>)
  endif()
endif()