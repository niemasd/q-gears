include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# define header and source files
set(HEADER_FILES
./src/engine/SoundManager.h
./src/engine/SoundBackend.h
./src/engine/backends/SoundBackendSDL.h
./src/SoundParser.h
./src/Main.h
)

set(SOURCE_FILES
./src/engine/backends/SoundBackendSDL.cpp
./src/engine/SoundManager.cpp
./src/SoundParser.cpp
./src/Main.cpp
)

add_definitions(
    -DQGEARS_ADD_MANAGERS
)

add_executable(xeno_sound_dumper
  ${HEADER_FILES}
  ${SOURCE_FILES}
)
SET_PROPERTY(TARGET xeno_sound_dumper PROPERTY FOLDER "utilities")

if (APPLE)
target_link_libraries(xeno_sound_dumper "-framework CoreFoundation -framework Cocoa -framework IOKit")
endif()

if(WIN32)
  set_target_properties(xeno_sound_dumper PROPERTIES WIN32_EXECUTABLE ON)
  if (MSVC)
    set_target_properties(xeno_sound_dumper PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
  endif()
endif()

set(LIBRARIES
    Utility
    QGearsMain
    q-gears-data
)
target_link_libraries(xeno_sound_dumper    ${LIBRARIES})

install(TARGETS xeno_sound_dumper
    DESTINATION tools/xeno
)
