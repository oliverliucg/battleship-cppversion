
include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

target_sources(battleship_cppversion
        PRIVATE
        CoodinateTest.cpp
        )

#target_include_directories(battleship_cppversion PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(battleship_cppversion gtest_main)
add_test(NAME battleship_cppversion_test COMMAND battleship_cppversion)