# copyright (c) 2013 Automatak, LLC

ACLOCAL_AMFLAGS = -I ./m4

CORE_BOOST_LIBS = $(BOOST_SYSTEM_LIB)

AM_CXXFLAGS = -lopendnp3 -lpiface-1.0
AM_LDFLAGS  = $(BOOST_LDFLAGS)

bin_PROGRAMS = pifacertu

pifacertu_LDFLAGS = $(BOOST_LDFLAGS)
pifacertu_LDADD = $(CORE_BOOST_LIBS)
pifacertu_SOURCES = PifaceRTU.cpp
