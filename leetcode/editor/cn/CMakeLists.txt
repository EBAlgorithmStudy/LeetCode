aux_source_directory(./ SOURCE_FILE)

foreach (var ${SOURCE_FILE})
    string(REGEX REPLACE ".*/" "" var ${var})
    string(REGEX REPLACE ".cpp" "" tgt ${var})

    add_executable(${tgt} ${var})
endforeach (var)