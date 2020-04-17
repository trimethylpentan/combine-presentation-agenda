cmake_minimum_required (VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER /usr/bin/g++-8)

project(combine-presentation-agenda)

find_package(OpenCV REQUIRED)
add_executable(combine-presentation-agenda combine-presentation-agenda.cpp src/ImageMerger.cpp)
target_include_directories(combine-presentation-agenda PRIVATE {CMAKE_CURRENT_SOURCE_DIR}/src ${OpenCV_INCLUDE_DIRS})
target_link_libraries(combine-presentation-agenda ${OpenCV_LIBS} stdc++)

file(GLOB meta_files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "files/*.*")

foreach(meta_file ${meta_files})
	get_filename_component(output_filename ${meta_file} NAME)
	configure_file(${meta_file} ${CMAKE_CURRENT_BINARY_DIR}/${output_filename} COPYONLY)
endforeach(meta_file ${meta_files})

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/img)
file(GLOB img_files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "files/img/*.*")

foreach(img_file ${img_files})
	get_filename_component(output_img_filename ${img_file} NAME)
	configure_file(${img_file} ${CMAKE_CURRENT_BINARY_DIR}/img/${output_img_filename} COPYONLY)
endforeach(img_file ${img_files})
