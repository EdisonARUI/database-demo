set(DEMO_DB_SRC
        main.cpp
        )

add_executable(bydb
        ${DEMO_DB_SRC})

target_link_libraries(bydb
        ${CMAKE_SOURCE_DIR}/sql-parser/lib/libsqlparser.so)