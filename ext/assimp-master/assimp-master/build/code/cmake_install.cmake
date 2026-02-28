# Install script for directory: C:/projects/MM1/extern/assimp-master/assimp-master/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Assimp")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/mingw64/bin/objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libassimp6.0.2-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/projects/MM1/extern/assimp-master/assimp-master/build/lib/libassimp.dll.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libassimp6.0.2" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/projects/MM1/extern/assimp-master/assimp-master/build/bin/libassimp-6.dll")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libassimp-6.dll" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libassimp-6.dll")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "C:/mingw64/bin/strip.exe" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libassimp-6.dll")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "assimp-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/anim.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/aabb.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/ai_assert.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/camera.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/color4.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/color4.inl"
    "C:/projects/MM1/extern/assimp-master/assimp-master/build/code/../include/assimp/config.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/ColladaMetaData.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/commonMetaData.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/defs.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/cfileio.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/light.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/material.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/material.inl"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/matrix3x3.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/matrix3x3.inl"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/matrix4x4.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/matrix4x4.inl"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/mesh.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/ObjMaterial.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/pbrmaterial.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/GltfMaterial.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/postprocess.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/quaternion.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/quaternion.inl"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/scene.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/metadata.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/texture.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/types.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/vector2.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/vector2.inl"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/vector3.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/vector3.inl"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/version.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/cimport.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/AssertHandler.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/importerdesc.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/Importer.hpp"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/DefaultLogger.hpp"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/ProgressHandler.hpp"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/IOStream.hpp"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/IOSystem.hpp"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/Logger.hpp"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/LogStream.hpp"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/NullLogger.hpp"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/cexport.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/Exporter.hpp"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/DefaultIOStream.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/DefaultIOSystem.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/ZipArchiveIOSystem.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/SceneCombiner.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/fast_atof.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/qnan.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/BaseImporter.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/Hash.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/MemoryIOWrapper.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/ParsingUtils.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/StreamReader.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/StreamWriter.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/StringComparison.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/StringUtils.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/SGSpatialSort.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/GenericProperty.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/SpatialSort.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/SkeletonMeshBuilder.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/SmallVector.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/SmoothingGroups.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/SmoothingGroups.inl"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/StandardShapes.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/RemoveComments.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/Subdivision.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/Vertex.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/LineSplitter.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/TinyFormatter.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/Profiler.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/LogAux.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/Bitmap.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/XMLTools.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/IOStreamBuffer.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/CreateAnimMesh.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/XmlParser.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/BlobIOSystem.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/MathFunctions.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/Exceptional.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/ByteSwapper.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/Base64.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "assimp-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/Compiler/pushpack1.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/Compiler/poppack1.h"
    "C:/projects/MM1/extern/assimp-master/assimp-master/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "C:/projects/MM1/extern/assimp-master/assimp-master/build/code/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
