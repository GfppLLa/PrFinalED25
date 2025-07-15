cmake_minimum_required(VERSION 3.15)
project (PrFinalED25 C)

#definicao padrao build

#habilitar warnings

#adicionar pastas de modulos

#adicionar executavel

add_executable(${CMAKE_CURRENT_SOURCE_DIR}/src/main.c)

#local do headers
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/src/modules
	${CMAKE_CURRENT_SOURCE_DIR}/src
	${CMAKE_CURRENT_SOURCE_DIR}/libs
)

