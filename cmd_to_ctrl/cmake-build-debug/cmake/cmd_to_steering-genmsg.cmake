# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "cmd_to_steering: 1 messages, 1 services")

set(MSG_I_FLAGS "-Icmd_to_steering:/home/vr-lab/catkin_ws/src/cmd_to_ctrl/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(cmd_to_steering_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/vr-lab/catkin_ws/src/cmd_to_ctrl/srv/AddTwoInts.srv" NAME_WE)
add_custom_target(_cmd_to_steering_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "cmd_to_steering" "/home/vr-lab/catkin_ws/src/cmd_to_ctrl/srv/AddTwoInts.srv" ""
)

get_filename_component(_filename "/home/vr-lab/catkin_ws/src/cmd_to_ctrl/msg/Num.msg" NAME_WE)
add_custom_target(_cmd_to_steering_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "cmd_to_steering" "/home/vr-lab/catkin_ws/src/cmd_to_ctrl/msg/Num.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(cmd_to_steering
  "/home/vr-lab/catkin_ws/src/cmd_to_ctrl/msg/Num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cmd_to_steering
)

### Generating Services
_generate_srv_cpp(cmd_to_steering
  "/home/vr-lab/catkin_ws/src/cmd_to_ctrl/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cmd_to_steering
)

### Generating Module File
_generate_module_cpp(cmd_to_steering
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cmd_to_steering
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(cmd_to_steering_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(cmd_to_steering_generate_messages cmd_to_steering_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/vr-lab/catkin_ws/src/cmd_to_ctrl/srv/AddTwoInts.srv" NAME_WE)
add_dependencies(cmd_to_steering_generate_messages_cpp _cmd_to_steering_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vr-lab/catkin_ws/src/cmd_to_ctrl/msg/Num.msg" NAME_WE)
add_dependencies(cmd_to_steering_generate_messages_cpp _cmd_to_steering_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(cmd_to_steering_gencpp)
add_dependencies(cmd_to_steering_gencpp cmd_to_steering_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS cmd_to_steering_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(cmd_to_steering
  "/home/vr-lab/catkin_ws/src/cmd_to_ctrl/msg/Num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/cmd_to_steering
)

### Generating Services
_generate_srv_eus(cmd_to_steering
  "/home/vr-lab/catkin_ws/src/cmd_to_ctrl/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/cmd_to_steering
)

### Generating Module File
_generate_module_eus(cmd_to_steering
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/cmd_to_steering
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(cmd_to_steering_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(cmd_to_steering_generate_messages cmd_to_steering_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/vr-lab/catkin_ws/src/cmd_to_ctrl/srv/AddTwoInts.srv" NAME_WE)
add_dependencies(cmd_to_steering_generate_messages_eus _cmd_to_steering_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vr-lab/catkin_ws/src/cmd_to_ctrl/msg/Num.msg" NAME_WE)
add_dependencies(cmd_to_steering_generate_messages_eus _cmd_to_steering_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(cmd_to_steering_geneus)
add_dependencies(cmd_to_steering_geneus cmd_to_steering_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS cmd_to_steering_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(cmd_to_steering
  "/home/vr-lab/catkin_ws/src/cmd_to_ctrl/msg/Num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/cmd_to_steering
)

### Generating Services
_generate_srv_lisp(cmd_to_steering
  "/home/vr-lab/catkin_ws/src/cmd_to_ctrl/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/cmd_to_steering
)

### Generating Module File
_generate_module_lisp(cmd_to_steering
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/cmd_to_steering
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(cmd_to_steering_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(cmd_to_steering_generate_messages cmd_to_steering_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/vr-lab/catkin_ws/src/cmd_to_ctrl/srv/AddTwoInts.srv" NAME_WE)
add_dependencies(cmd_to_steering_generate_messages_lisp _cmd_to_steering_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vr-lab/catkin_ws/src/cmd_to_ctrl/msg/Num.msg" NAME_WE)
add_dependencies(cmd_to_steering_generate_messages_lisp _cmd_to_steering_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(cmd_to_steering_genlisp)
add_dependencies(cmd_to_steering_genlisp cmd_to_steering_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS cmd_to_steering_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(cmd_to_steering
  "/home/vr-lab/catkin_ws/src/cmd_to_ctrl/msg/Num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/cmd_to_steering
)

### Generating Services
_generate_srv_nodejs(cmd_to_steering
  "/home/vr-lab/catkin_ws/src/cmd_to_ctrl/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/cmd_to_steering
)

### Generating Module File
_generate_module_nodejs(cmd_to_steering
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/cmd_to_steering
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(cmd_to_steering_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(cmd_to_steering_generate_messages cmd_to_steering_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/vr-lab/catkin_ws/src/cmd_to_ctrl/srv/AddTwoInts.srv" NAME_WE)
add_dependencies(cmd_to_steering_generate_messages_nodejs _cmd_to_steering_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vr-lab/catkin_ws/src/cmd_to_ctrl/msg/Num.msg" NAME_WE)
add_dependencies(cmd_to_steering_generate_messages_nodejs _cmd_to_steering_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(cmd_to_steering_gennodejs)
add_dependencies(cmd_to_steering_gennodejs cmd_to_steering_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS cmd_to_steering_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(cmd_to_steering
  "/home/vr-lab/catkin_ws/src/cmd_to_ctrl/msg/Num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cmd_to_steering
)

### Generating Services
_generate_srv_py(cmd_to_steering
  "/home/vr-lab/catkin_ws/src/cmd_to_ctrl/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cmd_to_steering
)

### Generating Module File
_generate_module_py(cmd_to_steering
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cmd_to_steering
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(cmd_to_steering_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(cmd_to_steering_generate_messages cmd_to_steering_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/vr-lab/catkin_ws/src/cmd_to_ctrl/srv/AddTwoInts.srv" NAME_WE)
add_dependencies(cmd_to_steering_generate_messages_py _cmd_to_steering_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vr-lab/catkin_ws/src/cmd_to_ctrl/msg/Num.msg" NAME_WE)
add_dependencies(cmd_to_steering_generate_messages_py _cmd_to_steering_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(cmd_to_steering_genpy)
add_dependencies(cmd_to_steering_genpy cmd_to_steering_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS cmd_to_steering_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cmd_to_steering)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cmd_to_steering
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(cmd_to_steering_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/cmd_to_steering)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/cmd_to_steering
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(cmd_to_steering_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/cmd_to_steering)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/cmd_to_steering
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(cmd_to_steering_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/cmd_to_steering)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/cmd_to_steering
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(cmd_to_steering_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cmd_to_steering)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cmd_to_steering\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cmd_to_steering
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(cmd_to_steering_generate_messages_py std_msgs_generate_messages_py)
endif()
