cmake_minimum_required(VERSION 2.8.12)

project (FactoryMethod)

set(SOURCES
    src/FactoryMethod_example.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

