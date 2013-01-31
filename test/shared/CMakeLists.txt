file(GLOB FILES *.hpp *.cpp)

set(TARGET test_shared)
add_executable(${TARGET} ${FILES})

acmake_boost_support(${TARGET} SHARED COPY_DLL COMPONENTS unit_test_framework)

add_test(
    NAME ${TARGET}
    COMMAND $<TARGET_FILE:${TARGET}>
    )
