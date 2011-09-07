project(battery)

add_executable(battery battery.c)

install(TARGETS battery RUNTIME DESTINATION bin)