cmake_minimum_required(VERSION 3.19)
project(weather_app)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "/Users/andreibuiciuc/Qt/5.12.11/clang_64/lib/cmake/Qt5")
set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

include_directories(tools)

# Add curl
set(CURL_INCLUDE_DIR "/Library/Developer/CommandLineTools/SDKs/MacOSX11.1.sdk/usr/include/curl")

# Add json
set(JSON_DIR "/Users/andreibuiciuc/json-develop/single_include/nlohmann")

include_directories(${CURL_INCLUDE_DIRECTORIES}, ${JSON_DIR})


add_executable(weather_app
        tools/Protocol.cpp
        tools/Protocol.h
        main.cpp
        gui/MainWindow.cpp
        gui/MainWindow.h
        gui/WeatherWindow.cpp
        gui/WeatherWindow.h gui/ChartWindow.cpp gui/ChartWindow.h tools/Validator.cpp tools/Validator.h tools/Service.cpp tools/Service.h domain/Weather.cpp domain/Weather.h)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)

target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
target_link_libraries(weather_app curl)
