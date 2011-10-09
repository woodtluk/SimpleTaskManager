PROJECT(SimpleTaskManager)

cmake_minimum_required(VERSION 2.8)

SET(QT_MIN_VERSION "4.2.0")

#                           absolut                   relative
# project source dir:     ${CMAKE_SOURCE_DIR}       ${CMAKE_CURRENT_SOURCE_DIR}
# build dir:              ${CMAKE_BINARY_DIR}       ${CMAKE_CURRENT_BINARY_DIR}

SET(CMAKE_BUILD_TYPE Debug)

#MESSAGE("PROJECT_NAME=${PROJECT_NAME}")
#MESSAGE("PROJECT_SOURCE_DIR=${PROJECT_SOURCE_DIR}")
#MESSAGE("PROJECT_BINARY_DIR=${PROJECT_BINARY_DIR}")
#MESSAGE("CMAKE_SOURCE_DIR=${CMAKE_SOURCE_DIR}")
#MESSAGE("CMAKE_BINARY_DIR=${CMAKE_BINARY_DIR}")

# Version
SET(SimpleTaskManager_VERSION_MAJOR 0)
SET(SimpleTaskManager_VERSION_MINOR 1)

# config.h file
configure_file (
  "${PROJECT_SOURCE_DIR}/src/Config.h.in"
  "${PROJECT_BINARY_DIR}/Config.h"
)

# add the binary tree to the search path for include files
# so that we will find Config.h
# add the source dir to include directory so that the generated source
# files from uic find custom widgets that are promoted to in the designer
include_directories("${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}")

# enable warnings
#ADD_DEFINITIONS( -c -g -Wall -frtti -fexceptions -mthreads -enable-stdcall-fixup -Wl,-enable-auto-import -Wl,-enable-runtime-pseudo-reloc)
#SET(CMAKE_CXX_FLAGS "-Wall")

# enable warnings
IF(CMAKE_COMPILER_IS_GNUCXX )
  ADD_DEFINITIONS( -g -Wall )
ENDIF(CMAKE_COMPILER_IS_GNUCXX )

IF(MSVC)
  ADD_DEFINITIONS(-DQT_DLL -Wall)
ENDIF(MSVC)

# Set some Win32 Specific Settings
IF(WIN32)
 SET(GUI_TYPE WIN32)
ENDIF(WIN32)

#   if(CMAKE_CONFIGURATION_TYPES)
#     #set(CMAKE_CONFIGURATION_TYPES Debug Release DebugMX31 ReleaseMX31)
#     set(CMAKE_CONFIGURATION_TYPES Debug Release)
#     set(CMAKE_CONFIGURATION_TYPES "${CMAKE_CONFIGURATION_TYPES}" CACHE STRING
#       "Reset the configurations to what we need"
#       FORCE)
#   endif()

# this command finds Qt4 libraries and sets all required variables
# note that it's Qt4, not QT4 or qt4
FIND_PACKAGE( Qt4 REQUIRED )

IF(NOT QT4_FOUND)
  MESSAGE(SEND_ERROR "Failed to find Qt 4.3 or greater.")
ELSE(NOT QT4_FOUND)

# don't know exactly what that is
#SET(CMAKE_PACKAGE_QTGUI TRUE)
# i don't want to install or package the qt gui on windows
# unless qt is static
#IF(WIN32 AND NOT QT_CONFIG MATCHES "static")
#  SET(CMAKE_PACKAGE_QTGUI FALSE)
#ENDIF(WIN32 AND NOT QT_CONFIG MATCHES "static")


# add some useful macros and variables
# (QT_USE_FILE is a variable defined by FIND_PACKAGE( Qt4 ) that contains a path to CMake script)
INCLUDE( ${QT_USE_FILE} )


# by default only QtCore and QtGui modules are enabled
# other modules must be enabled like this:

#SET(
  #QT_USE_QTXML                 TRUE
  # QT_USE_QTASSISTANT           TRUE
  # QT_USE_QAXCONTAINER         TRUE
  # QT_USE_QAXSERVER            TRUE
  #QT_USE_QTDESIGNER           TRUE
  # QT_USE_QTMOTIF              TRUE
  #QT_USE_QTMAIN               TRUE
  # QT_USE_QTNETWORK          TRUE
  # QT_USE_QTNSPLUGIN         TRUE
  # QT_USE_QTOPENGL         TRUE
  # QT_USE_QTSQL          TRUE
  # QT_USE_QTXML          TRUE
  #QT_USE_QTSVG          TRUE
  #QT_USE_QTTEST         TRUE
  #QT_USE_QTUITOOLS          TRUE
  #  QT_USE_QTDBUS         TRUE
  # QT_USE_QTSCRIPT         TRUE
  # QT_USE_QTASSISTANTCLIENT          TRUE
  # QT_USE_QTHELP         TRUE
  # QT_USE_QTWEBKIT         TRUE
  # QT_USE_QTXMLPATTERNS          TRUE
  # QT_USE_PHONON         TRUE
#)

# This sets the windows build that will need the special winmain@16 call. Qt provides
#  this for us in the qtmain.lib file. Using this cmake code will ensure we have it
#  linked into our build. Not needed on Unix/OS X/Linux which is why we have the
#  IF(WIN32) conditional.
IF(WIN32) # and mingw/gcc
  SET(QT_USE_QTMAIN TRUE)
ENDIF(WIN32)

#add_subdirectory(./src)





# with SET() command you can change variables or define new ones
# here we define SIMPLETASKMANAGER_SRCS variable that contains a list of all .cpp files
# note that we don't need \ at the end of line
SET( SIMPLETASKMANAGER_SRCS
  ./src/main.cpp
  ./src/GUI/MainWindow.cpp
  ./src/Task/Task.cpp
  ./src/TaskDialog/TaskDialog.cpp
  ./src/GUI/TaskListModel.cpp
  ./src/GUI/SimpleTimerDialog.cpp
  ./src/GUI/TaskListView.cpp
  ./src/GUI/TrayIcon.cpp
  ./src/Timer/Timer.cpp

)


# another list, this time it includes all header files that should be treated with moc
SET( SIMPLETASKMANAGER_MOC_HDRS
 ./src/GUI/MainWindow.h
  ./src/GUI/TaskListView.h
  ./src/TaskDialog/TaskDialog.h
  ./src/GUI/TaskListModel.h
  ./src/GUI/SimpleTimerDialog.h
  ./src/GUI/TrayIcon.h
  ./src/Timer/Timer.h
  ./src/GUI/TaskListModel.h)

# and finally this will run moc:
QT4_WRAP_CPP( SIMPLETASKMANAGER_MOC_SRCS ${SIMPLETASKMANAGER_MOC_HDRS} )

# headers that are not treated with moc
SET( SIMPLETASKMANAGER_HDRS
  ./src/Task/Task.h
  ./src/lib/Singleton.h
)


# some .ui files
SET( SIMPLETASKMANAGER_UIS
    ./src/GUI/MainWindow.ui
    ./src/TaskDialog/TaskDialog.ui
    ./src/GUI/SimpleTimerDialog.ui
)

# and finally an resource file
SET( SIMPLETASKMANAGER_RCS
  ./src/rsc/resources.qrc
)



# this will run uic on .ui files:
QT4_WRAP_UI( SIMPLETASKMANAGER_UI_HDRS ${SIMPLETASKMANAGER_UIS} )

# this command will generate rules that will run rcc on all files from SIMPLETASKMANAGER_RCS
# in result SIMPLETASKMANAGER_RC_SRCS variable will contain paths to files produced by rcc
QT4_ADD_RESOURCES( SIMPLETASKMANAGER_RC_SRCS ${SIMPLETASKMANAGER_RCS} )


# we need this to be able to include headers produced by uic in our code
# (CMAKE_BINARY_DIR holds a path to the build directory, while INCLUDE_DIRECTORIES() works just like INCLUDEPATH from qmake)
INCLUDE_DIRECTORIES( ${CMAKE_BINARY_DIR} )
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})


# here we instruct CMake to build SIMPLETASKMANAGER executable from all of the source files
# WIN32 as second param creates a WinMain instead of a main function. Has no effect on non Win platforms
ADD_EXECUTABLE( SimpleTaskManager WIN32 ${SIMPLETASKMANAGER_SRCS} ${SIMPLETASKMANAGER_HDRS} ${SIMPLETASKMANAGER_MOC_SRCS} ${SIMPLETASKMANAGER_RC_SRCS} ${SIMPLETASKMANAGER_UI_HDRS} )


# last thing we have to do is to tell CMake what libraries our executable needs,
# luckily FIND_PACKAGE prepared QT_LIBRARIES variable for us:
TARGET_LINK_LIBRARIES( SimpleTaskManager ${QT_LIBRARIES})


INSTALL_TARGETS( /bin SimpleTaskManager )





 # IF(${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION} GREATER 2.4)
    # SET(CMAKE_INSTALL_DESTINATION_ARGS
      # BUNDLE DESTINATION "${CMAKE_BUNDLE_LOCATION}")
  # ENDIF(${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION} GREATER 2.4)
 # if qt is not static and we are on windows then skip the install
  #I don't want to distribute qt dlls
  # IF(CMAKE_PACKAGE_QTGUI)
    # INSTALL(TARGETS cmake-gui RUNTIME DESTINATION bin
    # ${CMAKE_INSTALL_DESTINATION_ARGS})
  # ENDIF(CMAKE_PACKAGE_QTGUI)

  # IF(UNIX)
 #   install a desktop file so CMake appears in the application start menu
 #   with an icon
    # INSTALL(FILES CMake.desktop DESTINATION share/applications )
    # INSTALL(FILES CMakeSetup.png DESTINATION share/pixmaps )
    # INSTALL(FILES cmakecache.xml DESTINATION share/mime/packages )
  # ENDIF(UNIX)

  # IF(APPLE)
    # SET(CMAKE_POSTFLIGHT_SCRIPT
      # "${CMake_BINARY_DIR}/Source/QtDialog/postflight.sh")
    # SET(CMAKE_POSTUPGRADE_SCRIPT
      # "${CMake_BINARY_DIR}/Source/QtDialog/postupgrade.sh")
    # configure_file("${CMake_SOURCE_DIR}/Source/QtDialog/postflight.sh.in"
      # "${CMake_BINARY_DIR}/Source/QtDialog/postflight.sh")
    # configure_file("${CMake_SOURCE_DIR}/Source/QtDialog/postupgrade.sh.in"
      # "${CMake_BINARY_DIR}/Source/QtDialog/postupgrade.sh")
    # INSTALL(CODE "set(input_file
       # \"\$ENV{DESTDIR}\${CMAKE_INSTALL_PREFIX}/MacOS/cmake-gui\")")
    # INSTALL(SCRIPT "${CMake_SOURCE_DIR}/Source/QtDialog/CMakeIngestOSXBundleLibraries.cmake")
  # ENDIF(APPLE)
  # CONFIGURE_FILE("${QtDialog_SOURCE_DIR}/QtDialogCPack.cmake.in"
    # "${QtDialog_BINARY_DIR}/QtDialogCPack.cmake" @ONLY)
ENDIF(NOT QT4_FOUND)



add_subdirectory(./doc EXCLUDE_FROM_ALL)

