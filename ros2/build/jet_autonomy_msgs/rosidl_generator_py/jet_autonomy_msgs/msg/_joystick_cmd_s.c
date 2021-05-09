// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from jet_autonomy_msgs:msg/JoystickCmd.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_generator_c/visibility_control.h"
#include "jet_autonomy_msgs/msg/joystick_cmd__struct.h"
#include "jet_autonomy_msgs/msg/joystick_cmd__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool jet_autonomy_msgs__msg__joystick_cmd__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[48];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp(
        "jet_autonomy_msgs.msg._joystick_cmd.JoystickCmd",
        full_classname_dest, 47) == 0);
  }
  jet_autonomy_msgs__msg__JoystickCmd * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // manual_drive_enabled
    PyObject * field = PyObject_GetAttrString(_pymsg, "manual_drive_enabled");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->manual_drive_enabled = (Py_True == field);
    Py_DECREF(field);
  }
  {  // auto_drive_enabled
    PyObject * field = PyObject_GetAttrString(_pymsg, "auto_drive_enabled");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->auto_drive_enabled = (Py_True == field);
    Py_DECREF(field);
  }
  {  // steering
    PyObject * field = PyObject_GetAttrString(_pymsg, "steering");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->steering = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // throttle
    PyObject * field = PyObject_GetAttrString(_pymsg, "throttle");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->throttle = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * jet_autonomy_msgs__msg__joystick_cmd__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of JoystickCmd */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("jet_autonomy_msgs.msg._joystick_cmd");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "JoystickCmd");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  jet_autonomy_msgs__msg__JoystickCmd * ros_message = (jet_autonomy_msgs__msg__JoystickCmd *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // manual_drive_enabled
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->manual_drive_enabled ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "manual_drive_enabled", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // auto_drive_enabled
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->auto_drive_enabled ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "auto_drive_enabled", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // steering
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->steering);
    {
      int rc = PyObject_SetAttrString(_pymessage, "steering", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // throttle
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->throttle);
    {
      int rc = PyObject_SetAttrString(_pymessage, "throttle", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}