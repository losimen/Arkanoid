list(APPEND myApp_SOURCES ${CMAKE_CURRENT_LIST_DIR}/Block.cpp
                          ${CMAKE_CURRENT_LIST_DIR}/Block.h
                          ${CMAKE_CURRENT_LIST_DIR}/IObject.h
                          ${CMAKE_CURRENT_LIST_DIR}/IObject.cpp
                          ${CMAKE_CURRENT_LIST_DIR}/Platform.h
                          ${CMAKE_CURRENT_LIST_DIR}/Platform.cpp
                          ${CMAKE_CURRENT_LIST_DIR}/Mouse.h
                          ${CMAKE_CURRENT_LIST_DIR}/Mouse.cpp
                          ${CMAKE_CURRENT_LIST_DIR}/Ball.h
                          ${CMAKE_CURRENT_LIST_DIR}/Ball.cpp
                          ${CMAKE_CURRENT_LIST_DIR}/ScoreTab.h
                          ${CMAKE_CURRENT_LIST_DIR}/ScoreTab.cpp
        )

list(APPEND myApp_INCLUDES ${CMAKE_CURRENT_LIST_DIR})
