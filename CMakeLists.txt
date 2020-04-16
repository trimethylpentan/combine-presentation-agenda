cmake_minimum_required (VERSION 3.1)
set(CMAKE_CXX_STANDARD 17)

project (combine-presentation-agenda)

add_executable(combine-presentation-agenda combine-presentation-agenda.cpp ImageMerger.cpp)

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
