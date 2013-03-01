AC_INIT([pifacertu], [1.0.0], [jadamcrain@automatak.com])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([./m4])
AC_COPYRIGHT([(C) 2013 Automatak, LLC. All right reserved.])
AM_INIT_AUTOMAKE([subdir-objects])

AC_PREFIX_DEFAULT([/usr]) #works best for Ubuntu

AC_LANG([C++]) # tell autoconf that we're using C++
AX_CXX_COMPILE_STDCXX_11([ext]) #require support for C++11

AX_BOOST_BASE([1.45.0]  ,, [AC_MSG_ERROR(You must install boost >= 1.45.0)])
AX_BOOST_SYSTEM

AC_CHECK_LIB(pthread, pthread_create)

LT_INIT #initialize libtools

AC_CONFIG_FILES([Makefile])
AC_OUTPUT #actually output the configuration

