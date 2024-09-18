cmake_minimum_required(VERSION 3.26)
project(QcloudObj)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "D:/App/Qt/6.2.4/mingw_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Sql
        #        导入网络模块
        Network
        REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/LoginDialog)
include_directories(${CMAKE_SOURCE_DIR}/mainWidget)
include_directories(${CMAKE_SOURCE_DIR}/resource)
include_directories(${CMAKE_SOURCE_DIR}/LoginDialog/Header)
include_directories(${CMAKE_SOURCE_DIR}/LoginDialog/source)
include_directories(${CMAKE_SOURCE_DIR}/mainWidget/header)
include_directories(${CMAKE_SOURCE_DIR}/mainWidget/source)

FILE(GLOB_RECURSE RC_FILES ${CMAKE_SOURCE_DIR}/resource/*.rc)
FILE(GLOB_RECURSE QRC_FILES ${CMAKE_SOURCE_DIR}/resource/*.qrc)

add_executable(QcloudObj main.cpp

        LoginDialog/Source/logindialog.cpp
        LoginDialog/logindialog.h
        LoginDialog/Source/logindialog.ui
        LoginDialog/Source/titlewidget.cpp
        LoginDialog/Header/titlewidget.h
        LoginDialog/Source/titlewidget.ui
        resource/resources.qrc
        utils/source/movablewidget.cpp
        utils/header/movablewidget.h
        utils/source/DBUtils.cpp
        utils/header/DBUtils.h
        mainWidget/source/mainwindow.cpp
        mainWidget/mainwindow.h
        mainWidget/source/mainwindow.ui
        utils/source/QHttpRequest.cpp
        utils/header/QHttpRequest.h
        utils/source/Common.cpp
        utils/header/Common.h
        utils/source/des.c
        LoginDialog/Source/LoginUserInfo.cpp
        LoginDialog/Header/LoginUserInfo.h
        mainWidget/source/topbtngroup.cpp
        mainWidget/header/topbtngroup.h
        utils/utils.h
        mainWidget/source/myfilewidget.cpp
        mainWidget/header/myfilewidget.h
        mainWidget/source/myfilewidget.ui
        utils/source/FileInfo.cpp
        utils/header/FileInfo.h
        mainWidget/header/DownloadTask.cpp
        mainWidget/header/DownloadTask.h
        mainWidget/source/fileinfodialog.cpp
        mainWidget/header/fileinfodialog.h
        mainWidget/source/fileinfodialog.ui
)
target_link_libraries(QcloudObj
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt6::Sql
        Qt6::Network
)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
