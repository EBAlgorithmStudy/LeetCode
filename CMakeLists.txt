cmake_minimum_required(VERSION 2.8)
project(eb_leetcode_study)

add_subdirectory(leetcode/editor/cn)
#
#aux_source_directory(./ SOURCE_FILE)
#
#foreach (var ${SOURCE_FILE})
#    string(REGEX REPLACE ".*/" "" var ${var})
#    string(REGEX REPLACE ".cpp" "" tgt ${var})
#
#    add_executable(${tgt} ${var})
#endforeach (var)