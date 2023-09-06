cmake_minimum_required(VERSION 3.7...3.27)  # Aggiornare alla versione minima di CMake necessaria

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
    cmake_policy(VERSION 3.27)
endif()

if(${CMAKE_VERSION} VERSION_GREATER 3.9)
     include(cmake/InterproceduralOptimization.cmake)
     tclang_enable_ipo()
endif()

find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
    set(CMAKE_CXX_COMPILER_LAUNCHER "${CCACHE_PROGRAM}")
    if(${CMAKE_VERSION} VERSION_GREATER 3.9)
        set(CMAKE_CUDA_COMPILER_LAUNCHER "${CCACHE_PROGRAM}") # CMake 3.9+
    endif()
else()
    message(STATUS "chache notfound")
endif()

function(print)
    foreach(var ${ARGN})
        message(STATUS "${var} = ${${var}}")
    endforeach()
endfunction()
function(print_env)
    foreach(var ${ARGN})
        message(STATUS "${var} = ${${var}}")
    endforeach()
endfunction()
# Abilita Ricaricamento rapido per i compilatori MSVC, se supportato.
if (POLICY CMP0126)
cmake_policy(SET CMP0126 NEW)
endif()
if (POLICY CMP0127)
cmake_policy(SET CMP0127 NEW)
endif()
if (POLICY CMP0128)
cmake_policy(SET CMP0128 NEW)
endif()
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

include(Dependencies.cmake)
tclang_setup_dependencies()
project(tclang VERSION 0.1.0 LANGUAGES C CXX)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_GENERATOR_PLATFORM x64)
set(CMAKE_MESSAGE_LOG_LEVEL VERBOSE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# Set the output directory for executables (e.g., .exe files)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)

# If you want to also set the output directory for object files (.obj files), you can use:
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)
print(PROJECT_NAME CMAKE_OBJECT_OUTPUT_DIRECTORY)

# Aggiungere i file sorgente al progetto
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.c" "src/*.h")

# Aggiungere l'eseguibile
add_executable(${PROJECT_NAME} ${SOURCES})

# Set the optimization level to -Ox for all configurations
if (MSVC)
    target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_${CMAKE_CXX_STANDARD})
    target_compile_options(${PROJECT_NAME}
        PRIVATE
        $<$<CONFIG:Release>:/Oy>
        $<$<CONFIG:MinSizeRel>:/Oy>
        $<$<CONFIG:RelWithDebInfo>:/Oy>
    )
    target_compile_options(${PROJECT_NAME}
        PRIVATE
        $<$<CONFIG:Release>:/Ox>
        $<$<CONFIG:MinSizeRel>:/Ox>
        $<$<CONFIG:RelWithDebInfo>:/Ox>
    )
    target_compile_options(${PROJECT_NAME}
        PRIVATE
        $<$<CONFIG:Release>:/GL>
        $<$<CONFIG:MinSizeRel>:/GL>
    )
    message(STATUS "Warnings are treated as errors")
    target_compile_options(${PROJECT_NAME} PRIVATE
        /EHa
        /Oi
        /MP  # Enable Multi-Processor Compilation
        /FC
        /W4  # Set warning level to 4
        /WX  # Treat warnings as errors
        /permissive-  # Standards conformance mode for MSVC compiler
        /w14242  # Disable warning 14242 'identifier': conversion from 'type1' to 'type2', possible loss of data
        /w14254  # Disable warning 14254 'operator': conversion from 'type1:field_bits' to 'type2:field_bits', possible loss of data
        /w14263  # Disable warning 14263 'function': member function does not override any base class virtual member function
        /w14265  # Disable warning 14265 'classname': class has virtual functions, but destructor is not virtual instances of this class may not 
                 # be destructed correctly
        /w14287  # Disable warning 14287 'operator': unsigned/negative constant mismatch
        /we4289  # Disable warning 4289 nonstandard extension used: 'variable': loop control variable declared in the for-loop is used outside the 
                 # for-loop scope
        /w14296  # Disable warning 14296 'operator': expression is always 'boolean_value'
        /w14311  # Disable warning 14311 'variable': pointer truncation from 'type1' to 'type2'
        /w14545  # Disable warning 14545 expression before comma evaluates to a function which is missing an argument list
        /w14546  # Disable warning 14546 function call before comma missing argument list
        /w14547  # Disable warning 14547 'operator': operator before comma has no effect; expected operator with side-effect
        /w14549  # Disable warning 14549 'operator': operator before comma has no effect; did you intend 'operator'?
        /w14555  # Disable warning 14555 expression has no effect; expected expression with side- effect
        /w14619  # Disable warning 14619 pragma warning: there is no warning number 'number'
        /w14640  # Disable warning 14640 Enable warning on thread un-safe static member initialization
        /w14826  # Disable warning 14826 Conversion from 'type1' to 'type2' is sign-extended. This may cause unexpected runtime behavior.
        /w14905  # Disable warning 14905 wide string literal cast to 'LPSTR'
        /w14906  # Disable warning 14906 string literal cast to 'LPWSTR'
        /w14928  # Disable warning 14928 illegal copy-initialization; more than one user-defined conversion has been implicitly applied
        /wd4996  # Disable comaptibilty whit c++98
    )
    
    target_link_options(${PROJECT_NAME} 
       PRIVATE
        $<$<CONFIG:Release>:/LTCG>
        $<$<CONFIG:MinSizeRel>:/LTCG>
    )
endif()
target_compile_definitions(${PROJECT_NAME}
    PRIVATE
    $<$<CONFIG:Debug>:WL_DEBUG;SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_DEBUG>
    $<$<CONFIG:Release>:WL_RELEASE;SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_TRACE>
)

target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)
